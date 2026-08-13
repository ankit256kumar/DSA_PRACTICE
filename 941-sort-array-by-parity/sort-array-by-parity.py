class Solution(object):
    def sortArrayByParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s=0
        for i in range(0,len(nums)):
            if nums[s]%2 != 0 and nums[i]%2==0:
                nums[s],nums[i]=nums[i],nums[s]
                s+=1
            elif nums[s]%2==0:
                s+=1
            
                
        return nums
                 
        