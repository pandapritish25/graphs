#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=1e5+2;
vector<int> adj[maxn];
vector<int> vis(maxn,0);
vector<int> df;

void dfs(int node){
    vis[node]=1;
    df.push_back(node);
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            dfs(*it);
        }
    }
}

signed main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for(auto i:df){
        cout << i << " ";
    }
    cout << "\n";

}
