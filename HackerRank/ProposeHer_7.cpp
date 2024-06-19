int n;
vector<string> ans;

void build(string &str, int sum, int open)
{
    if (str.size() == 2 * n and sum == 0 and open == n)
    {
        ans.push_back(str);
        return;
    }
    if (str.size() >= 2 * n)
    {
        return;
    }
    str += '(';
    build(str, sum + 1, open + 1);
    str.pop_back();
    if (sum)
    {
        str += ')';
        build(str, sum - 1, open);
        str.pop_back();
    }
}

void solve()
{
    cin >> n;

    string t = "";

    build(t, 0, 0);

    cout << ans.size() << '\n';
    for (string str : ans)
    {
        cout << str << '\n';
    }
}
