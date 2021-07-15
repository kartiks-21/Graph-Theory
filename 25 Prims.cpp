/* Author Kartik Shukla */
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
#define inf 1e9
#define INF 1e18

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a[n + 1];

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        a[x].push_back({y, w});
        a[y].push_back({x, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 1;
    vector<int> dis(n + 1, inf);
    vector<int> par(n + 1, -1);
    vector<bool> inMST(n + 1, false);

    pq.push(make_pair(0, src));
    dis[src] = 0;

    int wt = 0;

    while (!pq.empty())
    {

        int u = pq.top().second;
        int du = pq.top().first;

        //cout << u << " " << du << endl;
        pq.pop();

        if (inMST[u] == true)
        {
            continue;
        }

        inMST[u] = true;

        for (auto i : a[u])
        {

            int v = i.first;
            int weight = i.second;

            if (inMST[v] == false && dis[v] > weight)
            {
                dis[v] = weight;
                pq.push(make_pair(dis[v], v));
                par[v] = u;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}