#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(vector<int> adj[],int n){
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
    
    int counter=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        counter++;
        
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            indegree[*it]--;
            if(indegree[*it]==0){
                q.push(*it);
            }
        }
    }
    return !(counter==n);
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
    
    bool helper=check(adj,n);
    if(helper==true){
        cout << "YES" << "\n";
        return 0;
    }
    cout << "NO" << "\n";
}
