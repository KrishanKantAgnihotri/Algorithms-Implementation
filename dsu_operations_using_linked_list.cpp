//Author : Krishan Kant Agnihotri        
//disjoint set union operation using linked list 
#include<bits/stdc++.h>
using namespace std;
bool test = false;
bool file = true;
struct node{
    node* hd;
    node* tl;
    int val;
};
class List{

public:
    unordered_map<int,node*> u;
    node* makeset(int x){
        node* cur = new node;
        cur->val = x;
        cur->hd = cur;
        cur->tl = NULL;
        return cur;
    }
    node* find(int x){
        node* cur = u[x];
        if(cur->hd == cur){
            return cur;
        }
        return find(cur->hd->val);
    }
    void uni(int a ,int b){
        node* one = find(a);
        node* two = find(b);
        if(one == two){
            return ;
        }
        node *ptr = u[a];
        while(ptr->tl!=NULL){
            ptr = ptr->tl;
        }
        ptr->tl = two;
        two->hd = ptr;
    }
};
        void file_io(){

    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
void solve(){
    int n;
    cin>>n;
    List s;
    for(int i = 1;i<=n ;i++){
        s.u[i] = s.makeset(i);
    }
    int q;//no. of operation
    cin>>q;
    while(q--){
        int t;//type of operation 1 means find and 2 means union
        cin>>t;
        if(t == 1){
            int val;
            cin>>val;
            cout<<s.find(val)->val<<endl;
        }
        else {
            int a,b;
            cin>>a>>b;
            s.uni(a,b);
        }
    }
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


