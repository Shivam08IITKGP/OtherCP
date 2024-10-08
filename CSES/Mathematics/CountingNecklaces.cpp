void solve()
{
    int n, m;
    cin>>n>>m;
    int ans = 0;
    // burnside's lemma
    // no. of objects = avg. no of symmetrical pictures over all symmetries.
    for(int i=0;i<n;i++)
    {
        ans = (ans + binpow(m , __gcd(i, n), N))%N;
    }
    ans = ans* binpow(n, N-2, N);
    ans %= N;
    cout<<ans<<endl;
}
