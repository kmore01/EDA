#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<unordered_set<int>> graf;

// Funcio que retorna la posicio de la especie al vector
int index(char e) {
    if (e >= 'A' and e <= 'Z') {
        return e - 'A';  // A, B, C...
    }
    else return e - 'a' + 26;  // a, b, c...
}

void llegirEspecies(vector<char> &v) {
    for (int i = 0; i < int(v.size()); ++i) {
        cin >> v[i];
    }
}

void llegirIncomp(graf &g, int m) {
    for (int i = 0; i < m; ++i) {
        char e1, e2;
        cin >> e1 >> e2;
        int indx1 = index(e1);
        int indx2 = index(e2);
        g[indx1].insert(indx2);
        g[indx2].insert(indx1);
    }
}

void backtracking(vector<char> &v, int idx, const graf &g, const vector<char> &e, vector<bool> &visit) {
    // Cas base
    if (idx == int(v.size())) {
        for (int i = 0; i < int(v.size()); ++i) {
            cout << v[i];
        }
        cout << endl;
    }

    // Cas recursiu
    else {
        for (int i = 0; i < int(v.size()); ++i) {
            int ind = index(e[i]);
            if (not visit[ind]) {
                if (idx > 0 and g[ind].count(index(v[idx - 1]))) {
                    continue;  // Pasar a la seguent iteracio
                }
                v[idx] = e[i];
                visit[ind] = true; // S'anira sobreescribint
                backtracking(v, idx + 1, g, e, visit);
                visit[ind] = false;
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n; // 1 <= n <= 52
    vector<char> especies(n); // Un espai per cada lletra del abecedari
    llegirEspecies(especies);
    cin >> m; 
    graf incompatibilitats(52);
    llegirIncomp(incompatibilitats, m);
    vector<char> solucio(n);
    vector<bool> visitats(52, false); // Un espai per cada lletra del abecedari
    int idx = 0;
    backtracking(solucio, idx, incompatibilitats, especies, visitats);
}