//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	   vector<int>res, temp; 
	    for(int i = n-1;  i >= 0; i--){
	        auto loc = lower_bound(temp.begin(),temp.end() , arr[i]) - temp.begin(); 
	        res.push_back(loc); 
	        temp.insert(temp.begin() + loc , arr[i]); // Storing in sorted order. 
	    }
	    reverse(res.begin(), res.end());
	    return res; 
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends