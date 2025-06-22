#include <iostream>
#include <vector>

using namespace std;

void llegir(vector<pair<char, bool> > &v) {
    for (int i = 0; i < int(v.size()); ++i) {
        char c;
        cin >> c;
        v[i] = {c, false};
    }
}

bool es_vocal(char c, const vector<pair<char, bool> > &vc) {
    for (int i = 0; i < int(vc.size()); ++i) {
        if (c == vc[i].first) return true;
    }
    return false;
}

void cons_i_voc(vector<char> &v, int idx, vector<pair<char, bool> > &vc, vector<pair<char, bool> > &cs) {
    // Cas base
    if (idx == int(v.size())) {
        for (int i = 0; i < int(v.size()); ++i) {
            cout << v[i];
        }
        cout << endl;
    }
    // Cas recursiu
    else {
        for (int i = 0; i < int(v.size()) / 2; ++i) {
            if (idx == 0) { // Primera posicio
                if (not vc[i].second) {
                    v[idx] = vc[i].first;
                    vc[i].second = true;
                    cons_i_voc(v, idx + 1, vc, cs);
                    vc[i].second = false;
                }
            }
            else {
                // Precedit de vocal
                if (es_vocal(v[idx - 1], vc)) {
                    if (not cs[i].second) {
                        v[idx] = cs[i].first;
                        cs[i].second = true;
                        cons_i_voc(v, idx + 1, vc, cs);
                        cs[i].second = false;
                    }
                }
                // Precedit de consonant
                else {
                    if (not vc[i].second) {
                        v[idx] = vc[i].first;
                        vc[i].second = true;
                        cons_i_voc(v, idx + 1, vc, cs);
                        vc[i].second = false;
                    }
                }
            }
        }
    }
}

int main () {
    int n;
    cin >> n; // 1 < n < 6
    vector<pair<char, bool> > consonants(n); 
    llegir(consonants);
    vector<pair<char, bool> > vocals(n);
    llegir(vocals);
    vector<char> solucio(2 * n);
    int idx = 0;
    cons_i_voc(solucio, idx, consonants, vocals);
}