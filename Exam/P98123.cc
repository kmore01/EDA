#include <iostream>
#include <set>

using namespace std;

int main() {
    int nJoies;
    long long int preu;
    string accio;
    cin >> nJoies;
    set<long long int> joies;
    set<long long int> resta;
    long long int suma = 0;
    while (cin >> accio >> preu) {
        if (accio == "deixar") {
            if (joies.size() < nJoies) {
                joies.insert(preu);
                suma += preu;
            } else {
                long long int min = *(joies.begin());
                if (min < preu) {
                    joies.insert(preu);
                    joies.erase(joies.begin());
                    suma = suma + preu - min;
                    resta.insert(min);
                } else
                    resta.insert(preu);
            }
        } else {
            if (*(joies.begin()) <= preu) {
                joies.erase(preu);
                suma -= preu;
                if (resta.size() > 0) {
                    auto it = resta.end();
                    --it;
                    joies.insert(*it);
                    suma += *it;
                    resta.erase(it);
                }
            } else
                resta.erase(preu);
        }
        cout << suma << endl;
    }
}