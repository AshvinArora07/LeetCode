class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1, v2;
        //This syntax is basically used to create a set and insert the values of a vector onto the set
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        
        //This syntax will basically eliminate the duplicate values present in set 1 by comparing both the sets by taking their difference and will push the values of set1 into the vector 1
        set_difference(s1.begin(), s1.end(),s2.begin(), s2.end(), back_inserter(v1));
        set_difference(s2.begin(),s2.end(), s1.begin(), s1.end(),back_inserter(v2));
        return {v1, v2};
    }
};