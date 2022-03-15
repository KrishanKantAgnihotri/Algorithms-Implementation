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
void count_sort(int n,vector<int> v){
    vector<int> arr = v;
    cout<<"Counting sort:\n\n";
    int mx = *max_element(arr.begin(),arr.end());
    int mn = *min_element(arr.begin(),arr.end());
    vector<int> store(mx-mn+1);
    int m = mx-mn+1;
    for(int i = 0 ; i<n; i++){
        store[arr[i]-mn]++;
    }
    for(int i = 1 ;i<m ;i++){
        store[i]+=store[i-1];
    }
    vector<int> ans(n);
    for(int i = arr.size() -1 ;i>=0 ;i--){
        ans[store[arr[i]-mn]-1] = arr[i];
        store[arr[i]-mn]--;
    }
    for(int i = 0;i<ans.size() ;i++){
        arr[i] = ans[i];
    }
    for(int i = 0 ;i<arr.size();i++){
        cout<<ans[i]<<" ";
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

    count_sort(n,v);
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


