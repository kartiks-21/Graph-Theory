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

struct edge
{
    int x,y,w;
};

void bellmanford()
{
    int n,m;
    cin>>n>>m;
    vector<edge> v(m);

    for(int i=0;i<m;i++)
    {
       cin>>v[i].x>>v[i].y>>v[i].w;
    }

    vector<int> dist(n+1,inf);

    dist[1] = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[v[j].x] < inf && dist[v[j].y] > dist[v[j].x] + v[j].w)
            {
                dist[v[j].y] = dist[v[j].x] + v[j].w;
            }
        }
    }

    for(int i=1;i<=n;i++)
    cout<<dist[i]<<" ";
    cout<<endl;
}
 
void solve ()
{
   bellmanford();
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
        solve();
    
    return 0;
}