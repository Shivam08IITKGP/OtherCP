#define n                        \
    {                            \
        cout << "-1 -1" << endl; \
        return;                  \
    }
// By using the formula a^b + 2(a&b)=a+b
//Keeping A= a&b and x= a^b
/*
If a bit is set in x and not in A, it means that it is set in one of a or b , so to minimise a, we set that in b.
If a bit is set in A and not in x, it means that it is set in both a and b.
If a bit is set neither in A nor in x, then it is not set in any of a or b.
If a bit is set in both A and x, then no such pair {a,b} exists.
*/
void solve()
{
    int s, x;
    read(s, x);
    if (s < x or (s - x) & 1)
    {
        n
    }
    int A = (s - x) / 2;
    // cout<<A<<endl;

    int a = 0, b = 0;

    for (int i = 0; i <= 31; i++)
    {
        int X = (A >> i) & 1;
        int Y = (x >> i) & 1;
        // cout << X << Y << endl;

        if (X == 1 and Y == 1)
        {
            n
        }
        else if (X == 1 and Y == 0)
        {
            a += (1LL << i);
            b += (1LL << i);
        }
        else if (X == 0 and Y == 1)
        {
            b += (1LL << i);
        }
        // cout<<" a = "<<a<<" b = "<<b<<endl;
    }
    cout << a << " " << b << endl;
}
