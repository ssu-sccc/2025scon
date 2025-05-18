#include <bits/stdc++.h>
using namespace std;

int N, M, C, D, A[202];

int dp[2][25252];
vector<int> G[25252];
int Cost(int t, int k){ return M - abs(A[t] - k); }
void Clear(int x){
    memset(dp[x], 0, sizeof(dp[x][0]) * (M/C+10));
}
int Solve(int p){
    const auto &v = G[p];
    if(v.empty()) return 0;

    Clear(1);
    for(int i=0; i<v.size(); i++) dp[1][i] = Cost(1, v[i]);

    deque<int> dq;
    for(int i=2; i<=N; i++){
        Clear(i%2);

        dq.clear();
        for(int j=0; j<v.size(); j++){
            while(!dq.empty() && j - dq.front() > D) dq.pop_front();
            while(!dq.empty() && dp[i-1&1][dq.back()] <= dp[i-1&1][j]) dq.pop_back();
            dq.push_back(j);
            dp[i&1][j] = max(dp[i&1][j], dp[i-1&1][dq.front()] + Cost(i, v[j]));
        }

        dq.clear();
        for(int j=(int)v.size()-1; j>=0; j--){
            while(!dq.empty() && dq.front() - j > D) dq.pop_front();
            while(!dq.empty() && dp[i-1&1][dq.back()] <= dp[i-1&1][j]) dq.pop_back();
            dq.push_back(j);
            dp[i&1][j] = max(dp[i&1][j], dp[i-1&1][dq.front()] + Cost(i, v[j]));
        }
    }
    return *max_element(dp[N&1], dp[N&1]+v.size());
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> C >> D; D /= C;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=M; i++) G[i%C].push_back(i);

    int res = 0;
    for(int i=0; i<C; i++) res = max(res, Solve(i));
    cout << res;
}