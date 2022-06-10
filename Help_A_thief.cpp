// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
         vector<pair<int,int>>v;
       for(int i=0;i<N;i++){
           v.push_back({B[i],A[i]});
       }
       int ans=0;
       sort(v.begin(),v.end());
       for(int i=v.size()-1;i>=0;i--){
           int a=v[i].second;
           int b=v[i].first;
           if(T>=a){
                T-=a;
                ans+=(a*b);
           }else if(T<a or T==0){
               ans+=(T*b);
               break;
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends