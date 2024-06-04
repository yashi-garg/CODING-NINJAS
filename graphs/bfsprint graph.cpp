#include<bits/stdc++.h>
using namespace std;
void bfsprint(int **edges,int n,int source)
{
	queue<int> q;
	bool *vis=new bool[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=false;
	}
	q.push(source);
	vis[source]=true;
	while(q.empty()==false)
	{
	int x=q.front();
	q.pop();
	cout << x<<endl;
	for(int i=0;i<n;i++)
	{
		if(i==x)
		continue;
		if(edges[i][x]==1 && vis[i]!=true)
		{
		q.push(i);	
		vis[i]=true;
		}
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
	bfsprint(edges,n,0);
}