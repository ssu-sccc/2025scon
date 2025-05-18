#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[1010101], B[1010101], C[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    for(int i=1; i<=N; i++) C[i] = A[i] ? B[i] : -B[i];

    ll R = accumulate(C+1, C+N+1, 0LL), M = 1, s = 0;
    for(int i=N; i>=2; i--) s += C[i], R += max(0LL, s), M += s > 0;
    cout << M << " " << R;
}