#include <iostream>
#include <vector>

using namespace std;

/*
    mc[j] es true si hi ha una reina a la columna j
    md1[i + j] es true si hi ha una reina a la diagonal(1) j
    md2[i - j + n - 1] es true si hi ha una reina a la diagonal(2) j
*/

void escriu(const vector<int> &t, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (t[i] == j)
                cout << 'Q';
            else
                cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}

void reines(vector<int> &v, int i, int n, vector<int> &mc, vector<int> &md1,
            vector<int> &md2) {
    // Cas base
    if (i == n) {  // Final del tauler
        escriu(v, n);
    }
    // Cas recursiu
    else {
        for (int j = 0; j < n; ++j) {
            // Si la reina no es atacada per ningu
            if (not mc[j] and not md1[i + j] and not md2[(i - j) + (n - 1)]) {
                v[i] = j;
                mc[j] = md1[i + j] = md2[(i - j) + (n - 1)] = true;
                reines(v, i + 1, n, mc, md1, md2);
                mc[j] = md1[i + j] = md2[(i - j) + (n - 1)] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;  // n > 0
    vector<int> t(n);
    vector<int> mc(n, false);           // Columnes
    vector<int> md1(2 * n - 1, false);  // Diagonal 1
    vector<int> md2(2 * n - 1, false);  // Diagonal 2
    reines(t, 0, n, mc, md1, md2);
}