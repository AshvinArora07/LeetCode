class Solution {
public:
    int arraySign(vector<int>& nums) {
        int plus=0,neg=0,zero=0;
        for(auto i:nums){
            if(i>0)
                plus++;
            else if(i<0)
                neg++;
            else
                return 0;
        }
        if((neg%2)!=0)
            return -1;
        else return 1;
    }
};