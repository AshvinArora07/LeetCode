class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> m;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() &&st.top()<=nums2[i]){
                st.pop();   
            }
            if(st.empty())
                m[nums2[i]]=-1;
            else
                m[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for(auto &i:nums1){
            res.push_back(m[i]);
        }
       return res; 
    }
};