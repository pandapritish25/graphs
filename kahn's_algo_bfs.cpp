#include<bits/stdc++.h>
using namespace std;
#define int long long




vector<int> topo(vector<int> adj[],int n){
    queue<int> q;
    vector<int> indegree(n,0);
    
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    vector<int> helper;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        helper.push_back(node);
        
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            indegree[*it]--;
            if(indegree[*it]==0){
                q.push(*it);
            }
        }
    }
    
    return helper;
    
}


signed main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+2];
 
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    vector<int> topoo=topo(adj,n);

    for(auto i:topoo){
        cout << i << " ";
    }
 
    
}
