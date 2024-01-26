There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point 
in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:
1 <= m, n <= 100
====================================================================================================================================================================================================================================================
//MEMOIZATION SOLUTION

class Solution {
public:
    int countPaths(int m,int n,vector<vector<int>>& dp){
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return dp[0][0]=1;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=countPaths(m-1,n,dp)+countPaths(m,n-1,dp);
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countPaths(m-1,n-1,dp);
    }
====================================================================================================================================================================================================================================================
//TABULATION APPROACH  

int uniquePaths(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(i-1>=0){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=0) dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
====================================================================================================================================================================================================================================================
//TABULATION WITH SPACE OPTIMIZATION
 
    int uniquePaths(int m,int n){
       vector<int> dp(n,1);
       for(int i=1;i<m;i++){
           int prev = 0;
           vector<int> temp(n,0);
           for(int j=0;j<n;j++){
               temp[j]=prev+dp[j];
               dp[j]=temp[j];
               prev = dp[j];
           }
       }
       return dp.back();
   }
====================================================================================================================================================================================================================================================
 
