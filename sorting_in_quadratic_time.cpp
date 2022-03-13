//Author : Krishan Kant Agnihotri        
//Enroll : 00716401519
//Class  : Btech  IT 6th sem

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Time cout<<"Time Taken : "<<fixed<<setprecision(10)<<(double)(clock()-time_p)<<"\n";
bool file = true;
void selection_sort(vector<int> v){
//selection_sort
    vector<int> arr  = v;
    cout<<"Selection Sort:\n\n";
    int n = v.size();
    for(int i = 0 ;i<n ;i++)   {
        int smallest_idx = i;
        for(int j = i+1 ;j<n ;j++){
            if(arr[j]<arr[smallest_idx]) smallest_idx = j;
        }
        swap(arr[i],arr[smallest_idx]);
    } 
    cout<<"After sorting:\n";
    for(int i = 0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void insertion_sort(vector<int> v){
//insertion_sort
    vector<int> arr = v;
    cout<<"Insertion Sort:\n\n";
    int n = v.size();
    for(int i = 1 ;i<n ;i++)   {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] = key;
    } 
    cout<<"After sorting:\n";
    for(int i = 0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void bubble_sort(vector<int> v){
//bubble_sort
    vector<int> arr = v;
    cout<<"Bubble Sort:\n\n";
    int n = v.size();
    for(int i = 0 ;i<n ;i++)   {
        bool flag = false;
        for(int j = 0;j<n-i-1 ;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
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
    selection_sort(v);
    Time
    bubble_sort(v);
    time_p = clock();
    Time
    time_p = clock();
    insertion_sort(v);
    Time
}
int main(){
    solve();
}


