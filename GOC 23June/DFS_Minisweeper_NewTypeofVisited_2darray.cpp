int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve()
{
    int n, m, x;
    read(n, m, x);
    vector<string> g(n);
    read(g);
    int ans = 0;
    auto good = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m and g[i][j] == '1';
    };
    graph vis(n, vi(m, 0));
    function<void(int, int, int, int)> rec = [&](int i, int j, int curr, int tm) -> void
    {
        int t = (vis[i][j] == 0);
        vis[i][j]++;

        if (i == 0 and j == 0)
        {
            ans = max(ans, curr + t);
        }
        if (tm == 0)
        {
            vis[i][j]--;
            return;
        }
        for (int k = 0; k < 4; k++)
        {
            int xx = i + dx[k];
            int yy = j + dy[k];

            if (good(xx, yy))
            {
                rec(xx, yy, curr + t, tm - 1);
            }
        }
        vis[i][j] -= 1;
    };
    rec(0, 0, 0, x);
    cout << ans << endl;
}
