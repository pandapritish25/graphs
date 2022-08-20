#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=1e5+2;
vector<int> adj[maxn];
vector<int> vis(maxn,0);
vector<int> bfs;

signed main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int> q;
    q.push(1);
    vis[1]=1;
    
    while(!q.empty()){
        int node=q.front();
        bfs.push_back(node);
        q.pop();
        
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!vis[*it]){
                vis[*it]=1;
                q.push(*it);
            }
        }
    }
    
    for(auto i:bfs){
        cout << i << " ";
    }
    cout << "\n";
}
