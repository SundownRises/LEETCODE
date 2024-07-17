class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)
    
        distinct_in_nums1 = list(set1 - set2)
    
        distinct_in_nums2 = list(set2 - set1)
    
        return [distinct_in_nums1, distinct_in_nums2]
