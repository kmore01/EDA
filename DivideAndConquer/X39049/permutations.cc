// Program that computes permutation^k

#include <iostream>
#include <vector>

using namespace std;

// Function that computes the multiplication of two permutations
vector<int> permutationMult(const vector<int> &p1, const vector<int> &p2) {
    vector<int> aux(p1.size());
    for (int i = 0; i < p1.size(); ++i) {
        aux[i] = p1[p2[i]];
    }
    return aux;
}

// Function that computes p^k (p being a permutation) using quick exponentiation
vector<int> quickExponence(const vector<int> &p, int k) {
    // Base case
    if (k == 0) {
        vector<int> aux(p.size());
        for (int i = 0; i < p.size(); ++i) {
            aux[i] = i;
        }
        return aux;
    }
    // General case
    else {
        vector<int> aux = quickExponence(p, k / 2);
        if (k % 2 == 0) return permutationMult(aux, aux);
        else { // k % 2 != 0
            vector<int> pp = permutationMult(aux, aux);
            return permutationMult(pp, p);
        }
    }
}

// Function that prints a vector
void print(const vector<int> &a) {
    bool space = false;
    for (int i = 0; i < a.size(); ++i) {
        if (space) cout << ' ';
        space = true;
        cout << a[i];
    }
    cout << endl;
}

int main () {
    int n;
    while (cin >> n) {
        vector<int> permutation(n);
        for (int i = 0; i < n; ++i) {
            cin >> permutation[i];
        }
        int k;
        cin >> k;
        permutation = quickExponence(permutation, k);
        print(permutation);
    }
}