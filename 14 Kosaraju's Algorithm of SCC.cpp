/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
#define inf 1e9
#define INF 1e18
vector<int> a[200005];
vector<int> tr[200005];
vector<bool> vis(200005,0);
vector<int> dis(200005,0);
vector<int> in(200005,0);
vector<int> out(200005,0);
vector<int> low;
vector<int> scc;
int timer = 1;

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
    low.push_back(s);
}

void dfs1(int s)
{
    vis[s] = true;

    for(auto i:tr[s])
    {
        if(!vis[i])
        {
            dfs1(i);
        }
    }

    scc.push_back(s);

}

void solve ()
{
   int n,m;
   cin>>n>>m;

   for(int i=0;i<=n;i++)
   {
       vis[i] = false;
       a[i].clear();
       tr[i].clear();
   }

   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
       a[x].push_back(y);
       tr[y].push_back(x);
   }

   for(int i=1;i<=n;i++)
   {
       if(!vis[i])
       {
           dfs(i);
       }
   }

   for(int i=1;i<=n;i++)
        vis[i] = false;

    for(int i=1;i<=n;i++)
    {
        if(!vis[low[n-i]])
        {
            scc.clear();
            dfs1(low[n-i]);
            for(int i=0;i<scc.size();i++)
                cout<<scc[i]<<" ";
            cout<<endl;
        }
    }

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}