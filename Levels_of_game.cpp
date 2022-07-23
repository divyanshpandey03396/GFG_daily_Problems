//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int maxLevel(int h,int m)
       {
           // code here
           bool r1=true,r2=false,r3=false;
           int c=0;
           while(h && m){
               if(r1){
                   h+=3;
                   m+=2;
                   r1=false;
                   r2=true;
                   r3=true;
                   c++;
                   continue;
               }
               if(r2){
                   if(h>5 && m>10){
                   h-=5;
                   m-=10;
                   r1=true;
                   r2=false;
                   r3=true;
                   c++;
                   continue;
                   }
               }
               if(r3){
                   if(h>20){
                   h-=20;
                   m+=5;
                   r1=true;
                   r2=true;
                   r3=false;
                   c++;
                   continue;
                   }
                   else {
                       break ;
                   }
               }
           }
       return c;
       }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends