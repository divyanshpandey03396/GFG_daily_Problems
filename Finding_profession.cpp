// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 char profession(int level, int pos){
    int i = 1;
    while (i < pos) i <<= 1;
    return trans(pos, i) ? 'e' : 'd';
    
}   
bool trans(int pos, int mask){
    if (pos == 1) return true;
    while (mask >= pos) mask /= 2;
    return !trans(pos - mask, mask/2);
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends