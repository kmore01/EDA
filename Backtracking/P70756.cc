#include <iostream>
#include <vector>

using namespace std;

void llegir(vector<string> &v) {
    for (int i = 0; i < int(v.size()); ++i) {
        cin >> v[i];
    }
}

void escriure(const vector<vector<string> > &p) {
    for (int i = 0; i < int(p.size()); ++i) {
        cout << "subconjunt " << i + 1 << ": {";
        bool coma = false;
        for (int j = 0; j < int(p[i].size()); ++j) {
            if (coma) cout << ',';
            cout << p[i][j];
            coma = true;
        }
        cout << '}' << endl;
    }
    cout << endl;
}

void backtracking(vector<vector<string> > &p, int idx, const vector<string> &words) {
    // Cas base 
    if (idx == int(words.size())) {
        escriure(p);
    }
    // Cas recursiu
    else {
        for (int j = 0; j < int(p.size()); ++j) {
            p[j].push_back(words[idx]);
            backtracking(p, idx + 1, words);
            p[j].pop_back();
        }
    }
}

int main () {
    int n, p; // n > 0, p > 0
    cin >> n;
    vector<string> paraules(n);
    llegir(paraules);
    cin >> p;
    vector<vector<string> > particions(p);
    backtracking(particions, 0, paraules);
}