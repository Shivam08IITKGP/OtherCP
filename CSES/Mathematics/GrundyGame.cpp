vi ans;
int mex(vi &v)
{
    set<int> s;
    for (int i = 0; i < (int)v.size(); i++)
    {
        s.insert(v[i]);
    }
    for (int i = 0; i <= V; i++)
    {
        if (s.find(i) == s.end())
        {
            return i;
        }
    }
}
void preCalculate()
{
    ans = {0, 0, 0};
    for (int i = 3; i < 2000; i++)
    {
        vi v;
        for (int j = 1; 2 * j < i; j++)
        {
            v.pb(ans[j] ^ ans[i - j]);
        }
        ans.pb(mex(v));
    }
}

void solve()
{
    int n;
    cin >> n;
    if (n >= 2000)
    {
        cout << "first\n";
    }
    else
    {
        if (ans[n] > 0)
        {
            cout << "first\n";
        }
        else
        {
            cout << "second\n";
        }
    }
}
