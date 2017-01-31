#include <bits/stdc++.h>
#define SIZE 101
#define pb push_back
using namespace std;
struct node{
    int u , w ;
};
class cmp{
    public ://function overloaded,overloading resolution
    bool operator () (node &a,node &b){
        if(a.w>b.w) return true;
        else return false;
    }
};
vector <int> graph[SIZE];
vector <int> cost[SIZE];

int Dijkstra(int N,int source,int destination){
    bool visit[SIZE] ;
    for(int i=1;i<=SIZE;i++) visit[i]=false;
    priority_queue <node,vector<node>,cmp> Q;
    node n;
    n.u=source;
    n.w=0;
    Q.push(n);
    while(Q.size()!=0) {
        n = Q.top();
        Q.pop();
        int u = n.u , w = n.w;
        if(visit[u]) continue;
        visit[u]=true;
        cout << u <<" ";
        if(u==destination) return w;
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(visit[v]==false){
                n.u=v ; n.w=w+cost[u][i];
                Q.push(n);
            }
        }
    }
    return destination;
}
int main()
{
    int N,M;
    cin >>N>>M;
    for(int i=1; i<=M; i++){
        int u , v , w;
        cin >> u >> v >> w;
        graph[u].pb(v);
        cost[u].pb(w);
    }
    int x , y ;
    cin >> x >>y;
    cout<< "Shortest path: "<<endl;
    int z = Dijkstra(N,x,y);
    cout <<endl;
    cout <<"The cost is: "<<z;
    return 0;
}
/*sample input output

6 10
1 2 10
1 3 2
3 2 3
3 4 20
3 5 15
2 4 30
2 5 4
5 4 5
5 6 40
4 6 2
1 6
Shortest path:
1 3 2 5 4 6
The cost is: 16

*/
