#include <bits/stdc++.h>
using namespace std;

int N, C[111], R;

bool Check(int x, int y, int z){
    C[x]++; C[y]++; C[z]++;
    bool flag = false;
    for(auto i : {x, y, z}) flag |= C[i] == 1 && count(C+i+1, C+101, 1) == 0;
    C[x]--; C[y]--; C[z]--;
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1,x,y,z; i<=N; i++) cin >> x >> y >> z, C[x]++, C[y]++, C[z]++;
    for(int i=1; i<=100; i++) for(int j=i+1; j<=100; j++) for(int k=j+1; k<=100; k++) R += Check(i, j, k);
    cout << R;
}