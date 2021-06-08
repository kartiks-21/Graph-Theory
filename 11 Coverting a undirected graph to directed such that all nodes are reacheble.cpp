/* Author Kartik Shukla */
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
vector<int> a[200005];
vector<bool> vis(200005, 0);
vector<int> in(200005, 0);
vector<int> low(200005, 0);
vector<pair<int,int>> pp;
int timer = 0;
int bridge;

void dfs(int v, int p)
{
    vis[v] = true;
    in[v] = low[v] = timer++;

    for (int to : a[v])
    {
        if (to == p)
            continue;

        if (vis[to])
        {
            low[v] = min(low[v], in[to]);
            if(in[v]>in[to])
            pp.push_back({v,to});

        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > in[v])
                bridge = 1;
            pp.push_back({v,to});
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1, -1);

    if(bridge)
    {
        cout<<0<<endl;
    }
    else
    {
        for(int i=0;i<pp.size();i++)
        cout<<pp[i].first<<" "<<pp[i].second<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}