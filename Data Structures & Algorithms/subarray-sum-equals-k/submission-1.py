class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        counter = 0
        n = len(nums)
        prefix_sums = {0: 1}
        current_sum = 0
        
        for i in range(n):
            current_sum += nums[i]
            if (current_sum - k) in prefix_sums:
                counter += prefix_sums[current_sum - k]
            prefix_sums[current_sum] = prefix_sums.get(current_sum, 0) + 1
            
        return counter