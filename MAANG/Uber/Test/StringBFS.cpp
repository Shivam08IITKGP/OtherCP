int solution(string dial, string passcode)
{
    int n = dial.size();
    queue<pair<ii, int>> q;
    // First pair represents the position of the passcode and the curr pos of dial
    // Second element represents the steps taken to reach the position of the passcode
    int steps = INT_MAX;
    q.push({{0, 0}, 0});
    while (!q.empty())
    {
        auto [pos, s] = q.front();
        q.pop();
        if (pos.first == passcode.size())
        {
            remin(steps, s);
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (dial[i] == passcode[pos.first])
            {
                q.push({{pos.first + 1, i}, s + min((i - pos.second + n) % n, (pos.second - i + n) % n) + 1});
            }
        }
    }
    return steps;
}
