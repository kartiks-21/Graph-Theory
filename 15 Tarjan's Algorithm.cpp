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
vector<bool> vis(200005,0);
vector<int> dis(200005,0);
vector<int> in(200005,0);
vector<int> low(200005,0);
vector<bool> onstack(200005,0);
stack<int> S; 
int timer = 1;
int scc = 0;

void tarjan(int s)
{
    vis[s] = true;
    in[s] = timer;
    low[s] = timer;
    timer++;
    S.push(s);
    onstack[s] = true;

    for(auto i:a[s])
    {
        if(vis[i])
        {
            if(onstack[i])
            low[s] = min(low[s],in[i]);
        }
        else
        {
            tarjan(i);
            if(onstack[i])
            low[s] = min(low[i],low[s]);

        }
    }

    if(low[s] == in[s])
    {
        scc++;
        while(1)
        {
            int u = S.top();
            S.pop();
            onstack[u] = false;
            if(u == s)
            break;
        }
    }

}
 
void solve ()
{
   int n,m;
   cin>>n>>m;
   low.clear();
   scc = 0;
   for(int i=1;i<=n;i++)
   {
       vis[i] = false;
       a[i].clear();
   }
   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
       a[x].push_back(y);
   }

   for(int i=1;i<=n;i++)
   {
       if(!vis[i])
       {
           tarjan(i);
       }
   }
   cout<<scc<<endl;
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