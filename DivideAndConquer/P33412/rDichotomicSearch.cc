// Program that tells if a double belongs a vector or not

#include <iostream>
#include <vector>

using namespace std;

// Function that returns if x is in v
// Precondition: the vector v is “almost sorted” in nondecreasing order, in the 
// sense that there may be at most a pair of indices i and j such that 
// 0 ≤ i < j < n and V[i] > V[j]
bool resistant_search(double x, const vector<double>& v) {
    if (v.size() == 0) return false; // Extreme case
    int i = 0;
    int j = int(v.size()) - 1;
    bool d = v[i] == x or v[j] == x; // This cases cannot be seen in the while
    while (i <= j and not d) {
        int k = ((i + j) / 2);
        if (v[k] == x or (k != 0 and v[k - 1] == x) 
            or (k != int(v.size()) - 1 and v[k + 1] == x)) d = true;
        else if (v[k] > x) j = k - 1;
        else i = k + 1;
    }
    return d;
}

/*
int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
*/