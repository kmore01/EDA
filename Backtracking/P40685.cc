#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void llegir(vector<int> &v) {
    for (int i = 0; i < int(v.size()); ++i) {
        cin >> v[i];
    }
}

void backtracking(vector<int> &v, int idx, const vector<int> &n, int s, int sumaActual) {
    // Cas base
    if (sumaActual == s) {
        cout << '{';
        bool coma = false;
        for (int i = 0; i < int(v.size()); ++i) {
            if (coma) cout << ',';
            cout << v[i];
            coma = true;
        }
        cout << '}' << endl;
    }   
    // Cas recursiu
    for (int i = idx; i < int(n.size()); ++i) {
        v.push_back(n[i]);
        backtracking(v, i + 1, n, s, sumaActual + n[i]);
        v.pop_back();
    }
}

int main () {
    int s, n; // n > 0
    cin >> s >> n;
    vector<int> num(n);
    llegir(num);
    sort(num.begin(), num.end()); // Mes eficient
    vector<int> solucio;
    backtracking(solucio, 0, num, s, 0);
}