//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        vector<long long int> dp (n+1,1);
        int mod = 1e9+7;
        
           for(int i=2; i<=n; i++)
             dp[i] = (dp[i-1]%mod + (i-1)*dp[i-2] % mod)% mod;
             
        
        return dp[n] % mod;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends