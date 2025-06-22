// DICCIONARI(MAP)

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    string ordre;
    map<string, string> diccionari;
    set<string> sols;
    while (cin >> ordre) {
        if (ordre == "liats") {
            string nom1, nom2;
            cin >> nom1 >> nom2;
            if (nom1 > nom2) {  // ordre alfabetic
                swap(nom1, nom2);
            }
            if (not diccionari[nom1].empty()) {
                sols.insert(diccionari[nom1]);
                diccionari.erase(diccionari[nom1]);
            }
            if (not diccionari[nom2].empty()) {
                sols.insert(diccionari[nom2]);
                diccionari.erase(diccionari[nom2]);
            }
            sols.erase(nom1);
            sols.erase(nom2);
            diccionari[nom1] = nom2;
            diccionari[nom2] = nom1;
        } else {  // "info"
            cout << "PARELLES:" << endl;
            set<pair<string, string>> parelles;  // No duplicats
            // Insertar elements
            for (const auto& [nom1, nom2] : diccionari) {
                if (nom1 < nom2) {  // Nomes es fara 1 vegada per cada parella
                    parelles.insert({nom1, nom2});
                }
            }
            for (const auto& p : parelles) {
                cout << p.first << ' ' << p.second << endl;
            }
            cout << "SOLS:" << endl;
            for (auto it = sols.begin(); it != sols.end(); ++it) {
                cout << *it << endl;
            }
            cout << "----------" << endl;
        }
    }
}