#include<bits/stdc++.h>
#define INF 1e8
using namespace std;
int a[10][10],visited[10],n,cost=0;

int least(int c)
{
	int nc = INF;
	int min = INF,kmin;
	for(int i=0;i < n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
			if(a[c][i] < min)
			{
				min=a[i][c]+a[c][i];
				kmin=a[c][i];
				nc=i;
			}
	}
	if(min!=INF) cost+=kmin;
	return nc;
}

void mincost(int ver)
{
	int i,nver;
	visited[ver]=1;
	cout << ver+1 << "-->";
	nver = least(ver);
	if(nver == INF)
	{
		nver=0;
		cout << nver+1;
		cost+=a[ver][nver];
		return;
	}
	mincost(nver);
}

int main()
{

	cout << "Enter no of vertex : ";
	cin >> n;
	for(int i=0;i<n;i++)
	{
		printf("\nEnter Elements of Row : %d\n",i+1);
		for(int j=0;j < n;j++) cin >> a[i][j];
		visited[i]=0;
	}
	cout <<endl;
	cout << "The cost list is: " <<endl;
	for(int i=0;i<n;i++)
	{
	    cout <<endl;
		for(int j=0;j<n;j++) cout << a[i][j]<<" ";
	}
	cout <<endl;
	cout <<"The Path is: "<<endl;
	mincost(0);

	cout << endl;
	cout << "Minimum cost:";
	cout << cost;

	return 0;
}
/*
sample input output

Enter no of vertex : 4

Enter Elements of Row : 1
1 5 4 2

Enter Elements of Row : 2
2 1 5 4

Enter Elements of Row : 3
9 6 2 4

Enter Elements of Row : 4
7 5 3 4

The cost list is:

1 5 4 2
2 1 5 4
9 6 2 4
7 5 3 4
The Path is:
1-->4-->3-->2-->1
Minimum cost:13

*/
