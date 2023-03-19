class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX;
        int s=nums.size();
        int sum=nums[0];
        int high=0,low=0; //keeping the window size--> 1
        while(low<s && high<s){
            //checking if the sum is greater or equal to target and calculating minimum length
            if(sum>=target){
                minlen=min(minlen,(high-low)+1);
                sum-=nums[low];
                low++;
            }
            else{
                high++;
                if(high<s)
                    sum+=nums[high];
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};