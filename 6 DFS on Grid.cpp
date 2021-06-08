/* Author Kartik Shukla */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358

char a[1005][1005];
bool vis[1005][1005];
int n,m;
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isvalid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return false;
    
    if(vis[x][y])
    return false;

    return true;
}

void dfs(int i,int j)
{
    vis[i][j] = true;

	for(auto p: moves)
	{
		if(isvalid(i+p.first, j+p.second))
		{
			dfs(i+p.first, j+p.second);
		}
	}

}

int connected()
{
    int ans = 0;

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(!vis[i][j])
           {
               dfs(i,j);
               ans++;
           }
       }
   }

   return ans;
}

void solve ()
{
  
   cin>>n>>m;

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>a[i][j];
           if(a[i][j]=='#')
           {
               vis[i][j] = true;
           }
       }
   }


   cout<<connected()<<endl;


}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    
    return 0;
}