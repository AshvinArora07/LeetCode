class Solution {
public:
    int climbStairs(int n) {
        int one=1;int two=1;int temp=0;
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        for(int i=2;i<=n;i++){
            temp=two;
            two=one+two;
            one=temp;
        }
        return two;
    }
};