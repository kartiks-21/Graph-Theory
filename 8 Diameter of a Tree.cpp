/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358

vector<int> v[10005];
vector<int> vis(10005,0);
vector<int> dis(10005,0);

void dfs(int s)
{
    vis[s] = 1;

    for(auto i:v[s])
    {
        if(!vis[i])
        {
            dis[i] = dis[s] + 1;
            dfs(i);
        }
    }
    
}

void solve ()
{
   int n,e;
   cin>>n>>e;

   for(int i=0;i<e;i++)
   {
       int x,y;
       cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);
   }

   dis[1] = 0;

   dfs(1);

   int res = 0;

   for(int i=1;i<=n;i++)
   {
       if(dis[i]>res)
       {
           res = i;
       }
   }
   cout<<endl;

   for(int i=1;i<=n;i++)
   {
       vis[i] = 0;
       dis[i] = 0;
   }

   dfs(res);
   int ans = 0;

   for(int i=1;i<=n;i++)
   {
       ans = max(ans,dis[i]);    
   }

   cout<<ans<<endl;

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}