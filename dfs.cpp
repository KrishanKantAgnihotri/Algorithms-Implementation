//Author : Krishan Kant Agnihotri        
#include<bits/stdc++.h>
using namespace std;
void file_io(){

    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
vector<vector<int>> adj;
void dfs(int u,int p = -1){
    cout<<u<<" ";
    for(auto child : adj[u]){
        if(child == p) continue;
        dfs(child,u);
    }
}
int main(){
    file_io();
    int n;//vertex
    cin>>n;
    int m;
    cin>>m;//edges
    adj.resize(n+1,vector<int>());
    
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int r;//root vertex
    cin>>r;
    dfs(r);
}


