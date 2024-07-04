from collections import defaultdict, deque

class Solution:
    # @param start : string
    # @param end : string
    # @param dictV : list of strings
    # @return a list of list of strings
    def findLadders(self, start, end, dictV):
        dictV = set(dictV)
        if end not in dictV:
            dictV.add(end)
        if end == start:
            return ([(start,)])
        queue = deque([[start]])
        visited = set([start])
        
        found = False
        ans = []
        
        while queue and not found:
            level_visit = set()
            for _ in range(len(queue)):
                current_path = queue.popleft()
                curr_word = current_path[-1]
                for i in range(len(curr_word)):
                    for char in 'abcdefghijklmnopqrstuvwxyz':
                        if char == curr_word[i]:
                            continue
                        
                        next_word = curr_word[:i] + char + curr_word[i+1:]
                        
                        if next_word == end:
                            ans.append(current_path + [next_word])
                            found = True
                        elif next_word in dictV and next_word not in visited:
                            level_visit.add(next_word)
                            queue.append(current_path + [next_word])
                            
            visited.update(level_visit)
            
        return ans
