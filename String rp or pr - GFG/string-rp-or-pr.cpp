//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    void pr(int x,int y , string S,long long& ans,bool flag){
        //Create a str stack to keep a track of when r ocurrs for a 'p'
        string str;
        for(char c:S){
            if(c=='r'){
                if(!str.empty() and str.back()=='p'){
                    ans+=x;
                    str.pop_back();// removing once "pr" is found
                }
                else{
                    str.push_back(c); // if no p found for a index before r then pushing r
                }
            }
            else 
                str.push_back(c);
        }
        if(flag)
            rp(x,y,str,ans,false);//if flag==true then call rp for the remaining   characters
    }
    void rp(int x,int y , string S,long long& ans,bool flag){
        //Create a str stack to keep a track of when p ocurrs for a 'r'
        string str;
        for(char c:S){
            if(c=='p'){
                if(!str.empty() and str.back()=='r'){
                    ans+=y;
                    str.pop_back();// removing once "rp" is found
                }
                else{
                    str.push_back(c); // if no r found for a index before p then pushing p
                }
            }
            else
                str.push_back(c);
        }
        if(flag)
            pr(x,y,str,ans,false);// if true then call pr for the remaining characters.
    }
    long long solve(int X,int Y,string S){
        long long ans=0;
      if(X>Y) 
        pr(X,Y,S,ans,true);
     else
        rp(X,Y,S,ans,true);
        
        
        return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends