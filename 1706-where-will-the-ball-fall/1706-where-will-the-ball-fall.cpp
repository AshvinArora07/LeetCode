class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
          int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);

        for(int ball=0; ball<m; ball++) {
            int i = 0, j = ball, f = 0;
            while(i < n) {
                if(grid[i][j] == 1) {
                    if(j == m - 1 || grid[i][j + 1] == -1) {f = 1; break;}
                    i++; j++;
                }
                else {
                    if(j == 0 || grid[i][j - 1] == 1) {f = 1; break;}
                    i++; j--;
                }
            }
            ans[ball] = f ? -1 : j;
        }
        return ans;
    }
};  