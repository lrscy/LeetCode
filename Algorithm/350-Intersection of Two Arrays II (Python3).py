class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ret = []
        mp1 = {}

        for i in nums1:
            if i not in mp1:
                mp1[i] = 1
            else:
                mp1[i] += 1;
        
        for i in nums2:
            if i in mp1 and mp1[i]:
                mp1[i] -= 1;
                ret.append( i );
        
        return ret;
