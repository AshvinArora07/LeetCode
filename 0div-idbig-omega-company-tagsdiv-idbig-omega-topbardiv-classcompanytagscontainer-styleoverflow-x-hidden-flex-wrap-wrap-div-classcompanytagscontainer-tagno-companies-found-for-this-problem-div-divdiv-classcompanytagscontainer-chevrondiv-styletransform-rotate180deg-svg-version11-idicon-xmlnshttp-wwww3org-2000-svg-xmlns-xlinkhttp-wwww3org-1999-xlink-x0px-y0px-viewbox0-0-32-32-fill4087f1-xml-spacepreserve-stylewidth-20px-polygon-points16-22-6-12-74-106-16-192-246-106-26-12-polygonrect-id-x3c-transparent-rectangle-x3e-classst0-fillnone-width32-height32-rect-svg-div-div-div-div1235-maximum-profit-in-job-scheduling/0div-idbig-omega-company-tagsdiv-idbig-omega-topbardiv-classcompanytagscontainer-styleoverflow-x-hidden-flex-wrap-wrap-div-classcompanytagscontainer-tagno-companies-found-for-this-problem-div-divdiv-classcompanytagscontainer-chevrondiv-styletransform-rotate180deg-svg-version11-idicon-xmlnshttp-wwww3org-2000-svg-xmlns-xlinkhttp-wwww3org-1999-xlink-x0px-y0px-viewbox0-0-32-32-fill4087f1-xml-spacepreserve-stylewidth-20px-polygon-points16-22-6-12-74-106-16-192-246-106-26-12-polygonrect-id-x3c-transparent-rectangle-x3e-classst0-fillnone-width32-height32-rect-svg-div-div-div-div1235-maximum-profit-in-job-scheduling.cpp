class Solution {
public:
    int memo[50001];
    int n;
    //find the first job jiska starting point >= currentJob ka end point
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n-1;
        
        int result = n+1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(array[mid][0] >= currentJobEnd) { //we can take this task
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    
    int solve(vector<vector<int>>& array, int i) {
        if(i >= n)
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        int next  = getNextIndex(array, i+1, array[i][1]);
        
        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);
        
        return memo[i] = max(taken, notTaken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        
        memset(memo, -1, sizeof(memo));
        
        vector<vector<int>> array(n, vector<int>(3, 0)); //{s, e, p}
        
        for(int i = 0; i<n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        auto comp = [&](auto& vec1, auto& vec2) {
              return vec1[0] <= vec2[0];
        };
        
        //sort kardo according to sart time
        sort(begin(array), end(array), comp);
        
        return solve(array, 0);
    }
};