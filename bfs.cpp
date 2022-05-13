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
vector<bool> vis;
int main(){
    file_io();
    int n;//vertex
    cin>>n;
    int m;
    cin>>m;//edges
    adj.resize(n+1,vector<int>());
    vis.resize(n+1,false);
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int r;//root vertex
    cin>>r;
    queue<int> q;
    q.push(r);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(vis[cur]) continue;
        cout<<cur<<" ";
        vis[cur] = true;
        for(auto child : adj[cur]){
            if(vis[child]) continue;
            q.push(child);
        }
    }

}


