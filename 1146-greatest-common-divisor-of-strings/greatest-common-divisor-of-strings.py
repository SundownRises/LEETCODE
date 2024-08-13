class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcd_length = math.gcd(len(str1), len(str2))
    
        candidate = str1[:gcd_length]
    
        if candidate * (len(str1) // gcd_length) == str1 and candidate * (len(str2) //  gcd_length) == str2:
            return candidate
        else:
            return ""