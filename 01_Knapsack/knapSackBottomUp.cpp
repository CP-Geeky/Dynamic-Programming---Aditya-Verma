#include <bits/stdc++.h>  
using namespace std;
 
int maxProfit(vector<int> &wt, vector<int> &val, int n, int W){
    vector<vector<int>> dp(n+1, vector<int>(W+1));
    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<W+1 ; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<W+1 ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }  

    for(int i=1 ; i<n+1 ; i++){
        for(int j=1 ; j<W+1 ; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+ dp[i-1][j- wt[i-1]], dp[i-1][j]); 
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}
 
 
int main(){ 
    // #ifndef Pavan
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdin);
    // #endif
 

    // int n, W;
    // cout << "Number of elements: ";
    // cin >> n;
    // cout<<"The capacity of knapsack :";
    // cin >> W;
    
    // cout<<"Enter the weight array : ";
    // vector<int> wt(n);
    // for(int i=0 ; i<n ; i++) cin >> wt[i];
    // cout<<"Enter the value array : ";
    // vector<int> val(n);
    // for(int i=0 ; i<n ; i++) cin >> val[i]


    // vector<vector<int>> dp(n+1, vector<int>(W+1));
    // for(int i=0 ; i<n+1 ; i++){
    //     for(int j=0 ; j<W+1 ; j++){
    //         if(i==0 || j==0)
    //             dp[i][j] = 0;
    //     }
    // }

    // for(int i=0 ; i<n+1 ; i++){
    //     for(int j=0 ; j<W+1 ; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }    


    int n = 4;
    int W = 7;
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    cout << "Maximum Profit : " << maxProfit(wt, val, n, W) << endl;
}