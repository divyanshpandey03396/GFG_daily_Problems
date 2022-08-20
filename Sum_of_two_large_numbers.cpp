//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        string out = "";
        int i = X.size() - 1, j = Y.size() - 1;
        
        int sum = 0;
        while(i >= 0 or j >= 0) {
            if(i >= 0) sum += (X[i] - '0');
            if(j >= 0) sum += (Y[j] - '0');
            
            
            int digit = sum % 10;
            out += to_string(digit);
            sum /= 10;
            i--, j--;
        }
        if(sum) out += to_string(sum);
        
        // remove leading zeroes
        while(out.back() == '0' and out.size() > 1)
            out.pop_back();
        reverse(out.begin(), out.end());
        return out;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends