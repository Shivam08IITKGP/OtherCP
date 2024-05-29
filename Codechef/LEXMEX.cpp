// link -> https://www.codechef.com/problems/LEXMAX?tab=statement
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);

    sort(all(a));
    int res= a[n-1];
    vi ans;
    while(a.size())
    {
        int mx= 0;
        vi temp;
        for(auto i:a)
        {
            if((res&i)==res)
            {
                ans.pb(i);
            }
            else
            {
                mx= max(mx, res&i);
                temp.pb(i);
            }
        }
        a.clear();

        for(auto i:temp)
        {
            if((mx&i)==mx)
            {
                ans.pb(mx);
            }
            else
            {
                a.pb(mx&i);
            }
        }
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout << endl;
}
