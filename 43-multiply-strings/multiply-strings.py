class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        len1, len2 = len(num1), len(num2)
        result = [0] * (len1 + len2)
    
        for i in range(len1 - 1, -1, -1):
            for j in range(len2 - 1, -1, -1):
                product = int(num1[i]) * int(num2[j])
                p1, p2 = i + j, i + j + 1
            
                total = product + result[p2]
            
                result[p2] = total % 10
                result[p1] += total // 10
    
        result_str = ''.join(map(str, result)).lstrip('0')
    
        return result_str if result_str else "0"
