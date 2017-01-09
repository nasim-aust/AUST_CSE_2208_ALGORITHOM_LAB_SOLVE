#include<bits/stdc++.h>
#define pb      push_back
using namespace std;

vector < char > cost[10];
map < char,int> visit,visited;

int main()
{
    queue < char > q;
    int m,n;
    char v,i,j;
    cout <<"Enter number of vertex : ";
    cin >> n;
    cout <<"Enter number of edges : ";
    cin >> m;
    cout <<"Enter ages EDGES : \n";
    for(int k=1;k<=m;k++)
    {
        cin >>i>>j;
        cost[i].pb(j);
    }

    cout <<"Enter source vertex : ";
    cin >>v;
    cout <<"Traverse Order : \n";
    cout << v << " ";
    visited[v]=1;
    int k=1;
    while(k<n)
    {
        for(auto z:cost[v])
        {
            if(visited[z]!=1 && visit[z]!=1)
            {
                visit[z]=1;
                q.push(z);
            }
        }
        //t=q;
        v=q.front();
        cout<<v << " ";
        q.pop();
        //cout <<"nasim ";
        //for(int j=1; j<q.size(); j++)
            //cout << q[j] <<" ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}
/*
Sample input output :
Enter number of vertex : 9
Enter number of edges : 9

Enter ages EDGES :
A B
B C
A E
A D
D G
G H
H I
B F
E G
Enter source vertex : A
Traverse Order :
A B E D C F G H I
*/
