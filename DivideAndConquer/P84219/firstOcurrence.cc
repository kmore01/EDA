// Program that searches an element x in a vector using the dicotomic search

#include <iostream>
#include <vector>

using namespace std;

// Function that search for the first occurrence of an element in a vector
// Precondition: The vector v is sorted in nondecreasing order
int first_occurrence(double x, const vector<double>& v) {
    int i = 0;
    int j = int(v.size()) - 1;
    int d = -1; // If we don't find x in v, we return -1
    while (i <= j) {
        int k = (i + j) / 2;
        if (v[k] > x) {
            j = k - 1;
        }
        else if (v[k] < x) {
            i = k + 1;
        }
        else { // v[k] == x
            d = k;
            j = k - 1; // We need to see if there is another ocurrence
        }
    }
    return d;
}

/*
int main () {
    int size;
    cin >> size;
    vector<double> seq(size);
    for (int i = 0; i < size; ++i) {
        cin >> seq[i];
    }
    double elem;
    cin >> elem;
    cout << first_occurrence(elem, seq) << endl;
}
*/