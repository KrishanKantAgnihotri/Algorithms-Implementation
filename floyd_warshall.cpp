#include<bits/stdc++.h>
using namespace std;
#define MAX_N 300
#define INF 987654321
int n;

int dist[MAX_N][MAX_N];
int flojd[MAX_N][MAX_N];
void FloydWarshall()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            flojd[i][j] = dist[i][j];
        }
        flojd[i][i] = 0;
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (flojd[i][k] + flojd[k][j] < flojd[i][j])
                {
                    flojd[i][j] = flojd[i][k] + flojd[k][j];
                }
            }
        }
    }
}
int main()
{
   
    int v,e;
    cin>>v;//vertex;
    cin>>e;//edges
    for(int i = 0 ;i<=v ;i++){
        for(int j = 0 ;j<=v ;j++){
            if(i == j) dist[i][j] = 0 ; 
            else 
            dist[i][j] = INF;
        }
    }
    for(int i = 0 ;i<e ;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = c;
    }
    
    n  = v;
    FloydWarshall();
    cout<<"Final Matrix: \n";
    for(int i = 1 ;i<=v;i++){
        for(int j = 1 ;j<=v ;j++){
            cout<<flojd[i][j]<<" ";
        }
        cout<<endl;
    }
}
