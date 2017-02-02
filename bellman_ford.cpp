// Run time O(V*E)
// V -> number of vertex
// E -> number of edges
#include<bits/stdc++.h>
#include <stdio.h>
#include <vector>
#define pb push_back
#define INF 1e8
#define SIZE 101
using namespace std;
struct node
{
    int u , v , w;
};
vector <node> edge;
int dist[SIZE];
void RELAX(int u,int v,int w)
{
    if((dist[v]>dist[u]+w)&&dist[u]!=INF)
    {
        dist[v]=dist[u]+w;
    }
}
bool Bellman_ford(int N,int source)
{
    for(int i=1;i<=N;i++) dist[i] = INF; //Initialize every node's distance from source is infinite
    dist[source]=0; //Initialize source distance is zero
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<edge.size();j++)
        {
            node obj = edge[j];
            int u=obj.u , v = obj.v , w = obj.w;
            RELAX(u,v,w);
        }
    }

    // Check negative cycle is present in the graph or not
    for(int i=0;i<edge.size();i++)
    {
        node obj = edge[i];
        int u=obj.u , v = obj.v , w = obj.w;
        if(dist[v]>dist[u]+w) return false;
    }

    return true;
}
int main()
{
    int n , m ; //n is the number of nodes and m is the number of relations
    cin >> n >> m;
    while(m--)
    {
        node obj;
        int u , v , w; // from node u to v is cost w
        cin >> u >> v >> w;
        obj.u=u;obj.v=v;obj.w=w;
        edge.pb(obj);
    }
    int source;
    cin >> source;
    bool decision=Bellman_ford(n,source);
    if(decision==false) puts("Negative cycle present!");
    else
    {
        for(int i=1;i<=n;i++) cout <<"Distance from "<<source<<" to "<< i << " is "<<dist[i];
    }
    return 0;
}
