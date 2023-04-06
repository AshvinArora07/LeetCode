class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res=max(res, (sum+i)/(i+1));
        }
        return res;
    }
};