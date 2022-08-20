#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+2;


bool bipartite(vector<int> adj[],vector<int> col,int src){
    queue<int> q;
    q.push(src);
    col[src]=1;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(col[*it]==-1){
                col[*it]=1-col[node];
                q.push(*it);
            }
            else if(col[*it]==col[node]){
                return false;
            }
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
    vector<int> adj[n+2];
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> col;
    if(check(adj,n)){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}
