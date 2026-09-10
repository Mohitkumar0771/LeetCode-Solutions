class Solution(object):
    def threeSum(self, nums):
        # Sort the array to easily handle duplicates and use two pointers
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n):
            # Skip duplicate elements for our first number (nums[i])
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # Use two pointers for the remaining array
            left = i + 1
            right = n - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total < 0:
                    # Sum is too small, move left pointer to increase the sum
                    left += 1
                elif total > 0:
                    # Sum is too large, move right pointer to decrease the sum
                    right -= 1
                else:
                    # We found a valid triplet!
                    result.append([nums[i], nums[left], nums[right]])
                    
                    # Skip any duplicate values for the second number (left pointer)
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    
                    # Skip any duplicate values for the third number (right pointer)
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                        
                    # Both pointers must move inward to find new combinations
                    left += 1
                    right -= 1
                    
        return result