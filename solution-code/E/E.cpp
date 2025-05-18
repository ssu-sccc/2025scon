#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7;

ll N, D[1010101][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    D[0][0] = 1;
    for(int i=1; i<=N; i++){
        D[i][0] = (D[i-1][0] * 24 + D[i-1][1] * 2) % MOD;
        D[i][1] = (D[i-1][0] * 2 + D[i-1][1] * 24) % MOD;
    }
    cout << D[N][0];
}