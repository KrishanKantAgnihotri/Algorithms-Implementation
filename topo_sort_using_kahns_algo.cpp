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
vector<int> indeg;
vector<vector<int>> adj;
vector<bool> vis;
int main(){
    file_io();
    int n;//vertices;
    cin>>n;
    int m;//edges
    indeg.resize(n+1,0);
    cin>>m;
    adj.resize(n+1,vector<int>());
    vis.resize(n+1,false);
    queue<int> q;

    vector<int> ans;
    while(m--){
        int a,b;
        cin>>a>>b;// edge from vertex a to b 
        a++,b++;
        adj[a].push_back(b);
        indeg[b]++;
    }
    for(int i = 1 ;i<=n ;i++){
        if(indeg[i] == 0 ) q.push(i);
    }
    while(q.size()){
        int cur = q.front();
        q.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        ans.push_back(cur);
        for(auto child : adj[cur]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    cout<<"Topological Ordering of graph:\n";
    for(int i = 0 ; i<ans.size() ;i++){
        ans[i]--;
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
// 6
// 6
// 5 2 
// 5 0 
// 4 0 
// 4 1 
// 2 3
// 3 1

