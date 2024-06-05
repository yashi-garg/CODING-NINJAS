#include <iostream>
#include<vector>
using namespace std;
vector<int> path(int **edges,int n,int s,int e,bool *vis)
{
    vector<int> v;
    if(e==s)
    {
        v.push_back(e);
        //v.push_back(s);
        return v;
    }
    vis[s]=true;
    for(int i=0;i<n;i++)
    {
        if(i==s)
        continue;
        if(edges[i][s]==1 && vis[i]!=true)
        {
            vector<int> res=path(edges, n, i, e, vis);
          if(res.empty()==false)
          {
              res.push_back(s);
              return res;
          }
        }
    }
    return v;
}
int main() {
    // Write your code here
    int n,e;
    cin >> n>>e;
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
    bool *vis=new bool[n];
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
    }
    int a,b;
    cin >> a>>b;

vector<int> res=path(edges, n, a, b, vis);
if(res.empty()==false)
{
    for(int i=0;i<res.size();i++)
    {
        cout << res[i]<<" ";
    }
}
//deletion
for(int i=0;i<n;i++)
{
    delete [] edges[i];
}
delete [] edges;
delete [] vis;
}