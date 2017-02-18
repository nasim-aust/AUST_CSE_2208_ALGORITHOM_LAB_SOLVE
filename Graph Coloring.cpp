#include<bits/stdc++.h>
using namespace std;

int G[50][50],x[50];
void color(int k)
{
    x[k]=1;  //coloring vertex with color1
    for(int i=0;i<k;i++)
    { //checking all k-1 vertices-backtracking
     if(G[i][k]!=0 && x[k]==x[i])  //if connected and has same color
        x[k]=x[i]+1;  //assign higher color than x[i]
    }
}

int main(){
    int n,e,k,m;
    cout <<"Enter no. of vertices : ";
    cin >> n;
    cout << "Enter no. of edges : ";
    cin >> e;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) G[i][j]=0;  //assign 0 to all index of adjacency matrix
    }

    cout <<"Enter indexes where value is 1-->" <<endl;
    for(int i=0;i<e;i++)
    {
        cin >> k >> m;
        G[k][m]=1;
        G[m][k]=1;
    }

    for(int i=0;i<n;i++) color(i);  //coloring each vertex

    cout <<"Colors of vertices -->" << endl;
    for(int i=0;i<n;i++)  //displaying color of each vertex
        printf("Vertex[%d] : %d\n",i+1,x[i]);

    return 0;
}


/*
Sample input Output


Enter no. of vertices : 4

Colored vertices of Graph G
Enter no. of edges : 5
Enter indexes where value is 1-->
0 1
1 2
1 3
2 3
3 0
Colors of vertices -->
Vertex[1] : 1
Vertex[2] : 2
Vertex[3] : 1
Vertex[4] : 3

*/
