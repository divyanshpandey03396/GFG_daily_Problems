// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int bitcountA = __builtin_popcount(a);
       int bitcountB = __builtin_popcount(b);
       if(bitcountA > bitcountB){
           int cnt = 0, ans = 0;
           for(int i = 31; i >= 0 && cnt < bitcountB; i--){
               if(a & (1 << i)){
                   ans ^= (1<<i);
                   cnt++;
               }
           }
           return ans;
       }
       else if(bitcountA < bitcountB){
           int cnt = 0, ans = a;
           for(int i = 0; i < 32 && cnt < bitcountB - bitcountA; i++){
               if((a & (1 << i)) == 0){
                   ans |= (1 << i);
                   cnt++;
               }
           }
           return ans;
       }
       else{
           return a;
       }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends