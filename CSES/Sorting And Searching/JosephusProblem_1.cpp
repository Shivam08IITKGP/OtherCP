void solve()
{
    int n;
    cin >> n;
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    bool flag = 0;
    while (!q.empty())
    {
        if (flag)
        {
            cout << q.front() << " ";
            q.pop();
            flag = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
            flag = 1;
        }
    }

}
