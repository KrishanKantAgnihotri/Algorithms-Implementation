//Author : Krishan Kant Agnihotri        
//Semester : 6th sem 
//Branch: IT
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Time cout<<"\nTime Taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";
clock_t time_p=clock();

void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
bool test = false;
bool file = true;
int divide(int l,int r,vector<int> &v){
    int dist = (r-l+1);
    srand(time(0));
    int p = l+rand()%dist;
    swap(v[p],v[r]);
    p = v[r];
    int i = l-1 ; 
    for(int j = l;j<=r-1;j++){
        if(v[j]<p){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i+1;
    
}
int median_order_statistic(int l,int r,int k,vector<int> &v){
    if(l<=r){
        int p = divide(l,r,v);
        if(p == k){
            return v[p];
        }
        else if(p>k){
           return median_order_statistic(l,p-1,k,v);
        }
        else{
            return median_order_statistic(p+1,r,k,v);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n ;i++) cin>>v[i];
        int k ;
    cin>>k;

    k--;
    if(k>n-1 || k<0){
        cout<<-1<<endl;
        return ;
    }
    cout<<median_order_statistic(0,n-1,k,v)<<endl;

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


