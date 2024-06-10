const int N = 1e6 + 1;
int t[4 * N];
int a[N];
int pos[N];
//the places occupied are set to be t[i]=0 and unoccupied are set to be t[i]=1
//initially all unoccupied
//We start placing the paintings from the back.

void build(int left, int right, int ind)
{
    if (left == right)
    {
        t[ind] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(left, mid, ind * 2);
    build(mid + 1, right, ind * 2 + 1);
    t[ind] = t[2 * ind] + t[2 * ind + 1];
}

int query(int node, int left, int right, int k)
{
    if (left == right)
    {
        return left;
    }
    int mid = (left + right) / 2;
    // If number of ones in the left child is greater than or equal to k,
    // Then we recurse to the left child
    // Otherwise we recurse to the right child with the left k
    
    if (t[2 * node] >= k)
    {
        return query(2 * node, left, mid, k);
    }
    else
    {
        return query(2 * node + 1, mid + 1, right, k - t[2 * node]);
    }
}
void update(int node, int left, int right, int idx)
{
    if(left == right)
    {
        t[node] = 0;
    }
    else
    {
        int mid = (left + right) / 2;
        if(left <= idx and idx <= mid)
        {
            update(2*node, left, mid, idx);
        }
        else
        {
            update(2*node+1, mid+1, right, idx);
        }
        t[node] = t[2*node] + t[2*node+1];
    }
}
void solve()
{
    int n;
    cin >> n;
    build(1, n, 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        int x = query(1, 1, n, a[i]);
        pos[x] = i;
        update(1,1,n,x);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<pos[i]<<" ";
    }
    cout<<endl;
}
/*
5
1 2 1 4 3

i = 5
x = 3
Printing t = 
4 2 2 2 0 1 1 1 1 
i = 4
x = 5
Printing t = 
3 2 1 2 0 1 0 1 1 
i = 3
x = 1
Printing t = 
2 1 1 1 0 1 0 0 1 
i = 2
x = 4
Printing t = 
1 1 0 1 0 0 0 0 1 
i = 1
x = 2
Printing t = 
0 0 0 0 0 0 0 0 0 
3 1 5 2 4 

*/
