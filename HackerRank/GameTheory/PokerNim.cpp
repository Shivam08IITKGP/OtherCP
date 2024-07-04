/*
This problem is identical to standard nim game. If the current player is in
winning position and the opponent adds some chips, the current player can remove
those chips in his move and remain in winning position. As the current player can 
mirror his opponent's "add" move all the time, that move has no value.
Now you can find xorsum like standard nim game and determine who will win the game.
*/

void solve()
{
    int n,k;
    cin >> n >> k;
    vi a(n);
    read(a);
    int x = 0;
    fr(i, n)
    {
      x^=a[i];
    }
    if (x > 0)
    {
        cout << "First\n";
    }
    else
    {
        cout << "Second\n";
    }
}
