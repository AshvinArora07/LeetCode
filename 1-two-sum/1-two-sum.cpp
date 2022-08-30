class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int y=target-x;
            m[y]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()&& m[nums[i]]!=i)
                return {i,m[nums[i]]};
        }
        return {0,0};
    }
};