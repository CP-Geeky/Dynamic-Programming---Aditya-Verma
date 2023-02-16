#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> &arr, int sum){
    int n = arr.size();
    if(sum&1) return false;
    sum/=2;
    vector<vector<bool>> dp(n+1, vector<bool> (sum+1));
    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<sum+1 ; j++){
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }
    for(int i=1 ; i<n+1 ; i++){
        for(int j=1 ; j<sum+1 ; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    vector<int> arr = {1, 5, 11, 6};
    int sum = 0;
    for(int i=0 ; i<arr.size() ; i++)
        sum += arr[i];
    
    if(isSubsetSum(arr, sum)) cout << "Yes we can do the equal partition" << sum << endl;
    else cout << "No, we can't do the equal partition" << endl;
} 