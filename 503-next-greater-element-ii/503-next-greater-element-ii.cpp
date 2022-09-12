class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        vector<int> v(n);
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() and s.top()<=nums[i%n]){
                s.pop();
            }
            if(s.empty())
                v[i%n]=-1;
            else
                v[i%n]=s.top();
            s.push(nums[i%n]);
        }
        return v;
    }
};