import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
     nums =[-x for x in nums]
     heapq.heapify(nums)
     c=1
     while c<k:
        a=-heapq.heappop(nums)
        c+=1
     return -nums[0]
        