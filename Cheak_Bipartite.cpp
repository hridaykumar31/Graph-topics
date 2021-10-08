#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fr1(i,n) for(int i=1;i<=n;i++)
#define fr0(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
# define M_PI  3.14159265358979323846
using namespace std;
int color[10000];
bool dfs(int u,vector<int>adj[],vector<bool>&vis)
{ 
    vis[u]=true;
    for(int v:adj[u])
    {
         if(!vis[v])
        {
            color[v]=!color[u];
            if(dfs(v,adj,vis)==false)
            {
                return false;
            }
        }
        else if(color[u]==color[v])
        {
            return false;
        }
    }
    return true;

}
int main() 
{ 
#ifndef ONLINE_JUDGE   
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);  
#endif
ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
cin>>n>>m;
vector<int>adj[10000];
vector<bool>vis(10000,false);
fr0(i,m)
{
  int a,b;
  cin>>a>>b;
  adj[a].push_back(b);
  adj[b].push_back(a);
}
color[1]=0;
if(dfs(1,adj,vis)==true)
{
    cout<<"graph is bipartite"<<endl;
}
else
{
    cout<<"graph is not bipartite"<<endl;
}

 return 0;    

}