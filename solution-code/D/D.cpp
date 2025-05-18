#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, A[101010], On[101010];

ll CW(){
    int q = 0, r = 0;
    for(int i=0; i<M; i++) q += r > On[i], r = On[i];
    return 1LL * q * N + r;
}

ll CCW(){
    int q = 0, r = 0;
    for(int i=N-1; i>=M; i--) q += r > On[i], r = On[i];
    return 1LL * q * N + r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M; M--;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) On[A[i]-1] = i;
    cout << (CW() < CCW() ? "CW" : "CCW");
}