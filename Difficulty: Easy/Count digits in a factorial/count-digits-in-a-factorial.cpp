//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int facDigits(int N){
        //code here
        if(N==0 || N==1){
            return 1;
        }
        
        double digitcount = 0;
        for(int i=2; i<=N; i++){
            digitcount += log10(i);
        }
        return floor(digitcount+1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.facDigits(n)<<"\n";
       
        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends