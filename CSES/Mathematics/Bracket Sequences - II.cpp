void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt_x = count(all(s), '(');
    int cnt_y = s.size() - cnt_x;
    if (n % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    int k = s.size(), c = 0, x = 0, y = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == ')')
            c--, y++;
        else if (s[i] == '(')
            c++, x++;
        if (c < 0)
        {
            cout << 0;
            return;
        }
    }
    int half_n = n / 2;
    vi F_(n + 1, 1), I(n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
        F_[i] = (F_[i - 1] * i) % N;
        I[i] = binpow(F_[i], N - 2, N);
    }
    if (cnt_x > half_n or cnt_y > half_n)
    {
        cout << 0;
        return;
    }
    // cout << half_n - cnt_x << " " << half_n - cnt_y << endl;
    // if half_n - cnt_x == 0 and half_n- cnt_y==0 then output 1
    if (half_n == cnt_x)
    {
        cout << 1;
        return;
    }
    int ans = (((F_[n - cnt_x - cnt_y] * I[half_n - cnt_x]) % N) * I[half_n - cnt_y]) % N;
    // subtracting invalid ways, taking more left brackets than right
    ans = (ans - (((F_[n - cnt_x - cnt_y] * I[half_n - cnt_x - 1]) % N) * I[half_n - cnt_y + 1]) % N + N) % N;

    cout << ans << endl;
}
