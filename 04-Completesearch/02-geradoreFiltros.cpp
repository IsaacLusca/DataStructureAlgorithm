// PROBLEMA: LISTAR OS INTEIROS POSITIVOS MENORES OU IGUAIS A N
// QUE SEJAM MULTIPLOS DE A OU DE B
#include <bits/stdc++.h>

using namespace std;

// Usando um filtro onde percorre todos os elementos
vector<int> filter(int N, int a, int b) {
    vector<int> filtrado;

    for(int i = 1; i <= N; i++) {
        if (i % a == 0 or i % b == 0) {
            filtrado.emplace_back(i);
        }
    }
    return filtrado;
}

// Função com gerador:

vector<int> generator(int N, int a, int b) {
    vector<int> ms;

    for(int i = a; i <= N; i+=a) {
        ms.emplace_back(i);
    }

    cout << endl << endl;

    for(int i = b; i <= N; i+=b) {
        // evitar duplicatas
        if (i % a) {
            ms.emplace_back(i);
        }
    }
    return ms;
}

int main() {

    vector<int> filtro = filter(20, 3, 5);

    for(auto i : filtro) {
        cout << i << " ";
    }

    cout << endl;

    vector<int> gerador = generator(20, 3, 5);
    for(auto i : gerador) {
        cout << i << " ";
    }
    return 0;
}