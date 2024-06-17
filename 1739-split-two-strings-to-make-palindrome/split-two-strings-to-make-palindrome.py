class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def is_palindrome(s):
            return s == s[::-1]
        def check(a, b):
            i, j = 0, len(a) - 1
            while i < j and a[i] == b[j]:
                i += 1
                j -= 1
            return is_palindrome(a[i:j+1]) or is_palindrome(b[i:j+1])
    
        return check(a, b) or check(b, a)
        