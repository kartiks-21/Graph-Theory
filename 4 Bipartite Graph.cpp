/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358

vector<int> v[10005];
vector<int> vis(10005,0);
vector<int> dis(10005,0);
vector<int> g(10005,0);
vector<int> c(10005,0);

bool dfs(int s,int cl)
{
    vis[s] = 1;
    c[s] = cl;

    for(auto i:v[s])
    {
        if(!vis[i])
        {
            if(dfs(i,cl^1)==false)
            {
                return false;
            }
        }
        else
        {
            if(c[s] == c[i])
            {
                return false;
            }
        }
    }

    return true;
    
}

void solve ()
{
   int n,e;
   cin>>n>>e;

   for(int i=0;i<e;i++)
   {
       int x,y;
       cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);
   }

   if(dfs(1,1))
   {
       cout<<"Bipartite Graph"<<endl;
   }
   else
   {
       cout<<"Not a Bipartite Graph"<<endl;
   }

}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}