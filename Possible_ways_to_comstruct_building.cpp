// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    long long dp[100001]={-1};
    dp[0]=1;
    dp[1]=2,dp[2]=3;
    long mod=1000000007;
    for(int i=3;i<=N;i++)
    {
        dp[i]=(dp[i-2]+dp[i-1])%mod;
    }
    int ans=((dp[N])%mod*(dp[N]%mod))%mod;
    return ans%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends