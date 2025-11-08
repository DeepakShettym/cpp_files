#include<iostream>
#include<vector>

using namespace std;

class   DP{
    // Tabulation 
    public : 
    int fib1(int n){

    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i -1] + dp[i - 2]; 
    }

    return dp[n];
    }

    // Space Optmisation

    int fib2(int n){
        int secprev = 0;
        int prev = 1;

        for(int  i = 2 ; i <= n ; i++){
            int curr = prev + secprev;
            secprev = prev;
            prev = curr;
        }

        return prev;
    }

        int helperminCost(int n , vector<int>& height,vector<int> &dp){
            if(n == 0){
                return 0;
            }
            
            if(dp[n] != -1){
                return dp[n];
            }
            
                int left = helperminCost( n - 1 , height,dp)  + abs(height[n] - height[n -1]);
            
            int right = INT_MAX;
            
            if(n > 1){
                
                right = helperminCost( n - 2 , height,dp)  + abs(height[n] - height[n -2]);
                
            }
            
            return dp[n] = min(left,right);
            
            
    }
    
    int minCost(vector<int>& height) {
       
        int n = height.size() - 1;
        vector<int> dp(height.size(), -1);
        return helper(n , height,dp);
    }


};


int main(){
    DP dp;

    int ans1 = dp.fib1(6);
    int ans2 = dp.fib2(6);

    

    cout << "ans 1 : " << ans1 << endl;

     cout << "ans 2 : " << ans2 << endl;

    /* ans 1 : 8
    ans 2 : 8 */
}