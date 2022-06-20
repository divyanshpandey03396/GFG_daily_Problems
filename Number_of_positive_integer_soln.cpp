// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    int n;
    long res= 0;
public:
    void rec(int ind, int lastind, int target, string s){
        if(ind >= lastind){
            if(target == 0)     res++;
            return;
        }
        for(int i=1;i<=target;i++){
            rec(ind+2, lastind, target-i, s);
        }
    }
    long posIntSol(string s)
    {
        int i = s.length()-1, n = s.length();
        while(s[i] != '=')  i--;
        int k = stoi(s.substr(i+1, n-i-1));
        rec(0, i, k, s);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends