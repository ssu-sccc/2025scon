#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7;

int X, Y, D[3030][3030];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> X >> Y;
    D[0][0] = 1;
    for(int i=0; i<=X; i++){
        for(int j=0; j<=Y; j++){
            if(i - 2 >= 0 && j - 1 >= 0) D[i][j] = (D[i][j] + 3LL * D[i-2][j-1]) % MOD;
            if(j - 3 >= 0) D[i][j] = (D[i][j] + D[i][j-3]) % MOD;
        }
    }
    cout << D[X][Y];
}