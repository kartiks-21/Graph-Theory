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
int LCA[100005][1000];

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

void dfs(int s,int p)
{
    LCA[s][0] = p;

    for(int i:a[s])
    {
        if(i!=p)
        dfs(i,s);
    }
}

void init(int n)
{
    dfs(1,-1);
    int maxn = log2(n);
    for(int j=1;j<=maxn;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(LCA[i][j-1]!=-1)
            {
                int par = LCA[i][j-1];
                LCA[i][j] = LCA[par][j-1];
            }
        }
    }
}

int lca(int a,int b,int n)
{
    if(level[a]>level[b])
    {
        return lca(b,a,n);
    }

    int maxn = log2(n);
    int d = level[b] - level[a];

    while(d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d-=(1<<i);
    }

    if(a == b)
    return a;

    for(int i=maxn;i>=0;i--)
    {
        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
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
       a[x].push_back(y);
       a[y].push_back(x);
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

   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=log2(n);j++)
       {
           LCA[i][j] = -1;
       }
   }

   for(int i=0;i<=n;i++)
        LCA[i][0] = i;

   init(n);

   cout<<lca(a,b,n)<<endl;

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}