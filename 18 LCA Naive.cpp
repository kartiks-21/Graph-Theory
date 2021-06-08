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
int w[200005];
int timer = 1;

int par[100005];
int level[100005];

int find(int a)
{
    if(par[a] == -1)
    return a;
    else
    return par[a] = find(par[a]);
}

void union_(int a,int b)
{
    par[a] = b;
}

int lca(int a,int b)
{
    if(level[a]>level[b])
    {
        return lca(b,a);
    }

    int d = level[b] - level[a];

    while(d--)
    {
        b = par[b];
    }

    if(a == b)
    return a;

    while(par[a]!=par[b])
    {
        a = par[a];
        b = par[b];
    }

    return par[a];

}

void solve ()
{
   int n,m;
   cin>>n>>m;

   for(int i=1;i<=n;i++)
   par[i]=-1;

   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
       par[y] = x;
   }

   for(int i=1;i<=n;i++)
   {
       int a = i;
       int lvl = 0;
       while(par[a]!=-1)
       {
           lvl++;
           a = par[a];
       }
       level[i] = lvl;
   }

   int a,b;
   cin>>a>>b;

   cout<<lca(a,b)<<endl;

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}