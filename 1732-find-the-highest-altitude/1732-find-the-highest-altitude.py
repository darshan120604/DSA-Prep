class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        pre = 0
        altitudes = []
        for num in gain:
            altitudes.append(pre)
            pre = pre + num
        altitudes.append(pre)
        return max(altitudes)
            
        