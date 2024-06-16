void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    map<char, int> freq;
    for (auto c : a)
    {
        freq[c]++;
    }
    if (b[0] == '0')
    {
        if (freq['0'] == n)
        {
            cout << -1 << endl;
            return;
        }
        string ans;
        for (auto &c : freq)
        {
            if (c.F > '0' && c.S > 0)
            {
                ans += c.F;
                c.S--;
                break;
            }
        }
        for(auto &c:freq)
        {
            while(c.S--)
            {
                ans+=c.F;
            }
        }
        cout << ans << endl;
        return;
    }
    int l = -1;
    for (int i = 0; i < n; i++)
    {
        for (auto &c : freq)
        {
            if (c.F > b[i] && c.S > 0)
            {
                l = i;
                break;
            }
        }

        if (freq[b[i]] > 0)
        {
            freq[b[i]]--;
        }
        else
            break;
    }
    if (l == -1)
    {
        cout << -1 << endl;
        return;
    }

    freq.clear();
    for (auto c : a)
    {
        freq[c]++;
    }
    string ans;
    for (int i = 0; i < l; i++)
    {
        ans += b[i];
        freq[b[i]]--;
    }
    for (auto &c : freq)
    {
        if (c.F > b[l] && c.S > 0)
        {
            ans += c.F;
            c.S--;
            break;
        }
    }

    for (auto &c : freq)
    {
        while (c.S--)
        {
            ans += c.F;
        }
    }
    cout << ans << endl;
    return;
}
