#include<bits/stdc++.h>
using namespace std;

int minimumSubsetSumDifference(vector<int> &arr){
    int n = arr.size();
    int sum =0;
    for(auto i:arr) {sum += i;}

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

    vector<bool> temp;
    for(int j=0 ; j<(sum+1)/2 ; j++){
        temp.push_back(dp[n][j]);
    }
    
    int diff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}


int main(){
    vector<int> arr = {1, 2, 7};
    cout << "The number of subsets with the given sum = " << minimumSubsetSumDifference(arr) << endl;
} 