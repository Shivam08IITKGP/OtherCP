void dfs(vector<vector<char>>& board, int i, int j, int N, int M) {
    // Directions for moving up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Mark current cell as visited by flipping 'O' to 'Y'
    board[i][j] = 'Y';
    
    // Visit all adjacent cells
    for (int d = 0; d < 4; ++d) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        
        // Check if the adjacent cell is within bounds and is an 'O'
        if (ni >= 0 && ni < N && nj >= 0 && nj < M && board[ni][nj] == 'O') {
            dfs(board, ni, nj, N, M);
        }
    }
}
void Solution::solve(vector<vector<char> > &board) 
{
    int N = board.size();
    if (N == 0) return;
    int M = board[0].size();
    
    // Step 1: Traverse the boundaries and mark all 'O's connected to boundaries as 'Y'
    for (int i = 0; i < N; ++i) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0, N, M);
        }
        if (board[i][M - 1] == 'O') {
            dfs(board, i, M - 1, N, M);
        }
    }
    for (int j = 0; j < M; ++j) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j, N, M);
        }
        if (board[N - 1][j] == 'O') {
            dfs(board, N - 1, j, N, M);
        }
    }
    
    // Step 2: Traverse the entire board and flip 'O's to 'X' and 'Y's back to 'O'
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X'; // 'O' surrounded by 'X'
            } else if (board[i][j] == 'Y') {
                board[i][j] = 'O'; // Revert marked 'Y' back to 'O'
            }
        }
    }
}
// https://www.interviewbit.com/problems/capture-regions-on-board/
