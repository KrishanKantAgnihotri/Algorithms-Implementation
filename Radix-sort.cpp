//Author : Krishan Kant Agnihotri        
#include<bits/stdc++.h>
using namespace std;
#define Time cerr<<"\nTime Taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";
clock_t time_p=clock();
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
void count_sort(int n,vector<int> &v,int p){
    vector<int> arr = v;
    vector<int> store(10);
    int m = 10;
    for(int i = 0 ; i<n; i++){
        store[(arr[i]/p)%10]++;
    }
    for(int i = 1 ;i<m ;i++){
        store[i]+=store[i-1];
    }
    vector<int> ans(n);
    for(int i = arr.size() -1 ;i>=0 ;i--){
        ans[store[(arr[i]/p)%10]-1] = arr[i];
        store[(arr[i]/p)%10 ]--;
    }
    for(int i = 0;i<ans.size() ;i++){
        v[i] = ans[i];
    }
}
void radix_sort(int n,vector<int> v){
    cout<<"Radix sort:\n\n";
    int mx = *max_element(v.begin(),v.end());
    for(int i = 1 ;i<mx; i*=10){
        count_sort(n,v,i);
    }
    for(int i = 0 ;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
bool test =false;
bool file = true;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n ;i++){
        cin>>v[i];
    }
    radix_sort(n,v);
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


