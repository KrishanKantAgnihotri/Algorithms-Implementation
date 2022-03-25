//Author : Krishan Kant Agnihotri        
//Longest common subsequence
#include<bits/stdc++.h>
using namespace std;
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
bool test =false;
bool file = true;
void solve(){
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i  = 0 ;i <=n ;i++){
        for(int j = 0 ;j<=m ;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0 ; 
            }
            else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
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

//abc
//abccff
