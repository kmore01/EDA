// BACKTRACKING

#include <iostream>
#include <vector>

using namespace std;

const char C[4] = {'A', 'C', 'G', 'T'};

void backtracking(int n, string &sol) {
    // Cas base
    if (sol.length() == n) {
        cout << sol << endl;
    }
    // Cas general
    else {
        for (int k = 0; k < 4; ++k) {
            sol.push_back(C[k]);
            backtracking(n, sol);
            sol.pop_back();
        }
    }
}

int main() {
    int n;  // n > 0
    cin >> n;
    string sol = "";
    backtracking(n, sol);
}