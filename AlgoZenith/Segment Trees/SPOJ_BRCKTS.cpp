int n;
const int N = 100005;
char arr[N];
struct Node
{
    int open, close;
};
struct Node merge(Node left, Node right)
{
    int match = min(left.open, right.close);
    left.open -= match;
    right.close -= match;
    return {left.open + right.open, left.close + right.close};
}
 
struct Node tree[4 * N];
 
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    function<void(int, int, int)> build = [&](int node, int l, int r)
    {
        if (l == r)
        {
            tree[node].open = (arr[l] == '(') ? 1 : 0;
            tree[node].close = (arr[l] == ')') ? 1 : 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    };
 
    build(1, 0, n - 1);
 
    function<void(int, int, int, int)> update = [&](int node, int ql, int qr, int pos)
    {
        if (pos < ql || pos > qr)
        {
            return;
        }
        else if (ql == qr)
        {
            tree[node].open ^= 1;
            tree[node].close ^= 1;
            return;
        }
        int mid = (ql + qr) / 2;
        update(2 * node, ql, mid, pos);
        update(2 * node + 1, mid + 1, qr, pos);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    };
 
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            if (tree[1].open == 0 && tree[1].close == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            update(1, 0, n - 1, type - 1);
        }
    }
}
