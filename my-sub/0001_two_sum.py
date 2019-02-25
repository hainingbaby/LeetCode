class Solution(object):
    def twoSum(self, nums, target):
        """
        时间复杂度：O(n)
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for i in xrange(len(nums)):
        	x = nums[i]
        	if target-x in dict:
        		return (dict[target-x],i)
        	dict[x] = i