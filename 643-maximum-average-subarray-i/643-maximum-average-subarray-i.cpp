class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        int start=0,end=0;
        int size=0;
        double maxval=INT_MIN;
        for(end=0;end<n;end++){
            sum+=nums[end];
            size=end-start+1;     //here we are calculating the size of the current window 
            if(size==k){         //now checking if our window size is equal to the given size k in the function 
                maxval=max(maxval,(sum/k));   //storing the maximum average for every window taken 
                sum-=nums[start];
                start++;
            }
        }
        return maxval;
    }
};