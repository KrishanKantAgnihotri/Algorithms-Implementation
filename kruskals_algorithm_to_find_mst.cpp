//Author : Krishan Kant Agnihotri        
#include<bits/stdc++.h>
using namespace std;
#define Time cerr<<"\nTime Taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";
clock_t time_p=clock();

//boost for big int 
//#include<boost/multiprecision/cpp_int.hpp>
//uncoment for large int requirement
//using boost::multiprecision::cpp_int;

//forced_functions 
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
bool test = false;
bool file = true;
vector<int> par;
vector<int> sz; 
//find using path compression
int fnd(int a){
    if(par[a] == -1) return a;
    return par[a] = fnd(par[a]);
}
//union by rank
void merge(int a,int b){
    if(sz[a]>sz[b]){
        swap(a,b);
    }
    sz[a]+=sz[b];
    par[b] = a ; 
}
void solve(){
    int n;
    cin>>n;
    par.resize(n+1,-1);
    sz.resize(n+1,1);
    int m;
    cin>>m;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i = 0 ;i<m ; i++){
        int a,b,w;
        cin>>a>>b>>w;//edge a to b with weight w 
        pq.push({-w,{a,b}});
    } 
    int sm = 0 ; 
    vector<pair<int,int>> ans;
    while(pq.size() && (ans.size()<=n-1)){
        int w = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if(fnd(a) == fnd(b)){
            continue;
        }
        else {
            merge(fnd(a),fnd(b));
            ans.push_back({a,b});
            sm+=w;
        }
    }
    cout<<"Sum of weights of minimum spanning tree is :\n";
    cout<<sm<<endl;
    cout<<"Edge list for tree is :\n";
    for(int i = 0 ;i<ans.size() ;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
int main(){
    if(file)
      file_io();
    int t ;
    t = 1 ;
    if(test)
    cin>>t;
    while(t--){
            solve();

    }
    Time
}


