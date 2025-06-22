#include <iostream>
#include <vector>
using namespace std;

int pic(const vector<int> &v, int i, int j) {
    if (j-i == 0) return j;
	if (j-i == 1) {
		if (v[j] > v[i]) return j;
		return i;
	}
	int mid = (i+j) / 2;
	if (v[mid-1] < v[mid] and v[mid] < v[mid+1]) return pic(v, mid+1, j);
	if (v[mid-1] > v[mid] and v[mid] > v[mid+1]) return pic(v, i, mid-1);
	return mid;
}

bool binary(int x, const vector<int>& v, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == x) return true;
        if (v[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

bool binary2(int x, const vector<int>& v, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == x) return true;
        if (v[mid] < x) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

bool search(int x, const vector<int>& v) {
    int npic = pic(v, 0, v.size() - 1);
    if (binary(x, v, 0, npic)) return true;
    return binary2(x, v, npic + 1, v.size() - 1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}