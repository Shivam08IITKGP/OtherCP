#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
vector<string> snow(4000);
vector<vector<int>> dp(4000, vector<int>(4000, 0));

bool inside(int x, int y, int h, int w)
{
    return x >= 0 && x < h && y >= 0 && y < w && snow[x][y] != '.';
}

void solve()
{
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> snow[i];
    int ans = 1;
    deque<pair<int, int>> q;
    dp[0][0] = 1;
    q.push_front({0, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop_front();
        int x = p.first;
        int y = p.second;
        // cout<<x<<" "<<y<<endl;
        ans = max(ans, dp[x][y]);
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // if(inside(nx,ny,h,w))
            //     cout<<"hello\n";
            if (inside(nx, ny, h, w) and dp[nx][ny] == 0)
            {
                // cout<<"Here\n";
                if (snow[nx][ny] == snow[x][y])
                {
                    dp[nx][ny] = dp[x][y];
                    q.push_front({nx, ny});
                }
                else
                {
                    // cout<<"here\n";
                    dp[nx][ny] = dp[x][y] + 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
