//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N) {
    // (N + 1) for 1 based indexing, taking rows and cols (in case they are different in some question)
    int rows = N + 1, cols = N + 1;
    
    vector<vector<bool>> visited (rows, vector<bool>(cols, false));
    
    // starting position
    visited[KnightPos[0]][KnightPos[1]] = true;
    
    queue<int> q;
    q.push(KnightPos[0] * cols + KnightPos[1]);
    
    //directions in which knight can move
    vector<vector<int> > dirs = {
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1},
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2}
    };
    
    int levels = 0;
    
    // BFS
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int currSquare = q.front(); q.pop();
            
            int currX = currSquare / cols;
            int currY = currSquare % cols;
            
            if(currX == TargetPos[0] && currY == TargetPos[1])
                return levels;
            
            // checking for next moves
            for(int k = 0; k < dirs.size(); ++k) {
                int nextX = currX + dirs[k][0];
                int nextY = currY + dirs[k][1];
                
                // checking for bounds
                if(nextX > 0 && nextX < rows && nextY > 0 && nextY < cols && visited[nextX][nextY] == false) {
                    q.push(nextX * cols + nextY);
                    visited[nextX][nextY] = true;
                }
            }
        }
        ++levels;
    }
    
    if(visited[TargetPos[0]][TargetPos[1]])
        return levels;
    
    return -1;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends