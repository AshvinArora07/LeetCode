class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int countflip=0,count1=0;
        for(auto str:s){
            if(str=='1')
                count1++;
            else{
                countflip++;
                countflip=min(countflip,count1);
            }
        }
        return countflip;
    }
};