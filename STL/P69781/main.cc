#include <iostream>
#include <map>

using namespace std;

int main() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        map<int, int> lista;
        lista[n] = 0;
        int posicion = 1;
        bool found = false;
        while (n <= 100000000 and not found) {
            // Actualizamos el numero n
            if (n % 2 == 0) n = n / 2 + x;
            else n = 3 * n + y;
            // Buscamos el numero en la lista para comprobar si ha aparecido
            map<int, int>::iterator it = lista.find(n);
            // Caso 1: No lo hemos encontrado
            if (it == lista.end()) lista[n] = posicion;
            // Caso 2: El numero ya estaba en la lista
            else {
                /* El numero de elementos de la sequencia sera la diferencia 
                    entre la ultima aparacion de ese mismo numero y la primera 
                    aparacion

                    Se utiliza n porque si no hay ninguna sequencia, hay que imprimir el primer numero que supera 100000000
                */
                n = posicion - (it->second);
                found = true;
            }
            ++posicion;
        }
        cout << n << endl;
    }
}