//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
           priority_queue<int , vector<int>,greater<int>> p;
       for(int i=0;i<n;i++){
           p.push(arr[i]);
       }
       
       int ans=0;
       while(!p.empty() && p.top()<k ){
           int x=p.top();
           p.pop();
           if(x< k){
               x=x+p.top();
               p.pop();
               p.push(x);
               ans++;
           }
       }
           return ans;
    }
   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends