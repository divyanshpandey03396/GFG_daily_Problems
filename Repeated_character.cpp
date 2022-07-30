//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
         int freq[26];
       int n  = s.size();
       memset(freq,0,sizeof(freq));
       for(int i = 0;i<n;i++)
         freq[s[i]-'a']++;
         int c = 0;
       for(int i = 0;i<n;i++){
       
           if(freq[s[i]-'a'] > 1){
               freq[s[i] - 'a'] = 0;
               c++;
               return s[i];
           }
           
       }  
       if(c==0)
        return '#';
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends