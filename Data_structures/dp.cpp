#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>


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
        return helperminCost(n , height,dp);
    }

    int finduniquePaths(int i , int j , vector<vector<int>> &dp ){
	if(i == 0 && j == 0){
		return 1;
	}


	if(i < 0 || j < 0){
		return 0;
	}


	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int up = finduniquePaths(i - 1 , j,dp);
	int left = finduniquePaths(i , j - 1,dp);


	return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m , vector<int>(n , 0));

	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i == 0 && j == 0){
				dp[i][j] = 1;
			}else{

				int up = 0;
				int left = 0;
					if(i > 0) up = dp[i-1][j];
					if(j > 0) left = dp[i][j-1];

					dp[i][j] = up + left;
			}

		}
	}


	return dp[m-1][n-1];

	
}



const int MOD = 1e9 + 7;

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1) {
                dp[i][j] = 0; 
            
            }else if(i == 0 && j == 0) {
                dp[i][j] = 1; 

            }else {
            int up = 0, left = 0;
            if (i > 0) up = dp[i - 1][j];
            if (j > 0) left = dp[i][j - 1];

            dp[i][j] = (up + left) % MOD;
        }
    }

    return dp[n - 1][m - 1];
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

    return 0;
}