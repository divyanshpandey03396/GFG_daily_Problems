
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        // code here
         long long s = S;
        int idx = N;
        for(int i=0;i<N; i++){
            A[i] += s;
            s += A[i];
            if(s>X){
                idx = i;
                break;
            }
        }
        while(X >= 0 and idx >=0){
            if(X >= A[idx])
                X -= A[idx];
            if(X == 0 || X-S == 0)
                return 1;
            idx--;
        }
        return 0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  