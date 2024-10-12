// Time Complexity - O(nlogn)
void solve()
{
    int n;
    cin >> n;
    vector<pair<ii, int>> a(n);
    fr(i, n)
    {
        cin >> a[i].F.F >> a[i].F.S;
        a[i].S = i;
    }

    vi ans(n, 0);

    sort(all(a));
    int last = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq; // Min-Heap to store the departure time and room number
    for (int i = 0; i < n; i++)
    {
        if (pq.empty() or pq.top().F >= a[i].F.F) 
          // Minimum Departure Time>=Current Arrival Time
        {
            last++;
            pq.push({a[i].F.S, last});
            ans[a[i].S] = last;
        }
        else
        {
            ii x = pq.top();
            pq.pop();
            pq.push({a[i].F.S, x.S});
            ans[a[i].S] = x.S;
        }
    }
    cout << last << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
