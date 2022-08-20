#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=1e5+2;
vector<int> adj[maxn];
vector<int> vis(maxn,0);

bool check_for_cycle(int s){
    queue<pair<int,int>> q;
    pair<int,int> p1=make_pair(s,-1);
    q.push(p1);
    vis[s]=1;
    
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        
        q.pop();
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!vis[*it]){
                vis[*it]=1;
                pair<int,int> p2=make_pair(*it,node);
                q.push(p2);
            }
            else if(*it!=parent){
                return true;
            }
        }
    }
    return false;
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
    bool possible=false;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(check_for_cycle(i)){
                possible=true;
            }
        }
    }
    
    if(possible==true){
        cout << "YES" << "\n";
        
    }
    else{
        cout << "NO" << "\n";
    }
    

}
