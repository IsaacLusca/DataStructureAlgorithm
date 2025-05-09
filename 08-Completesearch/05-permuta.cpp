#include <bits/stdc++.h>

using namespace std;

void process_solucion(const vector<int>& xs) {
    for (int x : xs) {
        cout << x << " ";
    }
    cout << endl;
}

void backtrack(vector<int>& nums, int index) {
    int N = nums.size();

    if (index == N) {
        process_solucion(nums);
        return;
    }

    for(int i = index; i < N; i++) {
        swap(nums[index], nums[i]);
        backtrack(nums, index +1);
        swap(nums[index], nums[i]);
    }
}

int main() {
    vector<int>vetor = {1, 2, 3};
    backtrack(vetor, 0);
}