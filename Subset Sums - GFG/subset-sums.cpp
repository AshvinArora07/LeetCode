//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int> arr, int ind,int N,int sum,vector<int> &res){
        if(ind==N){
            res.push_back(sum);
            return;
        }
        solve(arr,ind+1,N,sum+arr[ind],res);
        solve(arr,ind+1,N,sum,res);
    }
    vector<int> subsetSums(vector<int> arr,int N){
        int sum=0;
        vector<int> res;
        solve(arr,0,N,sum, res);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends