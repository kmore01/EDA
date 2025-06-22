#include <iostream>
#include <vector>

using namespace std;

void zeros_i_uns(vector<string> &v, int idx, const vector<string> &palabras, vector<bool> &visitat) {
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
    for (int i = 0; i < int(v.size()); ++i) {
        if (not visitat[i]) {
            v[idx] = palabras[i];
            visitat[i] = true;
            zeros_i_uns(v, idx + 1, palabras, visitat); 
            visitat[i] = false; 
        }
    }
}

int main () {
    int n;
    cin >> n; // n > 0
    vector<string> palabras(n);
    for (int i = 0; i < n; ++i) {
        cin >> palabras[i];
    }
    vector<bool> visitat(n, false);
    vector<string> sol(n);
    int idx = 0;
    zeros_i_uns(sol, idx, palabras, visitat);

}