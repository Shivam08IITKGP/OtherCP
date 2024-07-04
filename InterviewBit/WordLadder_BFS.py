from collections import deque
class Solution:
    # @param A : string
    # @param B : string
    # @param C : list of strings
    # @return an integer
    def solve(self, A, B, C):
        word_set = set(C)
        queue = deque([(A,1)])
        visited = set(A)
        
        while queue:
            current_word, level = queue.popleft()
            if current_word==B:
                return level
            
            for i in range(len(current_word)):
                for char in 'abcdefghijklmnopqrstuvwxyz':
                    if char == current_word[i]:
                        continue
                    next_word = current_word[:i] + char + current_word[i+1:]
                    if next_word == B:
                        return level+1
                    if next_word in word_set and next_word not in visited:
                        visited.add(next_word)
                        queue.append((next_word, level+1))
                        
        return 0
                        
                                                
                
        
