//Iterative
class Solution {
public:
    int climbStairs(int n) {
        int one=1;int two=1;int temp=0;
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        for(int i=2;i<=n;i++){                                                             // Iterative Approach
            temp=two;
            two=one+two;
            one=temp;
        }
        return two;
    }
};

// Recursion
class Solution {
public:
    int climbStairs(int n) {
        if(n<2)                                                                                        //Recursive Approach      
            return 1;
        return  climbStairs(n-1)+climbStairs(n-2); // from nth stair to the 0th stair                                                     
    }
};

//DP
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[1]=1;
        if(n>=2) dp[2]=2;                                                                                //DP approaach
        for(int i=3;i<=n;i++)  dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
