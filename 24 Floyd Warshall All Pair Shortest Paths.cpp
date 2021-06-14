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
vector<pair<ll,ll>> a[200005];
vector<bool> vis(200005,0);
vector<int> dis(200005,0);
vector<int> in(200005,0);
vector<int> low(200005,0);
int timer = 1;
 
void solve ()
{
   int n,m,q;
   cin>>n>>m>>q;
   
   ll dp[n+1][n+1];

   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=n;j++)
       {
           if(i == j)
           {
               dp[i][j] = 0;
           }
           else
           {
               dp[i][j] = INF;
           }
       }
   }

   for(int i=0;i<m;i++)
   {
       ll x,y,w;
       cin>>x>>y>>w;

       dp[x][y] = min(dp[x][y],w);
       dp[y][x] = min(dp[y][x],w);
   }

   for(int k=1;k<=n;k++)
   {
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               if(dp[i][j] > (dp[i][k] + dp[k][j]) && (dp[k][j]!=INF && dp[i][k]!=INF))
               {
                   dp[i][j] = dp[i][k] + dp[k][j];
               }
           }
       }
   }

   while(q--)
   {
       int x,y;

       cin>>x>>y;
       
       if(dp[x][y] == INF)
       {
           cout<<-1<<endl;
           continue;
       }
       cout<<dp[x][y]<<endl;
   }

   


}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}