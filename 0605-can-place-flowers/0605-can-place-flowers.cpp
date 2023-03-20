class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true; 
        int s=flowerbed.size();
        for(int i=0;i<s;i++){
         if((flowerbed[i]==0) && (i==0||flowerbed[i-1]==0) && (i==s-1||flowerbed[i+1]==0)){
             flowerbed[i]=1;
             n--;
             if(n==0)
                 return true;
         }
        }
        return false;
    }
};