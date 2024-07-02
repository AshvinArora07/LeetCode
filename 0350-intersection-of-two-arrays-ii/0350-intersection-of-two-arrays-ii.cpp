class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> result;
        int i=0,j=0;
        while(i<nums1.size() and j<nums2.size()){
            
            if(nums2[j]<nums1[i])
                j++;
            else if(nums2[j]>nums1[i])
                i++;
            else{
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return result;
    }
};