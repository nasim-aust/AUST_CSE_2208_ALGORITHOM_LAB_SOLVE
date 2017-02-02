// Use Depth First Search (DFS) algorithm
// Time Complexity O(V+E)
// V -> vertex E -> edge
#include<bits/stdc++.h>
#include <stdio.h>
#include <vector>
#define MAXM 1001
#define pb push_back
using namespace std;

vector <int> graph[MAXM+10] , seq ;
int visit[MAXM+10],cycle=0;
void dfs(int u)
{
    if(visit[u]==2||cycle) return;
    if(visit[u]==1)
    {
        cycle = 1 ;
        return;
    }
    visit[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i];
        dfs(v);
    }
    visit[u]=2;
    seq.pb(u);
}
int main()
{
    int N,M; // N is the number of subjects and M is the number of connections
    cin >> N >>M;
    while(M--)
    {
        int u , v ; // The subject v must read after u
        cin >> u >> v;
        graph[u].pb(v);
    }
    for(int i=1;i<=N;i++) dfs(i);
    if(cycle) cout << "Cycle Found!";
    else for(int i=N-1;i>=0;i--) cout << seq[i];
    return 0;
}
