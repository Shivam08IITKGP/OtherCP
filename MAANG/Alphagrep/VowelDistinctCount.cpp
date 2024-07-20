#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int countVowelSubstrings(const string &str)
{
    unordered_map<char, int> vowelCount;
    int n = str.size();
    int distinctVowel = 0;
    int ans = 0;
    int right = 0, left = 0;
    while (right < n)
    {
        if (isVowel(str[right]))
        {
            if (++vowelCount[str[right]] == 1)
            {
                distinctVowel++;
            }
            while (distinctVowel == 5)
            {
                ans += (n - right);
              // Why +(n-right)? 
              // from left to [right, right+1, right+2, ......n-1]
              // This adds up to n-right substrings
                if (--vowelCount[str[left]] == 0)
                {
                    distinctVowel--;
                }
                left++;
            }
        }
        else
        {
            distinctVowel = 0;
            for (char c : {'a', 'e', 'i', 'o', 'u'})
            {
                vowelCount[c] = 0;
            }
            left = 1 + right;
        }
        right++;
    }

    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout << countVowelSubstrings(s) << "\n";
    }
    return 0;
}
