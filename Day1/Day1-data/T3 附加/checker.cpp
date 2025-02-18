#include <bits/stdc++.h>
using namespace std;

int T, n;
vector<int> a;
vector<int> sol;

void readSol(ifstream &fs) {
    sol.clear();
    string line;
    stringstream ss;
    getline(fs, line);
    ss.clear();
    ss << line;
    int t;
    while (ss >> t)
        sol.push_back(t);
}

stringstream message;
bool judge() {
    message.str("");
    if (sol.size() != n - 1) {
        message << "Invalid Length.";
        return false;
    }
    int id = 0;
    for (int op : sol) {
        ++id;
        if (op <= 0 || op + 1 > a.size()) {
            message << "[WA] Invalid Operation (" << id << "-th Oprand: " << op << ", Out of Range).";
            return false;
        }
        if (a[op] != a[op + 1]) {
            message << "[WA] Invalid Operation (" << id << "-th Oprand: " << op << ", " << a[op] << " and " << a[op + 1]
                    << " not Equal).";
            return false;
        }
        ++a[op], a.erase(a.begin() + op + 1);
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 4) return cerr << "Usage: " << argv[0] << " <input_file> <output_file> <answer_file>" << endl, 1;
    ifstream fin(argv[1]);
    if (!fin.is_open()) return cerr << "ERROR: Input File " << argv[1] << " Cannot Be Opened!" << endl, 1;
    ifstream fout(argv[2]);
    if (!fout.is_open()) return cerr << "ERROR: Output File " << argv[2] << " Cannot Be Opened!" << endl, 1;
    ifstream fans(argv[3]);
    if (!fans.is_open()) return cerr << "ERROR: Answer File " << argv[3] << " Cannot Be Opened!" << endl, 1;

    if (!(fin >> T)) return cerr << "ERROR : Input Not Found!" << endl, 1;
    bool task1 = true, task2 = true;
    for (int c = 1; c <= T; ++c) {
        fin >> n;
        a.resize(n + 1), a.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            fin >> a[i];
        cerr << "Case #" << c << ":";
        string ansStr, outStr;
        getline(fans, ansStr), getline(fout, outStr);
        // fix CR
        if (*ansStr.rbegin() == '\r') ansStr.pop_back();
        if (*outStr.rbegin() == '\r') outStr.pop_back();
        cerr << " Task #1: ";
        if (ansStr == outStr)
            cerr << "[OK],";
        else
            cerr << "[WA],", task1 = false;
        cerr << " Task #2: ";
        if (ansStr[0] == 's') {
            int ansN, outN;
            readSol(fans), ansN = sol[0];
            readSol(fout), outN = sol.size() ? sol[0] : -1;
            if (ansN == outN)
                cerr << "[OK].";
            else
                cerr << "[WA] Wrong Answer.", task2 = false;
        } else {
            readSol(fout);
            if (!judge())
                cerr << "[WA] " << message.str(), task2 = false;
            else
                cerr << "[OK].";
            readSol(fans);
        }
        cerr << endl;
    }
    cerr << "Overall: Task #1: " << (task1 ? "[OK]" : "[WA]") << ", Task #2: " << (task1 && task2 ? "[OK]" : "[WA]")
         << "." << endl;
    cout << "Your Score: ";
    if (task1 && task2)
        cout << 100 << endl;
    else if (task1)
        cout << 70 << endl;
    else
        cout << 0 << endl;
    return 0;
}
