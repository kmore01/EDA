// Programa que maneja una lista de palabras y cuando acaba, imprime las 
// palabras que se encuentran en la lista y las palabras que se encontraban
// anteriormente en ella

#include <iostream>
#include <set>

using namespace std;

// Funcion que ordena el set en orden ascendiente respecto a la longitud de la 
// palabra, si tienen la misma longitud, se usa el orden alfabetico  
struct compare {
    bool operator()(const string &f, const string &s) const {
        if (f.length() == s.length()) return f < s;
        return f.length() < s.length();
    }
};

// Funcion para imprimir la salida del programa
void imprimir(const set<string> &hs, const set<string, compare> &hd,
const int &game) {
    if (game != 1) cout << endl;
    cout << "GAME #" << game << endl << "HAS:" << endl;
    for (auto it = hs.begin(); it != hs.end(); ++it) {
        cout << *it << endl;
    }
    cout << endl << "HAD:" << endl;
    for (auto it = hd.begin(); it != hd.end(); ++it) {
        cout << *it << endl;
    }
}

int main () {
    int game = 1;
    bool stop = false;
    string w;
    cin >> w;
    while (not stop) {
        set<string> has;
        set<string, compare> had;
        while (w != "END" and w != "QUIT") {
            if (not has.count(w) and not had.count(w)) has.insert(w);
            else if (has.count(w)) {
                has.erase(w);
                had.insert(w);
            }
            else { // had.count(w)
                had.erase(w);
                has.insert(w);
            }
            cin >> w;
        }
        imprimir(has, had, game);
        ++game;
        if (w == "QUIT") stop = true;
        else cin >> w;
    }
}