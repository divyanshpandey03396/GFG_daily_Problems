//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isPrime(int n)
{
   if (n <= 1)
       return false;
   if (n == 2 || n == 3)
       return true;
   if (n % 2 == 0 || n % 3 == 0)
       return false;
   for (int i = 5; i <= sqrt(n); i = i + 6)
       if (n % i == 0 || n % (i + 2) == 0)
           return false;

   return true;
}
   int firingEmployees(vector<int> &arr, int n){
       // code here   
       vector<int> adj[n+1];
       int geek=0;
       for(int i=0;i<n;i++){
           if(arr[i]==0) {geek=i+1;continue;}
           adj[arr[i]].push_back(i+1);
       }

       queue<int> q;
       
       for(auto it:adj[geek]) q.push(it);
      
       int ans=0;
       int level=0;
       while(!q.empty()){
           int size=q.size();
           level++;
           for(int i=0;i<size;i++){
               int p=q.front();
               q.pop();
               
               if(isPrime(p+level)==true) ans++;
               
               for(int j:adj[p]){
                   q.push(j);
               }
           }
       }
       return ans;
   }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends