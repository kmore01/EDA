// Program that returns the minimum index that complies x(i) + p = i
// (i starts at 1)

#include <iostream>
#include <vector>

using namespace std;

// Function that computes the minimum fixed point of p in s
int fixedPoints(const vector<int> &s, int p) {
    int i = 0;
    int j = int(s.size()) - 1;
    int d = -1; // If we don't find it, we return -1
    while (i <= j) {
        int k = (i + j) / 2;
        if (s[k] + p > k + 1) {
            j = k - 1;
        }
        else if (s[k] + p < k + 1) {
            i = k + 1;
        }
        else { // s[k] + a == k + 1
            d = k + 1;
            j = k - 1; // We need to see if there is another ocurrence before
        }
    }
    return d;
}

int main () {
    int n, count = 1;
    while (cin >> n) {
        vector<int> S(n);
        for (int i = 0; i < n; ++i) {
            cin >> S[i];
        }
        int a;
        cin >> a;
        cout << "Sequence #" << count << endl;
        for (int i = 0; i < a; ++i) {
            int p;
            cin >> p;
            int aux = fixedPoints(S, p);
            if (aux == -1) cout << "no fixed point for " << p << endl;
            else cout << "fixed point for " << p << ": " << aux << endl;
        }
        cout << endl;
        ++count;
    }
}