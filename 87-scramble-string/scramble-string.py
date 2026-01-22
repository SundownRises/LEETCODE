class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        
        memo = {}
        
        def helper(s1, s2):
            if (s1, s2) in memo:
                return memo[(s1, s2)]
            
            if s1 == s2:
                memo[(s1, s2)] = True
                return True
                
            if sorted(s1) != sorted(s2):
                memo[(s1, s2)] = False
                return False
            
            n = len(s1)
            for i in range(1, n):
                # Case 1: no swap - s1[0:i] with s2[0:i] and s1[i:] with s2[i:]
                if helper(s1[:i], s2[:i]) and helper(s1[i:], s2[i:]):
                    memo[(s1, s2)] = True
                    return True
                
                # Case 2: swap - s1[0:i] with s2[n-i:] and s1[i:] with s2[:n-i]
                if helper(s1[:i], s2[n-i:]) and helper(s1[i:], s2[:n-i]):
                    memo[(s1, s2)] = True
                    return True
            
            memo[(s1, s2)] = False
            return False
        
        return helper(s1, s2)