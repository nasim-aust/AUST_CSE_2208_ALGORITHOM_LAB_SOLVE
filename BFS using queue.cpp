#include<bits/stdc++.h>
using namespace std;
int cost[10][10],i,j,k,n,visit[10],visited[10];
int main()
{
    queue < int > q;
    int m,v;
    cout <<"Enter number of vertex : ";
    cin >> n;
    cout <<"Enter number of edges : ";
    cin >> m;
    cout <<"Enter ages EDGES : \n";
    for(k=1;k<=m;k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }

    cout <<"Enter source vertex : ";
    cin >>v;
    cout <<"Traverse Order : \n";
    cout << v << " ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                q.push(j);
            }
        }
        v=q.front();
        cout<<v << " ";
        q.pop();
        k++;
        visit[v]=0; visited[v]=1;
    }
    return 0;
}
/*
Sample input output :
Enter number of vertex : 9
Enter number of edges : 9

Enter ages EDGES :
1 2
2 3
1 5
1 4
4 7
7 8
8 9
2 6
5 7
Enter source vertex : 1
Traverse Order :
1 2 4 5 3 6 7 8 9
*/
