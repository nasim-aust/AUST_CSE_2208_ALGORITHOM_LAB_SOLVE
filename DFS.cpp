#include<bits/stdc++.h>
#define white 0
#define gray 1
#define black 2
#define size 1001

using namespace std;

int colour[size];
int parent[size];
int adj[size][size];

void dfsVisit(int u , int vertex)
{
    colour[u] = gray;
    for(int i = 0 ; i<vertex ; i++)
    {
        if(adj[u][i] == 1)
        {
            int v = i;
            if(colour[v] == white)
            {
                parent[v] = u;
                dfsVisit(v , vertex);
            }
        }
    }
    colour[u] = black;
    cout << u << " ";
}

void dfs(int vertex)
{
    for(int i = 0 ; i < vertex ; i++)
        colour[i] = white;
    cout << "DFS is ";
    for(int i = 0 ; i<vertex ; i++)
    {
        if(colour[i] == white)
        {
            dfsVisit(i , vertex);
        }
    }
}

int main()
{
    //freopen("input1.txt" , "r" , stdin);
    int vertex;
    int edge;
    cin >> vertex >> edge;
    int node1,node2;
    for(int i = 0 ; i< edge ; i++)
    {
        cin >> node1 >> node2;
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;
    }
    for(int i = 0 ; i < vertex ; i++)
    {
        for(int j = 0 ; j < vertex ; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    dfs(vertex);
    return 0;
}
/*
7	6
0	1
0	4
1	3
1	4
2	3
5	6
*/
