void solve()
{
    int n;
    cin >> n;
    vi books(n);
    read(books);

    int longest_time = 2 * *max_element(all(books));
    int total_time = accumulate(all(books), 0LL);

    cout << max(total_time, longest_time) << endl;
}
