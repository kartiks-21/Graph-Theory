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
vector<int> a[2005];
int level[1005];
const int maxn = 10;
int LCA[1005][maxn+1];

void dfs(int s,int lvl,int p)
{
    level[s] = lvl;
    LCA[s][0] = p;

    for(auto i:a[s])
    {
        if(i!=p)
        dfs(i,lvl+1,s);
    }
}

void init(int n)
{
	dfs(1 , 0 , -1);
 
	for(int i=1;i<=maxn;i++)
	{
		for(int j=1;j<=n;j++)
        {
		if(LCA[j][i-1] != -1)
		{
			int par = LCA[j][i-1];
			LCA[j][i] = LCA[par][i-1];
        
		}
     
        }
   
	}
    
}

int lca(int a,int b)
{
    if(level[a]>level[b])
    {
        return lca(b,a);
    }

    int d = level[b] - level[a];

    while(d>0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d-=(1<<i);
    }

    if(a == b)return a;

    for(int i=maxn;i>=0;i--)
    {
        if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i])
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

int getdistance(int a,int b)
{
    return level[a] + level[b] - 2*level[lca(a,b)];
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

   for(int i=1;i<=n;i++)
   {
       for(int j=0;j<=maxn;j++)
       {
           LCA[i][j] = -1;
       }
   }

   init(n);

   int q;
   cin>>q;

   while(q--)
   {
       int a,b;
       cin>>a>>b;
       cout<<getdistance(a,b)<<endl;
   }
    

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}