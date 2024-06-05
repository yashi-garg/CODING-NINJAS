#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int **edges,int n,int s,bool *vis,vector<int> &v)
{
v.push_back(s);
vis[s]=true;
for(int i=0;i<n;i++)
{
    if(i==s)
    continue;
    if(edges[i][s]==1 && vis[i]==false)
    {
        dfs(edges, n, i, vis, v);
    }
}
}
vector<vector<int>> helper(int**edges,int n)
{
bool *vis=new bool[n];
for(int i=0;i<n;i++)
{
    vis[i]=false;
}
vector<vector<int>> res;
vector<int> v;
dfs(edges, n, 0, vis, v);
sort(v.begin(),v.end());
res.push_back(v);
for(int i=1;i<n;i++)
{
    vector<int> v;
    if(vis[i]==false)
    {
        dfs(edges, n, i, vis, v);
        sort(v.begin(),v.end());
        res.push_back(v);
    }
}
delete [] vis;
return res;
}
int main() {
    // Write your code here
    int n, e;
    cin >>n >>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
    }
    for(int i=0;i<e;i++)
    {
        int s,f;
        cin >> s>>f;
        edges[s][f]=1;
        edges[f][s]=1;
    }
    vector<vector<int>> r1;
    r1=helper(edges, n);
    if(n==0)
    return 0;
    //printing the output
    int s=r1.size();
    for(int i=0;i<s;i++)
    {
        int l=r1[i].size();
        for(int j=0;j<l;j++)
        {
            cout << r1[i][j] <<" ";
        }
        cout << endl;
    }
    //deletion
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}