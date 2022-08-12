//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n) {
    string cp = str;
    sort(begin(cp), end(cp));
    int small = -1, cap = -1;
    for(int x = 0; x < n; x++){
        if(cp[x] >= 'A' and cp[x] <= 'Z' and cap == -1){
            cap = x;
        }
        if(cp[x] >= 'a' and cp[x] <= 'z' and small == -1){
            small = x;
        }
    }
    for(auto &x: str){
        if(x >= 'A' and x <= 'Z'){
            x = cp[cap++];
        }else{
            x = cp[small++];
        }
    }
    return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends