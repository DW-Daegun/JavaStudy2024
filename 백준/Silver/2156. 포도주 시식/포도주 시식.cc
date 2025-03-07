#include <iostream>
#include <vector>

using namespace std;

int max(int a,int b,int c){
    int ans = (a < b) ? b : a;
    if(ans < c)
        ans = c;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr;
    int n,ans=0;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(3,0));
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    if(n==1)
        cout<<arr[0];
    else if(n==2)
        cout<<arr[0]+arr[1];
    else if(n==3)
        cout<<max(arr[0]+arr[1],arr[0]+arr[2],arr[1]+arr[2]);
    else{
        dp[0][1] = arr[0];
        dp[1][0] = arr[0];
        dp[1][1] = arr[1];
        dp[1][2] = arr[0] + arr[1];
        dp[2][0] = dp[1][2];
        dp[2][1] = arr[0] + arr[2];
        dp[2][2] = dp[1][1] + arr[2];
        dp[3][0] = max(dp[2][0], dp[2][1], dp[2][2]);
        dp[3][1] = dp[1][2] + arr[3];
        dp[3][2] = arr[0] + arr[2] + arr[3];
        
        for(int i=4;i<n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
            dp[i][1] = max(dp[i-2][0] + arr[i],dp[i-2][1] + arr[i],dp[i-2][2] + arr[i]);
            dp[i][2] = max(dp[i-3][0] + arr[i] + arr[i-1],dp[i-3][1] + arr[i] + arr[i-1],dp[i-3][2] + arr[i] + arr[i-1]);
        }
        
        cout<<max(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
    }
    
    return 0;
}