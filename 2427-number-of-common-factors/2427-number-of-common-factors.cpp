class Solution {
public:
    int commonFactors(int a, int b) {
        int minimum=min(a,b);
        int count=0;
        for(int i=1;i<=minimum;i++){
            if(a%i==0 && b%i==0)
                count++;
        }
        return count;
    }
};