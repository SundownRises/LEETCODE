class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"
    
        if num < 0:
            num += 2**32
    
        hex_chars = "0123456789abcdef"
        hex_result = []
    
        while num > 0:
            hex_result.append(hex_chars[num & 0xF])
            num >>= 4
    
        return ''.join(reversed(hex_result))
