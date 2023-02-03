//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        vector<pair<int,int>> dir = { {0,1} , {1,0} , {0,-1}, {-1,0} };
        int i=0, j=0, k=0;
        int n = matrix.size();//row szie
        int m = matrix[0].size();// column size
        pair<int, int> ans;
        while(i>=0 && j>=0 && i<n && j<m){
            ans={i , j} ;
            if(matrix[i][j]==1){
                matrix[i][j]=0;
                k= (k+1)%4;
            } 
                i=i+dir[k].first;
                j=j+dir[k].second;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends