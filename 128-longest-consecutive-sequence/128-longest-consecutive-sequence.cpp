class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==0)
            return 0;
        int currlen=1;
        int max_len=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                currlen++;
                max_len=max(max_len,currlen);
            }
            else if(nums[i]==nums[i-1])
                continue;
            else
                currlen=1;
            
    }
        return max_len;
    }
};