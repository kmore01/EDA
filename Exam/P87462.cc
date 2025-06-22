// DFS

#include <iostream>
#include <vector>

using namespace std;

const int DI[4] = {1, 0, -1, 0};
const int DJ[4] = {0, 1, 0, -1};

void llegirTauler(vector<vector<char> > &t, int &fa, int &ca,
                  vector<pair<int, int> > &fan) {
    int f = t.size();
    int c = t[0].size();
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> t[i][j];
            if (t[i][j] == 'F') {  // Fantasmes
                fan.push_back({i, j});
            } else if (t[i][j] == 'P') {  // Pac-man
                fa = i;
                ca = j;
            }
        }
    }
}

bool fantasmesOk(int fa, int ca, const vector<pair<int, int> > &fan) {
    for (int i = 0; i < fan.size(); ++i) {
        if (abs(fa - fan[i].first) < 2 and abs(ca - fan[i].second) < 2) {
            return false;
        }
    }
    return true;
}

bool isOk(int fa, int ca, int f, int c, const vector<pair<int, int> > &fan) {
    return fa >= 0 and ca >= 0 and fa < f and ca < c;
}

bool dfs(const vector<vector<char> > &t, vector<vector<bool> > &v, int fa,
         int ca, const vector<pair<int, int> > &fan) {
    if (not v[fa][ca]) {
        v[fa][ca] = true;
        if (not fantasmesOk(fa, ca, fan)) return false;
        if (t[fa][ca] == 'B') return true;
        if (t[fa][ca] != 'X') {
            for (int k = 0; k < 4; ++k) {
                int fn = fa + DI[k];
                int cn = ca + DJ[k];
                if (isOk(fn, cn, t.size(), t[0].size(), fan)) {
                    if (dfs(t, v, fn, cn, fan)) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int f, c;  // 3 <= f <= 100, 3 <= c <= 100
    while (cin >> f >> c) {
        int filaActual, columnaActual;
        vector<vector<char> > tauler(f, vector<char>(c));
        vector<pair<int, int> > fantasmes;
        llegirTauler(tauler, filaActual, columnaActual, fantasmes);
        vector<vector<bool> > visited(f, vector<bool>(c, false));
        if (dfs(tauler, visited, filaActual, columnaActual, fantasmes)) {
            cout << "si" << endl;
        } else
            cout << "no" << endl;
    }
}