#include <iostream>
#include <vector>

using namespace std;

void zeros_i_uns(vector<int> &v, int idx, int o, int ones) {
    // Cas base
    if (idx == int(v.size())) {
        bool space = false;
        for (int i = 0; i < int(v.size()); ++i) {
            if (space) cout << ' ';
            space = true;
            cout << v[i];
        }
        cout << endl;
    }
    // Cas recursiu
    else {
        // (idx - ones) es el nombre de 0 actuals de la solucio v
        if ((idx - ones) < int(v.size()) - o) {
            v[idx] = 0;
            zeros_i_uns(v, idx + 1, o, ones);
        }
        // ones es el nombre de 1 actuals de la solucio v
        if (ones < o) {
            v[idx] = 1;
            zeros_i_uns(v, idx + 1, o, ones + 1);
        }
    }
}

int main () {
    int n, o;
    cin >> n >> o; // n > 0, 0 <= o <= n
    vector<int> sol(n);
    int idx = 0, ones = 0;
    zeros_i_uns(sol, idx, o, ones);
}