// BACKTRACKING

#include <iostream>
#include <vector>

using namespace std;

const int DI[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int DJ[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool dinsLimit(int n, int i, int j) {
    return 0 <= i and i < n and 0 <= j and j < n;
}

void escriu(const vector<vector<bool>> &t) {
    int n = t.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (t[i][j])
                cout << 'K';
            else
                cout << '.';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void reis(vector<vector<bool>> &t, int i, int j, int n, int r, int rCount) {
    // Cas base
    if (rCount == r) {
        escriu(t);
    }
    // Cas general
    else if (i < n) {
        for (int j2 = j; j2 < n; ++j2)  // Columnas
        {
            bool insertar = true;
            for (int k = 0; k < 8; ++k) {
                if (dinsLimit(n, i + DI[k], j2 + DJ[k])) {
                    if (t[i + DI[k]][j2 + DJ[k]]) {
                        insertar = false;
                        k = 9;
                    }
                }
            }
            if (insertar) {
                t[i][j2] = true;
                reis(t, i, j2 + 1, n, r, rCount + 1);
                t[i][j2] = false;
            }
        }
        reis(t, i + 1, 0, n, r, rCount);
    }
}

int main() {
    int n, r;  // n > 0, 0 <= r <= n^2
    cin >> n >> r;
    vector<vector<bool>> tauler(n, vector<bool>(n, false));
    reis(tauler, 0, 0, n, r, 0);
}