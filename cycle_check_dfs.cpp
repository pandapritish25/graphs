#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=1e5+2;
vector<int> adj[maxn];
vector<int> vis(maxn,0);

bool check_for_cycle(int node,int parent){
    vis[node]=1;
    
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            if(check_for_cycle(*it,node)){
                return true;
            }
        }
        else if(*it!=parent){
            return true;
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
            if(check_for_cycle(i,-1)){
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
