#include <iostream>
#include <vector>

using namespace std;

void escriu(const vector<int> &s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) cout << s[i];
    cout << endl;
}

void backtracking(int n, vector<int> &s, vector<int> &r, int idx, int parells) {
    // Cas base
    if (idx == s.size() and parells == 1) {
        escriu(s);
        return;
    } else if (parells > 1 or idx == s.size())
        return;
    // Cas general
    for (int i = 1; i <= 3; ++i) {
        s[idx] = i;
        r[i] += 1;
        if (r[i] <= n) {
            if (idx != 0 and s[idx - 1] == i) {
                backtracking(n, s, r, idx + 1, parells + 1);
            } else
                backtracking(n, s, r, idx + 1, parells);
        }
        r[i] -= 1;
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> solucio(3 * n);
        vector<int> roses(4, 0);
        int idx = 0;
        int parells = 0;
        backtracking(n, solucio, roses, 0, 0);
        cout << "**********" << endl;
    }
}