#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > graf;

void escriure(const vector<int> &v) {
    bool espai = false;
    for (int i = 0; i < int(v.size()); ++i) {
        if (espai) cout << ' ';
        cout << v[i];
        espai = true;
    }
    cout << endl;
}

void llegir(graf &d, int m, vector<int> &tp) {
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        d[x].push_back(y); 
        // Y s'ha de fer abans que x
        ++tp[y];
    }
}

void tasques(vector<int> &v, int idx, graf &prec, vector<bool> &vis, vector<int> &ge) {
    // Cas base
    if (idx == int(v.size())) {
        escriure(v);
    }
    // Cas recursiu
    else {
        for (int i = 0; i < int(v.size()); ++i) {
            if (not vis[i] and ge[i] == 0) {
                v[idx] = i;
                vis[i] = true;
                // Eliminar aquesta tasca d'aquelles tasques que necesitaven 
                // que aquesta es fes primer
                for (int tasca : prec[i]) {
                    --ge[tasca];
                }
                tasques(v, idx + 1, prec, vis, ge); 
                vis[i] = false; 
                // Tornar a afegir aquesta tasca d'aquelles tasques que 
                //neesiten que aquesta es fes primer
                for (int tasca : prec[i]) {
                    ++ge[tasca];
                }
            }
        }
    }
}

int main () {
    int n, m; // n >= 1
    cin >> n >> m;
    graf precedencias(n);
    vector<int> tasques_a_fer_prev(n);
    llegir(precedencias, m, tasques_a_fer_prev);
    vector<int> sol(n);
    vector<bool> visitats(n, false);
    tasques(sol, 0, precedencias, visitats, tasques_a_fer_prev);
}