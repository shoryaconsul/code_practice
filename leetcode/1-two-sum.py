class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        D = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in D:
                return [i,D[comp]]
            elif nums[i] not in D:
                D[nums[i]] = i
        
        raise ValueError