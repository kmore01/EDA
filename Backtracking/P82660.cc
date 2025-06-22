#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool found = false;

void llegir(vector<int> &v) {
    for (int i = 0; i < int(v.size()); ++i) {
        cin >> v[i];
    }
}

bool comp(int a, int b) {
	return a > b;
}

void imprimir(const vector<bool> &v, const vector<int> &n) {
    cout << '{';
    bool coma = false;
    for (int i = 0; i < int(v.size()); ++i) {
        if (v[i]) {
            if (coma) cout << ',';
            cout << n[i];
            coma = true;
        }
    }
    cout << '}' << endl;
}

void backtracking(int idx, const vector<int> &n, int s, int sumaActual,  vector<bool> &sol) {
    if (not found) {
        // Cas base
        if (sumaActual == s and idx == int(n.size())) {
            found = true;
            imprimir(sol, n);
            return;
        }   
        // Cas recursiu
        else if (idx < n.size()) {
			sol[idx] = true;
			backtracking(idx + 1, n, s, sumaActual + n[idx], sol);
			if (not found) {
				sol[idx] = false;
				backtracking(idx + 1, n, s, sumaActual, sol);
			}
		}
    }
}

int main () {
    int s, n; // n > 0
    cin >> s >> n;
    vector<int> num(n);
    llegir(num);
    sort(num.begin(), num.end(), comp); // Hint de l'enunciat
    vector<bool> sol(n, false);
    backtracking(0, num, s, 0, sol);
    if (not found) cout << "no solution" << endl;
}