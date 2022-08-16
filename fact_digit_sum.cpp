//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
vector<int> FactDigit(int n)
	{
	    vector<int>fact(10,1);
	    vector<int>ans;
	    for(int i=2;i<10;i++){
	        fact[i]=fact[i-1]*i;
	    }
	    for(int i=9;i>=1;i--){
	        if(fact[i]<=n){
	            n-=fact[i];
	            ans.push_back(i);
	            i++;
	        }
	        if(n==0){ 				   			   reverse(ans.begin(),ans.end());
	            return ans;
	        }
	    }
	    
	    return vector<int>();
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends