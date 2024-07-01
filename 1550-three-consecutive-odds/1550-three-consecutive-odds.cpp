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
