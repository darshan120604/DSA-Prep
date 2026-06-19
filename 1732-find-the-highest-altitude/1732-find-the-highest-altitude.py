class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        pre = 0
        maxAlt = 0
        for num in gain:
            pre = pre + num
            maxAlt = max(maxAlt, pre)
        return maxAlt
            
        