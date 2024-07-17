void solve() {
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> turns(l);
    for (int i = 0; i < l; i++) {
        cin >> turns[i].first >> turns[i].second;
    }

    // Sort turns by time
    sort(turns.begin(), turns.end());

    int x = 0, y = 0;
    int curr_dir = 0; // 0 = +x, 1 = +y, 2 = -x, 3 = -y
    int last_time = 0;

    // Directions in (dx, dy) format
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (auto& turn : turns) {
        int ti = turn.first;
        int turn_direction = turn.second;

        // Move from last_time to ti
        x += dx[curr_dir] * (ti - last_time);
        y += dy[curr_dir] * (ti - last_time);

        // Update direction based on the turn
        if (turn_direction == 1) {
            curr_dir = (curr_dir + 3) % 4; // right turn
        } else {
            curr_dir = (curr_dir + 1) % 4; // left turn
        }

        last_time = ti;
    }

    // Move from last_time to N
    x += dx[curr_dir] * (n - last_time);
    y += dy[curr_dir] * (n - last_time);

    cout << x + y << endl;
}
