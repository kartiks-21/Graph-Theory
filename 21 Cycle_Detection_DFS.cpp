/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
vector<int> a[20005];
vector<bool> vis(20005,0);
vector<int> cl(20005,0);

//Back edge is an edge connecting a node to it's ancestor which is not it's parent
//Presence of back edge indicates presence of cycle and can be detected using dfs

bool isparent(int x,int y)
{
    for(auto i:a[x])
    {
        if(i == y)
        {
            return true;
        }
    }

    return false;
}

bool dfs(int s,int par)
{
    vis[s] = true;

    for(auto i:a[s])
    {
        if(!vis[i])
        {
            if(dfs(i,s) == true)
            return true;
        }
        else
        {
            if(i!=par)
            return true;
        }
    }
    return false;
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

   if(dfs(1,1))
   {
       cout<<"Cycle"<<endl;
   }
   else
   {
       cout<<"No Cycle"<<endl;
   }


}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}