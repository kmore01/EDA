// Program that computes n^k % m using quick exponentiation

#include <iostream>

using namespace std;

// Funcion that computes n^k % m
int quickExponence(int n, int k, int m) {
    // Base case
    if (k == 0) return 1;
    // General case
    else {
        int aux = quickExponence(n, k / 2, m) % m;
        if (k % 2 == 0)
            return (aux * aux) % m;
        else {  // k % 2 != 0
            return ((aux * aux) % m) * n;
        }
    }
}

int main() {
    int n, k, m;  // 2 ≤ n ≤ 30000 and 2 ≤ m ≤ 30000
    while (cin >> n >> k >> m) {
        cout << quickExponence(n, k, m) % m << endl;
    }
}

/*
La entrada puede ser un int con un orden de magnitud muy elevado, por
eso hay que ir haciendo el modulo de cada numero en cada llamada recursiva. Hay
que hacer % m despues de cada operacion que hagamos
*/