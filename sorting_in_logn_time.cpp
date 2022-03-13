//Author : Krishan Kant Agnihotri        
//Enroll : 00716401519
//Class  : Btech  IT 6th sem

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Time cout<<"Time Taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";
void merge(int l,int mid,int r,vector<int> &v){
    int n1 = (mid-l+1);
    int n2 = (r-mid);
    vector<int> one(n1);
    vector<int> two(n2);
    for(int i = 0 ;i<n1 ;i++){
        one[i] = v[i+l];
    }
    for(int i = 0;i<n2 ;i++){
        two[i] = v[i+mid+1];
    }
    int i = 0 ; 
    int j = 0 ; 
    int k = l ;
    while(i<n1 && j<n2){
        if(one[i]>two[j]){
            v[k++] = two[j++];
        }
        else
            v[k++] = one[i++];
    } 
    while(i<n1){
        v[k++] = one[i++];
    }
    while(j<n2){
        v[k++] = two[j++];
    }

}
void merge_sort_recur(int l ,int r,vector<int> &v){
    if(l<r) {
    int mid = l + (r-l)/2;
    merge_sort_recur(l,mid,v);
    merge_sort_recur(mid+1,r,v);
    merge(l,mid,r,v);
   }
}
void merge_sort(vector<int> v){
//merge_sort
    vector<int> arr  = v;
    cout<<"Merge Sort:\n\n";
    int n = v.size();
    merge_sort_recur(0,n-1,arr); 
    cout<<"After sorting:\n";
    for(int i = 0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
ll divide(int l,int r,vector<int> &v){
    int dist = (r-l);
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
void q_sort(int l,int r,vector<int> &v){
    if(l<r){
        int p = divide(l,r,v);
        q_sort(l,p-1,v);
        q_sort(p+1,r,v);
    }

}
void quick_sort(vector<int> v){
//quick_sort
    vector<int> arr = v;
    cout<<"Quick Sort:\n\n";
    int n = v.size();
    q_sort(0,n-1,arr); 
    cout<<"After sorting:\n";
    for(int i = 0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void heapify(vector<int> &v,int n,int i){
    int mx = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && v[l]>v[mx]){
        mx = l;
    }
    if(r<n && v[r]>v[mx]){
        mx = r;
    }
    if(mx!=i){
        swap(v[i],v[mx]);
        heapify(v,n,mx);
    }
}
void heap_sort(vector<int> v){
//heap_sort
    vector<int> arr = v;
    cout<<"Heap Sort:\n\n";
    int n = v.size();
    for(int i = n/2-1 ;i>=0 ;i--){
        heapify(arr,n,i);
    }     
    for(int i = n-1 ;i>0 ;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    cout<<"After sorting:\n";
    for(int i = 0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n; i++){
        cin>>v[i];
    }
    clock_t time_p=clock();
    merge_sort(v);
    Time
 
    time_p = clock();
       heap_sort(v);
    Time
    time_p = clock();
    quick_sort(v);
    Time
}
int main(){
    solve();
}


