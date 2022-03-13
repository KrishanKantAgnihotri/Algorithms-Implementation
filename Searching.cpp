//Author : Krishan Kant Agnihotri        
//Enroll : 00716401519
//Class  : Btech  IT 6th sem

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Time cout<<"Time Taken : "<<fixed<<setprecision(10)<<(double)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";

void lin_search(vector<ll> v,int x){
    cout<<"Linear Search:\n";
   cout<<x<<" ";
    for(int i = 0 ; i<v.size() ;i++){
        if(v[i] == x) {
            cout<<"Found\n";
            return ;
        }
    }
    cout<<"NOT Found\n";
    return ;
}

void bin_search(vector<ll> v,int x){
    cout<<"Binary Search:\n";
    cout<<x<<" ";
    sort(v.begin(),v.end());
    clock_t time_p = clock();
    ll l = 0 ; 
    ll r = v.size()-1;
    while(l<=r){

        ll mid = (l+r)/2;
        if(v[mid] == x){
            cout<<"Found\n";
            Time
            return ;
        }
        else if(v[mid]>x){
            r = mid-1;
        }
        else 
            l = mid+1;
    }
    cout<<"NOT FOUND\n";
    Time
    return ;
}
const ll M = 10000019;

void dir_search(vector<ll> v,int x){
    //using quadratic probing
    cout<<"Direct Search:\n";
    vector<int> arr(M);
    cout<<x<<" ";
    int n = v.size();
    for(int i = 0 ; i<M ;i++) arr[i] = -1;

    for(int i = 0 ; i<n ;i++){
        if(arr[v[i]%M] != -1){
            // cout<<"Hel\n";
            for(int j = 1 ;j*j<M ;j++){
                if(arr[(v[i]+j*j)%M] != -1){
                    continue;
                }
                else{
                    arr[(v[i]+j*j)%M] = v[i];
                }

            }
        }
        else{
            arr[v[i]%M] = v[i];
        }

    }
    clock_t time_p = clock();
    if(arr[x%M] == x){
        cout<<"Found\n";
        Time
        return ;
    }
    else{
        for(int j = 1 ;j*j<M;j++){
            if(arr[(x+j*j)%M] == x){
                cout<<"Found\n";
                Time
                return ;
            }
        }
    }
    cout<<"NOT found\n";
    Time
}

void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
   //comment from here if dont want random input
    srand(time(0));
    for(int i = 0 ;i <n; i++){
        v[i] = rand()%100000 +1;
    }
    int x = rand()%100000 +1;
    random_shuffle(v.begin(),v.end());
   //_________________________________________________


    //uncomment if want to take input manually 
    // for(int i = 0 ; i<n; i++){
    //     cin>>v[i];
    // }
    // int x;
    // cin>>x;
    clock_t time_p=clock();
    lin_search(v,x);
    Time
    
    bin_search(v,x);
    // Time
    
    dir_search(v,x);
    // Time
}
int main(){
    if(file)
      file_io();
    solve();
}


