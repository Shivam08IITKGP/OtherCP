void solve()
{
    int n, q;
    cin >> n >> q;

    DisjointSet ds(n);
    int a, b;
    map<int, int> color_index;
    for (int i = 1; i <= n; i++)
    {
        color_index[i] = i;
    }
    map<int, int> index_color;
    for (int i = 1; i <= n; i++)
    {
        index_color[i] = i;
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b;
            int c_b = color_index[b];
            ds.parent[a] = c_b;
        }
        if (t == 2)
        {
            cin >> a >> b;
            swap(color_index[a], color_index[b]);
            swap(index_color[color_index[a]], index_color[color_index[b]]);
        }
        if (t == 3)
        {
            cin >> a;
            int c_a = ds.parent[a];
            cout << index_color[c_a] << endl;
        }
    }
}
