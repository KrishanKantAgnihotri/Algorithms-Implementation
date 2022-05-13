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
const int INF = 1e8;
vector<vector<pair<int,int>>> adj;
vector<bool> vis;
vector<int> dist;
int main(){
    file_io();
    int n;//vertex
    cin>>n;
    adj.resize(n+1,vector<pair<int,int>>());
    vis.resize(n+1,false);
    dist.resize(n+1,INF);
    int m;//edges
    cin>>m;
    while(m--){
        int u,v,w;//edge from a to b with weight w
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int s;//source
    cin>>s;
    priority_queue<pair<int,int>> pq;
    dist[s] = 0 ;
    pq.push({0,s}); 
    while(pq.size()){
        int w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto childd : adj[u]){
            int child  = childd.first;

            if(dist[child]> dist[u]+ childd.second){
                dist[child] = dist[u] + childd.second;
                pq.push({-dist[child],child});
            }
        }
    }
    for(int i = 1 ;i<=n ;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}


