class Solution(object):
    def twoSum(self, nums, target):
        # Dictionary to store the value and its corresponding index
        num_map = {} 
        
        for i, num in enumerate(nums):
            complement = target - num
            
            # If the complement exists in our map, we found the pair
            if complement in num_map:
                return [num_map[complement], i]
                
            # Otherwise, add the current number and its index to the map
            num_map[num] = i
            
        return []
        