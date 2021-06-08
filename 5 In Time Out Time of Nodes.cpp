/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
vector<int> a[20005];
vector<bool> vis(20005,0);
vector<int> cl(20005,0);
vector<int> in(20005,0);
vector<int> out(20005,0);
int timer = 1;

//Can be used to check if a node lies in the subtree of another node as
//if node x is in subtree of node s then
// in[x]>in[s]
// out[x]<out[s]

void dfs(int s)
{
    vis[s] = true;
    in[s] = timer++;
    for(auto i:a[s])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    out[s] = timer++;
    
}

void solve ()
{
   int n,m;
   cin>>n>>m;

   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
       a[x].push_back(y);
       a[y].push_back(x);
   }

   dfs(1);

   for(int i=1;i<=n;i++)
   {
       cout<<in[i]<<" ";
   }
   cout<<endl;
   for(int i=1;i<=n;i++)
   {
       cout<<out[i]<<" ";
   }

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}