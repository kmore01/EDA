#include <iostream>
#include <vector>

using namespace std;

bool multiple(const vector<int> &d, const vector<int> &s, int idx) {
    int num = 0;
    for (int k = 0; k < idx; ++k) {
        num = num * 10 + s[k];
        for (int i = 0; i < d.size(); ++i) {
            if ((num % d[i]) == 0) {  // Es multiple
                return true;
            }
        }
    }
    return false;
}

void backtracking2(int n, int m, const vector<int> &d, vector<int> &s,
                   int idx) {
    // Cas base
    if (idx == n) {
        for (int i = 0; i < n; ++i) cout << s[i];
        cout << endl;
        return;
    }
    // Cas general
    for (int i = 0; i < 10; ++i) {
        if (idx == 0 and i == 0) continue;
        s[idx] = i;
        // Dona igual que retornem
        if (not multiple(d, s, idx + 1)) {
            backtracking2(n, m, d, s, idx + 1);
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> divisors(m);
        for (int i = 0; i < m; ++i) {
            cin >> divisors[i];
        }
        vector<int> solucio(n);
        backtracking2(n, m, divisors, solucio, 0);
        cout << "----------" << endl;
    }
}