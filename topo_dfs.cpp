#include<bits/stdc++.h>
using namespace std;
#define int long long

void topo(int node,stack<int> &st,vector<int> &vis,vector<int> adj[]){
    vis[node]=1;
    
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            topo(*it,st,vis,adj);
        }
    }
    
    st.push(node);
}


signed main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    vector<int> vis(n+1,0);
    stack<int> st;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topo(i,st,vis,adj);
        }
    }
    
    vector<int> helper;
    
    while(!st.empty()){
        helper.push_back(st.top());
        st.pop();
    }
    
    for(auto i:helper){
        cout << i << " ";
    }
    
    
}
