#include <bits/stdc++.h>  
using namespace std;
 
int countOfSubsetSum(vector<int> &arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<sum+1 ; j++){
            if(i==0) dp[i][j] = 0;
            if(j==1) dp[i][j] = 1;
        }
    }

    for(int i=1 ; i<n+1 ; i++){
        for(int j=1 ; j<sum+1 ; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
 
 
int main(){ 
    // #ifndef Pavan
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdin);
    // #endif
 

    int n, diff;
    cout << "Size of an array: ";
    cin >> n;
    cout << "Difference : ";
    cin >> diff;
    cout<<"Enter the array elements : ";
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
    }

    int requiredSum = (diff + sum)/2;

    cout << "The number of subsets with the given difference is : " << countOfSubsetSum(arr, requiredSum) << endl;

}