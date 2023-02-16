#include <bits/stdc++.h>  
using namespace std;
 
int maxProfit(vector<int> &wt, vector<int> &val, int n, int W){
    if(n==0 || W==0)
        return 0;
    if(wt[n-1] <= W){
        return max(val[n-1] + maxProfit(wt, val, n-1, W - wt[n-1]),
                                        maxProfit(wt, val, n-1, W));
    }else{
        return maxProfit(wt, val, n-1, W);
    }
}
 
 
int main(){ 
    // #ifndef Pavan
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdin);
    // #endif
 

    int n, W;
    cout << "Number of elements: ";
    cin >> n;
    cout<<"The capacity of knapsack :";
    cin >> W;
    
    cout<<"Enter the weight array : ";
    vector<int> wt(n);
    for(int i=0 ; i<n ; i++) cin >> wt[i];
    cout<<"Enter the value array : ";
    vector<int> val(n);
    for(int i=0 ; i<n ; i++) cin >> val[i];
    
    cout << "Maximum Profit : " << maxProfit(wt, val, n, W) << endl;
}