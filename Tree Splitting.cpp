//time complexity O(n)
//tree splitting from sahani sir book -page 223
//algorithm 4.4 -TVS for special case of binary trees
#include<bits/stdc++.h>
#define size 1001
using namespace std;

int node, tree[size], d[size], w[size][size];

void TVS(int T,int delta)//delta is limit
{
	if(tree[T]!=0)//if the tree is not empty
    {
        if((2*T) >node) d[tree[T]]=0;//T is a leaf
        else
        {
            TVS(2*T,delta);
            //Delay of each vertex can only be computed if all of its child nodes delay is already completed.
			d[T] = max(d[T],(d[2*T]+w[T][2*T]));//compute the delay of vertex T,2*T is child
			//cout <<d[T]<<endl;
			if( ((2*T)+1)<=node )
			{
				TVS( ((2*T)+1) , delta );
				d[T] = max( d[T],( d[(2*T)+1]+w[T][(2*T)+1] ) );
				//cout <<d[T]<<endl;
			}
			//cout << ( d[T] + w[(T/2)][T] ) <<endl;//delay
		}
		//cout<<"Tree :"<<T<<" parent "<<T/2<<" weights "<<w[(T/2)][T]<<endl;
		if(tree[T]!=1 && ( d[T] + w[(T/2)][T] )>delta )//split condition,T/2 is parent
		{//tree[T] != 1 -> T is not the root
			cout<<"Splitting node : ";
			cout<<tree[T]<<endl;
		   d[T]=0;//if we do not 0 the delay of vertex T, there will be another splitting node
		}
	}
}

int main(){

	cin>>node;

	//given input from sahani sir book from the figure 4.2
	//15 nodes,10 nodes without 0
	tree[1]=1;
	tree[2]=2;
	tree[3]=3;
	tree[4]=0;
	tree[5]=4;
	tree[6]=5;
	tree[7]=6;
	tree[8]=0;
	tree[9]=0;
	tree[10]=7;
	tree[11]=8;
	tree[12]=0;
	tree[13]=0;
	tree[14]=9;
	tree[15]=10;

	//9 edges and their weights
	w[1][2]=w[2][1]=4;
	w[1][3]=w[3][1]=2;
	w[2][5]=w[5][2]=2;
	w[5][10]=w[10][5]=1;
	w[5][11]=w[11][5]=4;
	w[3][6]=w[6][3]=1;
	w[3][7]=w[7][3]=3;
	w[7][14]=w[14][7]=2;
	w[7][15]=w[15][7]=3;
	TVS(1,5);//delta 1 is 5(final),2 is 2,3 is 3,4 is 0,6 is 0
	//at the beginning starting from cell 1

	return 0;
}
/*
Sample input : 15
Sample output :
Splitting node : 4
Splitting node : 2
Splitting node : 6
*/
