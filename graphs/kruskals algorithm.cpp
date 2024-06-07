#include<iostream>
#include <algorithm>
using namespace std;
class edge{
	public:
		 int source;
		 int dest;
		 int weight;
};
bool compare(edge e1,edge e2)
{
	return e1.weight<e2.weight;
}
int findparent(int x, int *p)
{
	if(x==p[x])
	return x;
	
	int r=findparent(p[x],p);
	return r;
	
}
void kruskals(edge *input,int n,int e)
{
	//sort in increasing order
	sort(input,input+e,compare);
	//output array
	edge *output=new edge[n-1]; //we need n-1 edges in the final mst
	//parent array
	int *p=new int[n];
	for(int i=0;i<n;i++)
	{
		p[i]=i;
	}
	 int count=0;
	 int i=0;
	  while(count!=n-1)
	  {
	  	edge e1=input[i];
	  	
	  	int sparent=findparent(e1.source,p);
	  	int dparent=findparent(e1.dest,p);
	  	
	  	if(sparent !=dparent)
	  	{
	  		output[count]=e1;
	  		count++;
	  		
	  		//updating the parent
	  		p[sparent]=dparent;
		  }
		  i++;//moving iterator of input array
	  }//while over
	  
	  //printing the output
	  for(int i=0;i<n-1;i++)
	  {
	  	cout << output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
	  }
	
}
int main()
{
	int n,e;
	cin >> n>>e;
	edge *input=new edge[e];
	//input
	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cin >> s>>d >> w;
		input[i].source=s;
		input[i].dest=d;
		input[i].weight=w;
	}
	
	kruskals(input,n,e);
	
}