void solve()
{
    int n;
    cin >> n;
    vi coins(n);
    read(coins);
    for (int i = 0; i < n; i++)
    {
        if (coins[i] & 1)
        {
            cout << "first\n";
            return;
        }
    }
    cout << "second\n";
    return;
}
/*

According to the initial state of piles, we can have three cases: 



1) All piles have even number of coins:
If all the piles have even number of coins,
then from whichever piles the first player will remove the coins, the second player
will also remove from the same piles again leaving all the piles with even number
of coins. In this way, the second player will always be the one to remove the last 
coin(s). So, second player will always be the winner.
2) Some piles have even number of coins and some have odd number of coins:
In this case, the first player will remove one coin each from all the piles 
with odd number of coins leaving even number of coins in all the piles. Now,
from whichever piles the second player chooses to remove a coin, the first player 
will remove coins from the same piles leaving the second player with piles with 
even number of coins. So, the first player will always be the winner.
3) All piles have odd number of coins:
If all the piles have odd number of coins, then the first player will remove coins
from all the piles leaving all the piles with even number of coins. Now, again the
second player will have all the piles with even number of coins making the first player 
the winner. 
*/
