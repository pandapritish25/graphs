#include<bits/stdc++.h>
using namespace std;
#define int long long

bool bipartite(vector<int> adj[],vector<int> col,int node){
    if(col[node]==-1){
        col[node]=1;
    }
    
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(col[*it]==-1){
            col[*it]=1-col[node];
            if(!bipartite(adj,col,*it)){
                return false;
            }
        }
        else if(col[*it]==col[node]){
            return false;
        }
    }
    return true;
}

bool check(vector<int> adj[],int n){
    vector<int> col;
    for(int i=0;i<n;i++){
        col.push_back(-1);
    }
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            if(!bipartite(adj,col,i)){
                return false;
            }
        }
    }
    return true;
}
signed main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    if(check(adj,n)){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
    
}
