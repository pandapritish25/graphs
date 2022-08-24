#include<bits/stdc++.h>
using namespace std;
// #define int long long




void pr(vector<int> v){
    for(auto it:v){
        cout << it << " ";
    }
}

const int maxn=1e5+2;

vector<int> bfs(vector<int> adj[],int src,int n){
    vector<int> dis(n,maxn);
    queue<int> q;
    q.push(src);
    dis[src]=0;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(dis[node]+1 < dis[*it]){
                dis[*it]=1+dis[node];
                q.push(*it);
            }
        }
    }
    return dis;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+5];
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[x].push_back(y);
    }
    vector<int> dis=bfs(adj,0,n);
    pr(dis);
    
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
}
