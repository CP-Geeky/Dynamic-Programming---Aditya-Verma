#include <bits/stdc++.h>  
using namespace std;
 
int maxProfit(vector<int> &wt, vector<int> &val, int n, int W){
    //Base condition
    if(n==0 || W==0)
        return 0;
    
    /**
     * *If the weight of the item is lesser than or equal to the weight of the item, then we have two options
     * *  include the item --> val[n-1] + maxProfit(wt, val, n-1, W - wt[n-1])
     * !  Not include the item --> maxProfit(wt, val, n-1, W - wt[n-1])
     
     * TODO: And we have to return the maxProfit so we will take maximum from include and exclude. i.e., max(include, exclude)
    */


    if(wt[n-1] <= W){
        return max(val[n-1] + maxProfit(wt, val, n-1, W - wt[n-1]),
                              maxProfit(wt, val, n-1, W));
    }else{
        /** 
         * *Else (means the weight of the item is greater than the capacity of the bag), then we can skip this item
         * * return maxProfit(wt, val, n-1, W);
        */
        return maxProfit(wt, val, n-1, W);
    }
}
 
 
int main(){ 

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