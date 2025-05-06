#include <bits/stdc++.h>

using namespace std;

// passar o valor que quer encontrar,
// O comprimento do vetor, e o vetor. Note que é com &
int find(int x, int N, const vector<int>& xs) {
    for(int i = 0; i < N; i++) {
        if(xs[i] == x) return i;
    }
    return -1;
}

int main() {

    vector<int> buscarAqui {2, 3, 5, 7, 11, 12, 17, 19};

    cout << find(7, 8, buscarAqui) << endl;

    return 0;
}

// Anotação adversa.

// Uma class e struct com o mesmo funcionamento:
class Pessoa {
    public:
        string nome;
        int idade;

        Pessoa(int nome, int idade) {
            this->nome = nome;
            this->idade = idade;

            cout << "Construtor chamado para " << nome << endl;
        }
};

// Pode escrever assim:

struct Pessoa {
    string nome; 
    int idade;

    Pessoa(string nome, int idade) : nome(nome), idade(idade) {
        cout << "Construtor chamado para " << nome << endl;
    }
};

