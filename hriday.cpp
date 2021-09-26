#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fr1(i,n) for(int i=1;i<=n;i++)
#define fr0(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
# define M_PI  3.14159265358979323846
const int MOD=1e9+7;
 int timer=0;
int graph_color[10000];
int discover_time[1000];
int finish_time[10000];
using namespace std;
void dfs(int start,vector<int>adj[],vector<bool>&vis,vector<int>&store_path,vector<int>&store_path1)
{
     timer++;
     store_path.pb(start);
     vis[start]=true;
   discover_time[start]=timer;
   graph_color[start]=1;
  for(auto i:adj[start])
  {
       if(!vis[i])
       {
        //recursive call
           dfs(i,adj,vis,store_path,store_path1);
       }
  }
  finish_time[start]=++timer;
  graph_color[start]=2;
  //bracktrack from stack
  store_path1.pb(start);

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
   vector<int>adj[2*n];
   vector<bool>vis(n,false);
   vector<int>store_path,store_path1; 
    graph_color[0]=0;
    for(int i=0;i<m;i++)
   {
       int a,b;
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   //visiting all node from the graph
   for(int i=1;i<=n;i++)
   {
       if(!vis[i])
       {
              dfs(i,adj,vis,store_path,store_path1);
       }
   }
   cout<<endl;

   //DFS traverse in preorder & print path
   for(int i:store_path)
   {
       cout<<i<<endl;
   }
   cout<<endl;



   //print discover&finshing time
  for(int i=1;i<=n;i++)
  {
    cout<<i<<" "<<discover_time[i]<<" "<<finish_time[i]<<endl;
  }
   cout<<endl;



  //DFS traverse in postorder (also called topological sort when we print reverse order)
   for(int i:store_path1)
   {
       cout<<i<<endl;
   }
   cout<<endl;



   reverse(store_path1.begin(),store_path1.end());
   //TOPOLOGICAL sort using DFS
   for(int i:store_path1)
   {
       cout<<i<<endl;
   }





 return 0;    

}