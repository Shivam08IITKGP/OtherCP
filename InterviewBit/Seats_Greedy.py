class Solution:
	# @param A : string
	# @return an integer
    def seats(self, A):
        MOD = 10**7 + 3
        occupied_positions = [i for i, char in enumerate(A) if char == 'x']
        
        if not occupied_positions:
            return 0

        median_index = len(occupied_positions) // 2
        median_position = occupied_positions[median_index]

        total_moves = 0
        for i, pos in enumerate(occupied_positions):
            target_position = median_position - (median_index - i)
            total_moves = (total_moves + abs(pos - target_position)) % MOD

        return total_moves          
        
