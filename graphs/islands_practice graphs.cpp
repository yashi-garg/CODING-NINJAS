#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges,int n,int s,bool *vis)
{
vis[s]=true;
for(int i=0;i<n;i++)
{
    if(i==s)
    continue;
    if(edges[i][s]==1 && vis[i]==false)
    {
        dfs(edges,n,i,vis);
    }
}
}
int helper(int **edges,int n)
{
bool *vis=new bool[n];
for(int i=0;i<n;i++)
{
    vis[i]=false;
}
int c=1;
dfs(edges,n,0,vis);
for(int i=1;i<n;i++)
{
    if(vis[i]==false)
    {
        c++;
        dfs(edges,n,i,vis);
    }
}
delete [] vis;
return c;
}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
    }
    if(n==0)
    {
        cout <<0 <<endl;
        return 0;
    }
    //input
    for(int i=0;i<e;i++)
    {
        int s,f;
        cin >> s>>f;
        edges[s][f]=1;
        edges[f][s]=1;
    }
    //function
    int res=helper(edges,n);
    cout << res<<endl;
    //deletion
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
return 0;
}