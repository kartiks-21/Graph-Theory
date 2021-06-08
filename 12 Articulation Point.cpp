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
int timer = 1;

void dfs(int s,int p)
{
    vis[s] = true;
    in[s] = timer;
    low[s] = timer;
    timer++;
    int child = 0;
    for(auto i:a[s])
    {
        if(i == p)
        continue;

        if(vis[i])
        {
            low[s] = min(low[s],in[i]);
        }
        else
        {
            dfs(i,s);
            child++;
            low[s] = min(low[s],low[i]);
            if(low[i]>=in[s] && p!=-1)
            {
                cout<<s<<endl;
            }
        }
        
    }

    if(p == -1 && child>1)
    cout<<s<<endl;
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
   dfs(1,-1);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}