// Crie uma função genérica chamada juntar que receba dois parâmetros de tipos diferentes (ex: int, string, char, etc) 
// e retorne um pair<T1, T2> contendo esses valores.
#include <bits/stdc++.h>

using namespace std;

template<typename T1, typename T2>
vector<pair<T1, T2>> juntar(T1 val1, T2 val2) {
    vector<pair<T1, T2>> juncao;

    juncao.emplace_back(val1, val2);

    return juncao;
}

int main() {
    auto v = juntar(5, string("abc"));
    for (auto p : v)
        cout << p.first << " - " << p.second << endl;
}

// #include <bits/stdc++.h>
// using namespace std;

// template<typename T1, typename T2>
// pair<T1, T2> juntar(T1 val1, T2 val2) {
//     // make_pair cria um pair<int, const char*>
//     return make_pair(val1, val2); // ou: return {val1, val2};
// }

// int main() {
//     auto p1 = juntar(5, "Olá");  // precisa ser string, não const char*
//     auto p2 = juntar('A', 3.14);
    
//     cout << p1.first << " - " << p1.second << endl;
//     cout << p2.first << " - " << p2.second << endl;
// }
