void solve()
{
    int n, x;
    read(n, x);
    vi a(n);
    read(a);

    int i = 0, j = n - 1;
    vi used(n, 0);
    int ans = 0;
    sort(all(a));
    while (i < j)
    {
        if (a[i] + a[j] > x)
        {
            j--;
        }
        else
        {
            used[i] = 1;
            used[j
              ] = 1;
            i++;
            j--;
            ans++;
        }
    }
    // cout<<used;
    cout << ans + count(all(used), 0);
}

// It is written in the problem that only 1 or two children can go in a gondola
// So that's why we are using pairing up
// I used lowerBound to find the x- a[i] partner, which apparently is not working 
// Because suppose you have repeating elements, then you will have trouble applying this 
// Operation in lower_bound code->
//        if (a[i] + a[j] > x)
//        {
//            j--;
//        }
