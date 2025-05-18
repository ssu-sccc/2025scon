#include <bits/stdc++.h>
using namespace std;

int N, D[202020], R;
vector<int> G[202020];

void DFS(int v, int b=-1, int d=1){
    D[v] = d;
    for(auto i : G[v]){
        if(i == b) continue;
        if(!D[i]) DFS(i, v, d+1);
        else R = D[i] - D[v] + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1,u,v; i<=N; i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    DFS(1);
    cout << (R % 2 ? 3 : 2);
}