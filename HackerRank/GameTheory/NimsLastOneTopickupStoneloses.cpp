void solve() {
    int n;
    cin >> n;
    vi a(n);
    read(a);

    int x = 0;
    fr(i, n) 
    {
        x ^= a[i];
    }

    bool all_ones = all_of(a.begin(), a.end(), [](int i){ return i == 1; });
    //This is a extra edge case you must check
    if(all_ones) 
    {
        if(n % 2 == 0) 
        {
            cout << "First\n";
        } 
        else 
        {
            cout << "Second\n";
        }
    } 
    else {
        if(x != 0) 
        {
            cout << "First\n";
        } 
        else 
        {
            cout << "Second\n";
        }
    }
}
