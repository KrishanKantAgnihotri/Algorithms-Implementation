#include<bits/stdc++.h>
using namespace std;
#define MAX_N 5001
#define MAX_E 25000001
#define INF 987654321

int v, e;

int dist[MAX_N];
struct Edge
{
    int x, y, weight;
};
Edge E[MAX_N];
int BellmanFord(int source)
{
    for (int i=0;i<v;i++)
    {
        if (i == source) dist[i]=0;
        else dist[i] = INF;
    }
    bool done = false;
    for (int i=0;!done&&i<v;i++)
    {
        done = true;
        for (int j=0;j<e;j++)
        {
            int so = E[j].x;
            int de = E[j].y;
            if (dist[so] + E[j].weight < dist[de])
            {
                dist[de] = dist[so] + E[j].weight;
                done=false;
            }
        }
    }
    if (!done) return -1; //negative edge cycle detected
    return 0;
}
int main()
{
   
    cin>>v;//vertex;
    cin>>e;//edges
    for(int i = 0 ;i<e ;i++){
        cin>>E[i].x>>E[i].y>>E[i].weight;
    }
    if(BellmanFord(0)==-1){
        return 0 ; 
    }
    for(int i = 0 ;i<v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
