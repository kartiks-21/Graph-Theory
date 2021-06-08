/* Author Kartik Shukla */
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
#define MOD 1000000007
#define PI 3.14159265358
int n, m;
char a[1005][1005];
vector<vector<pair<int, int>>> path;
vector<vector<bool>> vis;

int sx, sy, ex, ey;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isvalid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;

    if (vis[x][y])
        return false;

    return true;
}

void bfs(int x, int y)
{
    queue<pair<int,int>> q;
	q.push({sx,sy});
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(auto mv: moves)
		{
			int mvx = mv.first;
			int mvy = mv.second;
			if(isvalid(cx+mvx, cy+mvy))
			{
				q.push({cx+mvx, cy+mvy});
				vis[cx+mvx][cy+mvy] = true;
				path[cx+mvx][cy+mvy] = {mvx,mvy};
			}
		}
	}
}

void solve()
{

    cin >> n >> m;

    path.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; ++i)
    {
        path[i].resize(m);
        vis[i].resize(m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if (c == 'A')
            {
                sx = i;
                sy = j;
            }

            if (c == 'B')
            {
                ex = i;
                ey = j;
            }

            if (c == '#')
            {
                vis[i][j] = true;
            }
        }
    }

    bfs(sx, sy);

    if (!vis[ex][ey])
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
 
	vector<pair<int,int>> ans;
	pair<int,int> end = {ex,ey};
 
	while(end.first != sx or end.second != sy)
	{
		ans.push_back(path[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}
 
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		if(c.first == 1 and c.second ==0)
		{
			cout << 'D';
		}
		else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
		}
	}
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}