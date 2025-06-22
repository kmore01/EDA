// Programa que mide estadisticas (minimo, maximo, mediana) de numeros enteros

#include <iostream>
#include <map>

using namespace std;

int main () {
    string accion;
    int num_elem = 0, total = 0;
    map<int, int> num_veces;
    map<int, int>::iterator it;
    while (cin >> accion) {
        if (accion == "number") {
            int num;
            cin >> num;
            if (num_veces.count(num)) { // el elemento ya esta en el map
                it = num_veces.find(num);
                ++it->second; // una aparacion mas del num
            }
            else num_veces[num] = 1; // el elemento no esta en el map
            ++num_elem;
            total += num;
        }
        else { // DELETE
            if (num_elem != 0) { // hay algun elemento
                it = num_veces.begin();
                if (it->second == 1) { // solo aparece una vez
                    total -= it->first;
                    num_veces.erase(it);
                }
                else { // aparece mas de una vez
                    total -= it->first;
                    --it->second;
                }
                --num_elem;
            }
        }   

        cout.setf(ios::fixed);
	    cout.precision(4);
        if (num_veces.size() == 0) cout << "no elements" << endl;
        else cout << "minimum: " << num_veces.begin()->first
                  << ", maximum: " << (--num_veces.end())->first 
                  << ", average: " << double(total) / double(num_elem) << endl;
    }
}