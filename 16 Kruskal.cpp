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

struct edge
{
    int a;
    int b;
    int w;
};

edge ar[100005];
int par[100005];

bool comp(edge x,edge y)
{
    if(x.w<y.w)
    return true;
    else
    return false;
}

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

void solve ()
{
   int n,m;
   cin>>n>>m;

   for(int i=1;i<=n;i++)
   par[i]=-1;

   for(int i=0;i<m;i++)
   {
       int x,y,z;
       cin>>x>>y>>z;
       ar[i].a = x;
       ar[i].b = y;
       ar[i].w = z;
   }

   sort(ar,ar+m,comp);
   
   int sum = 0;

   for(int i=0;i<m;i++)
   {
       int x = find(ar[i].a);
       int y = find(ar[i].b);

       if(x!=y)
       {
           sum+=ar[i].w;
           union_(x,y);
       }
   }

   cout<<sum<<endl;

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve();
    
    return 0;
}