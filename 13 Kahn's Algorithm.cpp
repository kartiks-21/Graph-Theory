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
vector<int> ans;
int timer = 1;

void kahndfs(int s)
{
    vis[s] = true;

    for(auto i:a[s])
    {
        if(!vis[i])
        {
            kahndfs(i);
        }
    }

    ans.push_back(s);

}

void kahn(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    if(in[i] == 0)
    q.push(i);

    while(!q.empty())
    {
        int curr = q.front();
        ans.push_back(curr);
        q.pop();

        for(auto i:a[curr])
        {
            in[i]--;
            if(in[i] == 0)
            q.push(i);
        }
    }

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

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
       in[y]++;
   }

    for(int i=1;i<=n;i++)
    if(!vis[i])
    kahndfs(i);

    reverse(ans.begin(),ans.end());

   for(int i=0;i<ans.size();i++)
   cout<<ans[i]<<" ";
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
        solve();
    
    return 0;
}