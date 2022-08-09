//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
void sieve(vector<bool> &isPrime, int n) {
        for(long long i=2; i<=sqrt(n); i++) {
            if(isPrime[i]) {
                for(long long p=i*i; p<=n; p+=i) {
                    isPrime[p]=0;
                }
            }
        }
    }
    
    long long count(long long n, long long limit, vector<long long> &primes) {
        long long l=0, h=n-1, ans=n;
        while(l<=h) {
            long long mid=l+(h-l)/2;
            if(primes[mid]<=limit) {
                l=mid+1;
            }
            else {
                h=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
    
public:
    long long int nineDivisors(long long int n){
        long long m=sqrt(n)/2;
        vector<bool> isPrime(m+1, 1);
        sieve(isPrime, m);
        vector<long long> primes;
        for(long long i=2; i<=m; i++) {
            if(isPrime[i]) {
                primes.push_back(i);
            }
        }
        long long p=primes.size(), ans=0;
        
        for(long long i=p-1; i>=0; i--) {
            long long limit=floor(sqrt(n*1.0)/primes[i]);
            ans+=count(i, limit, primes);
        }
        
        for(long long i=0; i<p; i++) {
            long long sq=primes[i]*primes[i];
            if(pow(sq, 4)<=n) {
                ans++;
            }
            else {
                break;
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
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends