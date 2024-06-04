//graphs dfs implementation coding ninjas
#include<bits/stdc++.h>
using namespace std;
//dfs of graph
void print(int **edges,int n,int source,bool *vis)
{
	cout << source<<endl;
	vis[source]=true;
	for(int i=0;i<n;i++)
	{
		if(i==source)
		continue;
		if(edges[i][source]==1)
		{
			if(vis[i])
			continue;
			print(edges,n,i,vis);
		}
	}
	
}
int main()
{
	int n,e;
	cin >> n>> e;
	//adjacency matrix
	int **edges=new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	//visited array
	bool *vis=new bool[n];
	
	for(int i=0;i<n;i++)
	{
		vis[i]=false;
	}
	//graph input
	for(int i=0;i<e;i++)
	{
		int s,f;
		cin >> s>>f;
		edges[s][f]=1;
		edges[f][s]=1;
	}
	//for printing
	print(edges,n,0,vis);
}