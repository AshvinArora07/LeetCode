//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<bool> visited(leaves+1,false);
        int count=0;
        for(int j=0;j<N;j++){
            int frog=frogs[j];
            if(frog<=leaves && visited[frog]) continue;
            for(int i=frog;i<=leaves;i+=frog){
                visited[i]=true;
            }
        }
        for(int i=1;i<=leaves;i++){
            if(!visited[i])
                count++;
        }
        return count;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends