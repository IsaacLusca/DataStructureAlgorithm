#include <bits/stdc++.h>
using namespace std;

int main() {
    // Criando um vetor de inteiros
    vector<int> v;

    // Adicionando elementos
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Após push_back: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Removendo o último elemento
    v.pop_back();

    cout << "Após pop_back: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Inserindo na posição 1 (segunda posição)
    v.insert(v.begin() + 1, 15);

    cout << "Após insert: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // FOR PADRãO:

    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }


    // Removendo o elemento da posição 0
    v.erase(v.begin());

    cout << "Após erase: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Limpando todo o vetor
    v.clear();

    cout << "Após clear, tamanho do vetor: " << v.size() << endl;

    return 0;
}

// ADICIONAR OU REMOVER NO FINAL DE UM VTOR SEMPRE É O(1)

// ADICIONAR OU REMOVER EM COMEÇO, É PRECISO INTERAR E MUDAR A POSIÇÃO DOS OUTROS, OU SEJA, SE TORNA O(N)
// v.insert(v.begin() + (v.size() / 2), 15);
