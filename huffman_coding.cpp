//Author : Krishan Kant Agnihotri       
//Huffman Coding 
//Btech IT - 6th sem  
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    char val;
    int freq;
    node *left;
    node *right;
    
};
bool operator<(node one ,node two){
        return one.freq >two.freq;
}
map<char,string> ans;
void dfs(node* root,string res){
    // cout<<root->val<<endl;
    if( (root->left == NULL) && (root->right ==NULL) ){
        ans[root->val] = res;
    }
    if(root->left!=NULL)
        dfs(root->left,res+'0');
    if(root->right!=NULL)
        dfs(root->right,res+'1');
}
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    freopen("log.txt","w",stderr);
    #endif
}
bool test = false;
bool file = true;
void solve(){
    string s;
    cin>>s;//input string which has to be encoded
    int n = s.length();
    map<char,int>  m;//frequency  table for message
    for(int i = 0 ;i<n ;i++){
        m[s[i]]++;
    }
    priority_queue<node*> pq;
    node* top ;
    for(pair<char,int> it : m){
        node* cur = new node;
        cur->val = it.first;
        cur->freq = it.second;
        cur->left = NULL;
        cur->right = NULL;
        top = cur;
        // cout<<it.second<<" ";
        pq.push(top);
    }
    // cout<<endl;
    node *l,*r,*t;
    while(pq.size()>1){
        l = pq.top();
        pq.pop();
        r = pq.top();
        pq.pop();
        t = new node;
        t->val = l->val;
        t->freq = l->freq+r->freq;
        t->left = l;
        t->right = r;
        // cout<<(t->freq)<<endl;
        pq.push(t);
    }
    dfs(t,"");
    for(auto it : ans){
        cout<<it.first<<" "<<it.second<<endl;
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


