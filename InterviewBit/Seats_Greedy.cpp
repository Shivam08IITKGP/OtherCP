int Solution::seats(string A) {
    const int MOD = 1e7 + 3;
        vector<int> occupied_positions;

        // Collect the positions of 'x'
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 'x') {
                occupied_positions.push_back(i);
            }
        }

        if (occupied_positions.empty()) {
            return 0;
        }

        // Find the median position
        int median_index = occupied_positions.size() / 2;
        int median_position = occupied_positions[median_index];

        // Calculate the minimum number of moves
        int total_moves = 0;
        for (int i = 0; i < occupied_positions.size(); ++i) {
            int target_position = median_position - (median_index - i);
            total_moves = (total_moves + abs(occupied_positions[i] - target_position)) % MOD;
        }

        return total_moves;
}
