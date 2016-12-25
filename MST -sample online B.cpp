//algorithm lab MST online set -B
#include<bits/stdc++.h>
using namespace std;
//#define max(a,b)        (a>b)?a:b
vector< pair<int,pair<int,int> >  > Edge;
int M,N,d;
bool visited[1000001];
int pset[1000001];

int find(int V)
{
    if(pset[V] == V)
      return V;
   else
      return (pset[V] = find(pset[V]));
}
void union_find(int u,int v)
{
    pset[find(u)] = find(v);
}

bool comp(pair<int,pair<int,int> > edge1,pair<int,pair<int,int> >edge2)
{
    pair<int,int> p1;
    pair<int,int>p2;
    p1=edge1.second;
    p2=edge2.second;
    return p1.second<p2.second;
}
int kruskal()
{
    int lweight;
    int m;
    memset(visited,false,sizeof visited);
    sort(Edge.begin(),Edge.end(),comp);
    int totalcost=0;
    d=0;
    m=0;
    for(int i=0;i<Edge.size();i++)
    {
        pair<int,pair<int,int> > p=Edge[i];
        pair<int,int> q=p.second;
        int V1=p.first;
        int V2=q.first;
        if((find(V1)!=find(V2)))
        {
            //cout<<V1<<"-"<<V2<<":"<<q.second<<endl;
            d++;
            lweight=q.second;
            totalcost+=q.second;
            visited[i]=true;
            union_find(find(V1),find(V2));
            m = max(m,q.second);
        }
    }
    //cout<<"Total Cost: "<<totalcost<<endl;
    return lweight;
}

int main()
{
    int value1,value2,weight;
    while(scanf("%d %d",&N,&M)==2)
    {
        if(N==0&&M==0) break;
        Edge.clear();
        for(int i=0;i<N;i++)
        {
            pset[i]=i;
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d %d %d",&value1,&value2,&weight);
            Edge.push_back(make_pair(value1,make_pair(value2,weight)));
        }
        int totalcost=kruskal();
        if(d<N-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            cout<<totalcost<<endl;
        }
    }
    return 0;
}
