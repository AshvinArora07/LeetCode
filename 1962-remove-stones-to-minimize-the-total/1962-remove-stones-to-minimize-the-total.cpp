class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto x: piles) pq.push(x);
        while(k--){
            int x=pq.top();
            pq.pop();
            x=x-x/2;
            pq.push(x);
        }
        int ans=0;
        while(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};