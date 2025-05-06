#include <bits/stdc++.h>

using namespace std;

template<typename T1, typename T2>
vector<pair<T1, T2>> cartesian_product(const vector<T1>& A, const vector<T2>& B) {
    vector<pair<T1, T2>> AB;

    for(const auto& a: A) {
        for(const auto& b: B) {
            AB.emplace_back(a, b);
        }
    }
    return AB;
}

// Exemplo uso template

template<typename nomeTipo>
nomeTipo quadrado(nomeTipo n) {
    return n * n;
}

auto teste(auto n) {
    return n * n;
}

int main() {

    // Exemplo uso template
    cout << quadrado(5) << endl;
    cout << quadrado(3.14) << endl;
    
    // Teste:
    cout << teste(5) << endl;
    cout << teste(3.14) << endl;

    return 0;
}