#include <iostream>
#include <vector>

using namespace std;

void zeros_i_uns(vector<int> &v, int idx, int n) {
    // Cas base
    if (idx == n) {
        bool space = false;
        for (int i = 0; i < n; ++i) {
            if (space) cout << ' ';
            space = true;
            cout << v[i];
        }
        cout << endl;
    }
    else {
        // Cas recursiu
        v[idx] = 0;
        zeros_i_uns(v, idx + 1, n);
        v[idx] = 1;
        zeros_i_uns(v, idx + 1, n);
    }
}

int main () {
    int n; // n > 0
    cin >> n;
    vector<int> sol(n);
    int idx = 0;
    zeros_i_uns(sol, idx, n);
}