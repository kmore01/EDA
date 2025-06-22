#include <iostream>
#include <vector>

using namespace std;

void zeros_i_uns(vector<int> &v, int idx, vector<bool> &vis) {
    // Cas base
    if (idx == int(v.size())) {
        bool coma = false;
        cout << '(';
        for (int i = 0; i < int(v.size()); ++i) {
            if (coma) cout << ',';
            coma = true;
            cout << v[i];
        }
        cout << ')' << endl;
    }
    // Cas recursiu
    for (int i = 1; i <= int(v.size()); ++i) {
        if (not vis[i - 1]) {
            v[idx] = i;
            vis[i - 1] = true;
            zeros_i_uns(v, idx + 1, vis);
            vis[i - 1] = false;
        }
    }
}

int main () {
    int n;
    cin >> n; // n > 0
    vector<int> sol(n);
    vector<bool> visitat(n, false);
    int idx = 0;
    zeros_i_uns(sol, idx, visitat);
}