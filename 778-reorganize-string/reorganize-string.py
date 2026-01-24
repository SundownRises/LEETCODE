class Solution:
    def reorganizeString(self, s: str) -> str:
        from collections import Counter
        import heapq
        
        freq = Counter(s)
        
        max_heap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(max_heap)
        
        prev_count, prev_char = 0, ''
        result = []
        
        while max_heap:
            count, char = heapq.heappop(max_heap)
            result.append(char)
            
            if prev_count < 0:
                heapq.heappush(max_heap, (prev_count, prev_char))
            
            prev_count = count + 1
            prev_char = char
        
        return "".join(result) if len(result) == len(s) else ""
