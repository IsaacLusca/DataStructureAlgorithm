#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    for (int i = 1; i <= 5; i++) {
        int valor;
        cout << "Insira o " << i << " Elemento: ";
        cin >> valor;
        v.push_back(valor);
    }

    cout << "Valores adicionados: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Inserir 999 no meio
    v.insert(v.begin() + (v.size() / 2), 999);
    cout << "Valor adicionado no meio: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Remover o primeiro
    v.erase(v.begin());
    cout << "Removendo o primeiro termo: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Remover o último
    v.pop_back();
    cout << "Removendo o ultimo termo: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
