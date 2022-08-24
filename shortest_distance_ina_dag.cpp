#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+2;
vector<int> topo(vector<int> adj1[],int n){
    queue<int> q;
    vector<int> indegree(n,0);
    
    for(int i=0;i<n;i++){
        for(auto it:adj1[i]){
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
        for(it=adj1[node].begin();it!=adj1[node].end();it++){
            indegree[*it]--;
            if(indegree[*it]==0){
                q.push(*it);
            }
        }
    }
    return helper;
}

vector<int> path(vector<pair<int,int>> adj[],vector<int> adj1[],int n,int src){
    vector<int> v=topo(adj1,n);
    stack<int> st;
    for(int i=v.size()-1;i>=0;i--){
        st.push(v[i]);
    }
    
    vector<int>  dis(n,maxn);
    dis[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        
        if(dis[node]!=maxn){
            for(auto i:adj[node]){
                if(dis[node]+i.second < dis[i.first]){
                    dis[i.first]=dis[node]+i.second;
                }
            }
        }
    }
    return dis;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    vector<int> adj1[n];
    for(int i=0;i<m;i++){
        int x,y,wt;
        pair<int,int> p1=make_pair(y,wt);
        adj[x].push_back(p1);
        adj1[x].push_back(y);
    }
    vector<int> dis=path(adj,adj1,n,0);
    for(auto i:dis){
        if(i==maxn){
            cout << "cant be reached" <<  " ";
        }
        else{
            cout << i << " ";
        }
    }
    
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
}
