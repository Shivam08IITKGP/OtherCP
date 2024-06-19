vector<bool> supermask(V), submask(V);

void insert_super(int a)
{
    if (supermask[a])
        return;

    supermask[a] = true;

    for (int i = 0;; i++)
    {
        if (((a >> i) & 1) == 0 and (a + (1 << i)) < V)
        {
            insert_super(a + (1 << i));
        }
        else if ((a + (1 << i)) > V)
        {
            return;
        }
    }
}
void insert_sub(int a)
{
    if (submask[a])
    {
        return;
    }
    submask[a] = true;

    for (int i = 0;; i++)
    {
        if (((a >> i) & 1) and (a - (1 << i)) >= 0)
        {
            insert_sub(a - (1 << i));
        }
        else if ((a - (1 << i)) < 0)
        {
            return;
        }
    }
}

void solve()
{
    vi present(20, 0);
    int n, q;
    read(n, q);
    int x;
    while (n--)
    {
        cin >> x;
        insert_super(x);
        insert_sub(x);
    }
    while (q--)
    {
        cin >> x;
        if (supermask[x] or submask[x])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
