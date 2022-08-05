//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
       vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
    bool isSafe(int i, int j, vector<vector<char>> &v, vector<vector<bool>> &vis) {
        if(i >= 0 && i < v.size() && j >= 0 && j < v[0].size() && !vis[i][j] && v[i][j] != 'O')
            return true;
        return false;
    }
    
    void cntShapes(int i, int j, vector<vector<char>> &v, vector<vector<bool>> &vis) {
        vis[i][j] = true;
    
        for(int k = 0; k < dir.size(); k++) {
            int x = i + dir[k].first;
            int y = j + dir[k].second;
    
            if(isSafe(x,y,v,vis)){
                cntShapes(x,y,v,vis);
            }
        }
    }

    int xShape(vector<vector<char>>& v) 
    {
        int n = v.size(), m = v[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
    
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 'X' && !vis[i][j]){
                    ans++;
                    cntShapes(i,j,v,vis);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends