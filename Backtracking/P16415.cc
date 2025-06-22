#include <iostream>
#include <vector>

using namespace std;

/*
    mc[j] es true si hi ha una reina a la columna j
    md1[i + j] es true si hi ha una reina a la diagonal(1) j
    md2[i - j + n - 1] es true si hi ha una reina a la diagonal(2) j
*/

int reines(vector<int> &v, int i, int n, vector<int> &mc, vector<int> &md1,
           vector<int> &md2) {
  // Cas base
  if (i == n) {  // Final del tauler
    return 1;
  }
  // Cas recursiu
  int res = 0;
  for (int j = 0; j < n; ++j) {
    // Si la reina no es atacada per ningu
    if (not mc[j] and not md1[i + j] and not md2[(i - j) + (n - 1)]) {
      v[i] = j;
      mc[j] = md1[i + j] = md2[(i - j) + (n - 1)] = true;
      res += reines(v, i + 1, n, mc, md1, md2);
      mc[j] = md1[i + j] = md2[(i - j) + (n - 1)] = false;
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;  // n > 0ç
  vector<int> t(n);
  vector<int> mc(n, false);           // Columnes
  vector<int> md1(2 * n - 1, false);  // Diagonal 1
  vector<int> md2(2 * n - 1, false);  // Diagonal 2
  cout << reines(t, 0, n, mc, md1, md2) << endl;
}