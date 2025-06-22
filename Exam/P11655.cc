#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int llegir(vector<int> &v) {
    int suma = 0, size = int(v.size());
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
        suma += v[i];
    }
    return suma;
}

void imprimir(const vector<int> &v) {
    cout << '{';
    bool coma = false;
    int size = int(v.size());
    for (int i = 0; i < size; ++i) {
        if (coma) cout << ',';
        cout << v[i];
        coma = true;
    }
    cout << '}' << endl;
}

void backtracking(vector<int> &v, int idx, const vector<int> &n, int s,
                  int sumaActual, int sumaTotal) {
    // Cas base
    if (idx == n.size() and sumaActual == s) {
        imprimir(v);
    }
    if (sumaActual > s or sumaTotal + sumaActual < s or idx >= n.size()) return;
    // Cas recursiu
    int elem = n[idx];
    v.push_back(elem);
    backtracking(v, idx + 1, n, s, sumaActual + elem, sumaTotal - elem);
    v.pop_back();
    backtracking(v, idx + 1, n, s, sumaActual, sumaTotal - elem);
}

int main() {
    int s, n;  // n > 0
    cin >> s >> n;
    vector<int> num(n);
    int sumaTots = llegir(num);
    vector<int> solucio;
    backtracking(solucio, 0, num, s, 0, sumaTots);
}