class Solution(object):
    def getMaximumGold(self, grid):
        def dfs(r, c):
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == 0:
                return 0
        
            original_value = grid[r][c]
            grid[r][c] = 0
            max_gold = 0
        
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                max_gold = max(max_gold, dfs(r + dr, c + dc))
        
            grid[r][c] = original_value
            return max_gold + original_value
    
        max_gold_collected = 0
    
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] != 0:
                    max_gold_collected = max(max_gold_collected, dfs(r, c))
    
        return max_gold_collected

        