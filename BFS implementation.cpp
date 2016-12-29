#include<bits/stdc++.h>
#define     MAX     100000//maximum node
#define     pb          push_back

using namespace std;

vector < int > edges[MAX];
vector < int > cost[MAX];

int main()
{
    int N,E;
    cin >> N >> E;
    for(int i=1; i<=E; i++)
    {
        int x,y;
        cin >> x >> y;

        edges[x].pb(y);
        edges[y].pb(x);
        cost[x].pb(1);
        cost[y].pb(1);
    }
    //print which node connected with node 1
    cout << "Connected with node 1 :" ;
    int size = edges[1].size();
    for(int i=0; i<size; i++)
        cout << edges[1][i] << " ";
    cout<<endl;
    return 0;
}
