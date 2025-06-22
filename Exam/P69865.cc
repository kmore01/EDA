// DFS

#include <iostream>
#include <vector>

using namespace std;

const int DIA[4] = {1, -1, -1, 1};
const int DJA[4] = {1, 1, -1, -1};

const int DIC[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int DJC[8] = {1, -1, -2, -2, -1, 1, 2, 2};

/*
Si un alfil esta a la posicio x, y, podra arribar a totes les caselles de la
forma que i, j que compleixin |i - x| = |j - y|
*/

void llegir(vector<vector<char>> &t, vector<pair<int, int>> &a,
            vector<pair<int, int>> &c) {
    int n = t.size();
    int m = t[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
            if (t[i][j] == 'B') {  // Alfil
                a.push_back({i, j});
            } else if (t[i][j] == 'K') {
                c.push_back({i, j});
            }
        }
    }
}

bool isOk(int fa, int ca, int f, int c) {
    return fa >= 0 and ca >= 0 and fa < f and ca < c;
}

bool notPerill(int i, int j, const vector<pair<int, int>> &a) {
    for (int l = 0; l < a.size(); ++l) {
        if (abs(i - a[i].first) != abs(j - a[i].second)) return false;
    }
    return true;
}

int dfs(vector<vector<char>> &t, vector<vector<bool>> &v, int i, int j) {
    int suma = 0;
    if (not v[i][j]) {
        v[i][j] = true;
        if (t[i][j] != 'T' and t[i][j] != 'B' and t[i][j] != '.' and
            t[i][j] != 'K') {  // Es una moneda
            suma += t[i][j] - '0';
            t[i][j] = '.';
        }
        if (t[i][j] != 'T') {
            for (int k = 0; k < 4; ++k) {
                int fa = i + DIA[k];
                int ca = j + DJA[k];
                if (isOk(fa, ca, t.size(), t[0].size())) {
                    suma += dfs(t, v, fa, ca);
                }
            }
        }
    }
    return suma;
}

int dfs2(const vector<vector<char>> &t, vector<vector<bool>> &v, int i, int j) {
    int suma = 0;
    if (not v[i][j]) {
        v[i][j] = true;
        if (t[i][j] != 'T' and t[i][j] != 'B' and t[i][j] != '.' and
            t[i][j] != 'K') {  // Es una moneda
            suma += t[i][j] - '0';
        }
        if (t[i][j] != 'T') {
            for (int k = 0; k < 8; ++k) {
                int fa = i + DIC[k];
                int ca = j + DJC[k];
                if (isOk(fa, ca, t.size(), t[0].size())) {
                    suma += dfs2(t, v, fa, ca);
                }
            }
        }
    }
    return suma;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> tauler(n, vector<char>(m));
        vector<pair<int, int>> alfils, caballs;
        llegir(tauler, alfils, caballs);
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        int suma = 0;
        // Alfils
        for (int i = 0; i < alfils.size(); ++i) {
            suma += dfs(tauler, visit, alfils[i].first, alfils[i].second);
        }
        // Caballs
        vector<vector<bool>> visit2(n, vector<bool>(m, false));
        for (int i = 0; i < caballs.size(); ++i) {
            suma += dfs2(tauler, visit2, caballs[i].first, caballs[i].second);
        }
        cout << suma << endl;
    }
}