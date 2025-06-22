/* program that calculates in which position is a number in a vector */

#include <iostream>
#include <vector>

using namespace std;

// Pre: The vector v is sorted in strictly increasing order
// Moreover, we have 0 ≤ left ≤ size of v and −1 ≤ right < size of v
int position(double x, const vector<double>& v, int left, int right) {
    int answer;
    if (left > right) answer = -1; // case base
    else { // general case
        int medium = (left + right) / 2;
        if (x < v[medium]) { 
            answer = position(x, v, left, medium - 1);
        }
        else if (x > v[medium]) {
            answer = position(x, v, medium + 1, right);
        }
        else answer = medium;
    }
    return answer;
}

// function that saves numbers in a vector
vector<double> read_in_vector() {
    int size;
    cin >> size;
    vector<double> VNumbers(size);
    for (int i = 0; i < size; ++i) {
        cin >> VNumbers[i];
    }
    return VNumbers;
}

int main () {
    double x;
    cin >> x;
    vector<double> sequence = read_in_vector();
    // left = 0, right = sequence.size()
    cout << position(x, sequence, 0, sequence.size()) << endl;
}