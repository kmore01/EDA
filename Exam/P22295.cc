// BACKTRACKING

#include <iostream>
#include <vector>

using namespace std;

const int DI[4] = {1, 0, -1, 0};
const int DJ[4] = {0, 1, 0, -1};

void llegir(vector<vector<char> > &t) {
    int n = t.size();
    int m = t[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
        }
    }
}

bool isOk(int i, int j, int n, int m) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void backtracking(const vector<vector<char> > &t, vector<vector<bool> > &u,
                  string &sol, int fa, int ca, int ff, int cf) {
    // Cas base
    if (fa == ff and ca == cf) {
        cout << sol << endl;
    }
    // Cas general
    else {
        int n = t.size();
        int m = t[0].size();
        for (int k = 0; k < 4; ++k) {
            int nf = fa + DI[k];
            int nc = ca + DJ[k];
            if (isOk(nf, nc, n, m) and not u[nf][nc]) {
                u[nf][nc] = true;
                sol.push_back(t[nf][nc]);
                backtracking(t, u, sol, nf, nc, ff, cf);
                u[nf][nc] = false;
                sol.pop_back();
            }
        }
    }
}

int main() {
    int n, m, fi, ci, ff, cf;
    cin >> n >> m;
    vector<vector<char> > terra(n, vector<char>(m));
    llegir(terra);
    cin >> fi >> ci >> ff >> cf;
    vector<vector<bool> > used(n, vector<bool>(m, false));
    used[fi][ci] = true;
    string sol;
    sol.push_back(terra[fi][ci]);
    backtracking(terra, used, sol, fi, ci, ff, cf);
}