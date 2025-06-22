// Programa que devuelve el k elemento menor de una sequencia de vectores

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE; // vector<vector<int> > VVE;

int k_esim(int k, const VVE& V) {
    map<int, int> valor_indice;
    for (int i = 0; i < V.size(); i++) {
	    if (not V[i].empty()) valor_indice[V[i][0]] = i;
    }

    pair <int, int> ans;
	VE it(V.size(), 1);
	for (; k > 0; --k) {
		ans = *valor_indice.begin(); // valor menor de los vectores
		if (V[ans.second].size() > it[ans.second]) //
        valor_indice[ V[ans.second][it[ans.second]++] ] = ans.second;

		valor_indice.erase(valor_indice.begin()); // eliminamos valor menor ya visitado
	}
	return ans.first;
}

/*
int main() {
    int x, y, k;
    cin >> x >> y;
    VVE v(x, VE(y));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) cin >> v[i][j];
    }
    cin >> k;
    cout << k_esim(k, v) << endl;
}
*/