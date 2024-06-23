void solve()
{
    int n, m, q;
    read(n, m, q);
    vector<string> g(n);
    read(g);

    set<string> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            string temp = "";
            temp += g[i][j];
            temp += g[i][j + 1];
            s.insert(temp);
        }
        for (int j = 0; j < m - 2; j++)
        {
            string temp = "";
            temp += g[i][j];
            temp += g[i][j + 1];
            temp += g[i][j + 2];
            s.insert(temp);
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            string temp = "";
            temp += g[i][j];
            temp += g[i + 1][j];
            s.insert(temp);
        }
        for (int i = 0; i < n - 2; i++)
        {
            string temp = "";
            temp += g[i][j];
            temp += g[i + 1][j];
            temp += g[i + 2][j];
            s.insert(temp);
        }
    }

    while (q--)
    {
        string c;
        cin >> c;
        vi dp(c.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 0;
        for (int i = 2; i <= c.size(); i++)
        {
            if (dp[i - 2] and s.find(c.substr(i - 2, 2)) != s.end())
            {
                dp[i] = true;
            }
            else if (i >= 3 and (dp[i - 3] and s.find(c.substr(i - 3, 3)) != s.end()))
            {
                dp[i] = true;
            }
        }
        if (dp[c.size()])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
