// Uma técnica de busca completa que utiliza recursão para verificar o espaço de soluções
// é comum um código precisar de funções como is_solution, process_solution e candidates

#include <bits/stdc++.h>

using namespace std;

bool is_solucion(int i, int N) {
    return i == N;
}

void process_solution(const vector<int>&xs) {
    cout << "{ ";

    for (auto x : xs) {
        cout << x << " ";
    }
    cout << "}" << endl;

}

vector<int> candidates(int i, const vector<int>& as) {
    return {as[i]};
}

void backtracking(vector<int>& xs, int i, int N, const vector<int>& as) {
    // caso base
    if (is_solucion(i, N)) {
        process_solution(xs);
    } else {
        auto cs = candidates(i, as);

        for(auto c : cs) {
            backtracking(xs, i + 1, N, as);

            xs.push_back(c);
            backtracking(xs, i+1, N, as);
            xs.pop_back();
        }
    }
}

int main() {
    vector<int> as {2, 3, 5, 7, 11};
    vector<int> xs;

    backtracking(xs, 0, (int) as.size(), as);

}