class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2==0)
                output[i]=output[i/2];
            else
                output[i]=output[i-1]+1;
        }
        return output;
        }
  
};
/*
0 - 0
1 - 001
2 - 010          Here we observe there are same no. of 1's in 2 and 4 & 3 and 6
3 - 011          i.e. the multiples have the same no. of 1's
4 - 100          And the number which is not divisible by 2 and gives remainder as 1
5 - 101          has an extra number of bit set i.e, in 4 there is one 1's and in 5 
6 - 110          which is not divisble by 2 and gives remainder 1 has an additional bitset 1.
7 - 111
8 - 1000
*/
