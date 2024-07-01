/*
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int product;
        //looping through the array up to the third last element eventually to take the last 3 elements
        for(int i=0;i<n-2;i++){
            product=arr[i]*arr[i+1]*arr[i+2];
            //Checking if the product is odd or not 
            if(product % 2 == 1) return true;
        }
        return false;
    }
};
*/ 
//It can also be done by iterating over the array and counting till we get 3 odd consecutive nos.
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for (int num: arr){
            if(num%2!=0){
                count++;
                if(count==3)
                    return true;
                }
                 else count=0;
            }
                return false;
         }
};