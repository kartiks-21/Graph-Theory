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
vector<pair<int,int>> a[200005];
vector<bool> vis(200005,0);
vector<int> dis(200005,0);
vector<int> in(200005,0);
vector<int> low(200005,0);
int timer = 1;

void dijkstra()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,inf);
    pq.push({0,1});
    dist[1] = 0;

    int par[1000] = {0};

    while(!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;

        pq.pop();

        for(auto edge:a[curr])
        {
            if(curr_d + edge.second < dist[edge.first])
            {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first],edge.first});
                par[edge.first] = curr;
            }
        }
    }

    int sn,dn;
    cin>>sn>>dn;  // path betwween two nodes

    int p = dn;

    while(p!=sn)     // path retrieval using parent trace
    {
        cout<<p<<" ";
        p = par[p];
    }

    cout<<sn<<endl;

    for(int i=1;i<=n;i++)  // shortest distances from a given source
    cout<<dist[i]<<" ";

}
 
void solve ()
{
   dijkstra();
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}