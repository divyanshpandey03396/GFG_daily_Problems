//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPossible(int x, int y, int mid, int R, int C, vector<vector<int>>& sum, int k){
        int x1 = x + mid, y1 = y + mid, x2 = x - mid, y2 = y - mid;
        int ones = sum[x1][y1];
        ones -= x2 - 1 >= 0 ? sum[x2 - 1][y1] : 0;
        ones -= y2 - 1 >= 0 ? sum[x1][y2 - 1] : 0;
        ones += (y2 - 1 >= 0 && x2 - 1 >= 0 )? sum[x2 - 1][y2 - 1] : 0;
        return ones <= k;
    }
  
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        vector<vector<int>> sum(R, vector<int>(C, 0));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                sum[i][j] = M[i][j];
            }
        }
        for(int i = 0; i < R; i++){
            for(int j = 1; j < C; j++){
                sum[i][j] += sum[i][j - 1];
            }
        }
        for(int j = 0; j < C; j++){
            for(int i = 1; i < R; i++){
                sum[i][j] += sum[i - 1][j];
            }
        }
        vector<int> ans;
        for(int i = 0; i < Q; i++){
            int x = q_i[i], y = q_j[i];
            int down = min(R - 1 - x, C - 1 - y), up = min(x, y);
            int low = 0, high = min(up, down);
            while(low <= high){
                int mid = low + (high - low)/2;
                if(isPossible(x, y, mid, R, C, sum, K)){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            if(high == -1) ans.push_back(0);
            else ans.push_back(1 + 2*high);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R,C,K,Q,x;
        cin>>R>>C;
        vector<vector<int>> M;
        
        for(int a=0; a<R; a++)
        {
            vector<int> temp;
            for(int b=0; b<C; b++)
            {
                cin>>x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }
        
        cin>>K>>Q;
        
        int q_i[Q], q_j[Q];
        
        for(int i=0; i<Q; i++)
            cin>>q_i[i];
        for(int i=0; i<Q; i++)
            cin>>q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M,R,C,K,Q,q_i,q_j);
        
        for(int i=0; i<Q; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends