//Author : Krishan Kant Agnihotri        
//matrix chain multiplication 
#include<bits/stdc++.h>
using namespace std;
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
vector<array<int,2>> v;
vector<vector<int>> dp;
int calc(int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];

    if(i>j){
        return INT_MAX;
    }
    int res = INT_MAX;
    for(int k = i ;k<j; k++){
        int cur = calc(i,k)+calc(k+1,j)+ v[i][0]*v[k][1]*v[j][1];
        res = min(res,cur);
    }
    return dp[i][j] = res;
}
bool test =false;
bool file = true;
void solve(){
    int n;
    cin>>n;
    v.resize(n+1);
    dp.resize(n+1,vector<int>(n+1,-1));
    for(int  i  = 1 ;i<=n ;i++){
        cin>>v[i][0]>>v[i][1];//{n,m}
    }
    for(int i = 0 ; i<=n ;i++){
        dp[i][i] = 0 ; 
    }
    cout<<calc(1,n)<<endl;//recursive call

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



// 4
// 14 14   
// 14 2
// 2 4
// 4 5