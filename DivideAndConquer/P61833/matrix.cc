// Program that computes M^n % m using quick exponentiation

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > matrix;

// Function that computes the multiplication of two matrices
matrix mult(const matrix &ma, const matrix &mb) {
    matrix ans = {{0, 0}, {0, 0}};
    for (int i = 0; i < ma.size(); ++i) {
        for (int j = 0; j < ma[0].size(); ++j) {
            for (int k = 0; k < mb.size(); ++k) { 
                ans[i][j] += ma[i][k] * mb[k][j];
            }
        }
    }
    return ans;
}

// Function that computes ma^n % m
matrix pow(matrix &ma, int n, int m) {  
    // Base cases
    if (n == 0) {
        return matrix {{1, 0}, {0, 1}};
    } 
    else if (n == 1) {
        ma[0][0] %= m;
        ma[0][1] %= m;
        ma[1][0] %= m;
        ma[1][1] %= m;
        return ma;
    }
    // General case
    else {
        // n even --> M^n = M^(n / 2) * M^(n / 2)
        // n odd --> M^n = M^(n / 2) * M^(n / 2) * M
        matrix aux = pow(ma, n / 2, m); // M^(n / 2)
        aux = mult(aux, aux);  // M^(n / 2) * M^(n / 2)
        if (n % 2 != 0) aux = mult(aux, ma);
        aux[0][0] %= m;
        aux[0][1] %= m;
        aux[1][0] %= m;
        aux[1][1] %= m;
        return aux;
    }
}

// Function that prints a matrix
void imp(const matrix &m) {
    for (int i = 0; i < m.size(); ++i) {
        bool space = false;
        for (int j = 0; j < m[0].size(); ++j) {
            if (space) cout << ' ';
            cout << m[i][j];
            space = true;
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

int main () {
    matrix mat(2, vector<int>(2));
    while (cin >> mat[0][0] >> mat[0][1] >> mat[1][0] >> mat[1][1]) {
        int n, m; // 0 ≤ n ≤ 10^9, 2 ≤ m ≤ 1000 
        cin >> n >> m;
        mat = pow(mat, n, m);
        imp(mat);
    }
}