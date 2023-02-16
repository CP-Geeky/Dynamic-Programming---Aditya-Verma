#include<bits/stdc++.h>
using namespace std;

int countSubsetsWithGivenSum(vector<int> &arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (sum+1));
    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<sum+1 ; j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    for(int i=1 ; i<n+1 ; i++){
        for(int j=1 ; j<sum+1 ; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // for(int i=0 ; i<n+1 ; i++){
    //     for(int j=0 ; j<sum+1 ; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][sum];
}

int main(){
    vector<int> arr = {1, 2, 5};
    int sum = 5;

    cout << "The number of subsets with the given sum = " << countSubsetsWithGivenSum(arr, sum) << endl;
} 