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
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool test = false;
bool file = true;
vector<vector<int>> dp;
vector<vector<int>> rec;
vector<int> f;
vector<int> v;
int calc(int i,int j,int lvl ){
    if(i>j){
        return 0; 
    }
    if(i == j){
        rec[i][j] = i;
        return f[i]*lvl;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   
    int res = INT_MAX;
    int mark = -1;
    for(int k = i ;k<=j ;k++){
        int val = calc(i,k-1,lvl+1)+calc(k+1,j,lvl+1)+f[k]*lvl;
        if(val<res){
            res = val;
            mark = k;
        }
    }
    rec[i][j] = mark;
    // cout<<i<<" "<<j<<" "<<res<<"\n";
    return dp[i][j] = res;
}
void solve(){
    int n;
    cin>>n;
    v.resize(n);
    for(int i = 0 ;i<n; i++){
        cin>>v[i];//node value
    }

    f.resize(n);
    for(int i = 0 ;i<n ;i++){
        cin>>f[i];//weights of node
    }
    dp.resize(n,vector<int>(n,-1));
    rec.resize(n,vector<int>(n,-1));
    
    cout<<"Minimum cost of Optimal binary Search Tree:\n"<<calc(0,n-1,1)<<endl;
    //reconstruct matrix to reconstruct tree 
    // for(int i = 0 ;i<n ;i++){
    //     for(int j = 0 ;j<n ;j++){
    //         cout<<rec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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

}


