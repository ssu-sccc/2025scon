#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N);
    for(auto &i : A) cin >> i;
    partial_sum(A.rbegin(), A.rend(), A.rbegin(), [](auto a, auto b){ return min(a, b); });
    cout << accumulate(A.begin(), A.end(), 0LL);
}