//Author : Krishan Kant Agnihotri        
#include<bits/stdc++.h>
using namespace std;
#define Time cout<<"\nTime Taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";
clock_t time_p=clock();
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
void insertion_sort(int n ,vector<float> &v){
    for(int i = 1 ;i<n ;i++)   {
        float key = v[i];
        int j = i-1;

        while(j>=0 && v[j]>key){
            v[j+1] =v[j];
            j--;
        }
        v[j+1] = key;
    } 
}
void bucket_sort(int n,vector<float> v){
    cout<<"Bucket sort:\n\n";
    vector<vector<float>> ans(n+1,vector<float>());
    for(int i = 0 ;i<n;i++){
        int id = v[i]*n;
        ans[id].push_back(v[i]);
    }
    for(int i = 0 ;i<n; i++){
        if(ans[i].size()>1){
            insertion_sort(ans[i].size(),ans[i]);
        }
    }
    int id = 0 ; 
    for(int i = 0 ;i<n;i++){
        int m = ans[i].size();
        int j = 0 ; 
        while(m--){
            v[id++] =ans[i][j++]; 
        }
    }
    for(int i = 0 ;i<n ;i++){
        cout<<fixed<<setprecision(2)<<v[i]<<" ";
    }
    cout<<endl;
}
bool test =false;
bool file = true;
void solve(){
    int n;
    cin>>n;
    vector<float> v(n);
    for(int i = 0 ; i<n ;i++){
        cin>>v[i];
    }
    bucket_sort(n,v);
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


