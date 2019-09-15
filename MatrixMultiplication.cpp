#include <iostream>
using namespace std;

#define Min(a, b) (a < b ? a : b)

int main(){
	int n;
   scanf("%d", &n);
   int p[n+1], dp[n+1][n+1];
   for(int i = 1;i < n;i++) {
       cin>>p[i-1]>>p[i];
   }
   for(int i = 1;i < n;i++){
       dp[i][i] = 0;
   }
    // dp[i][j] 表示i - j 矩阵链乘的最小次数；
   for(int l = 2;l <= n;l++) {
       for(int i = 1;i <= n - l +1;i++){
           int j = i + l -1;
           dp[i][j] = 1 << 21;
           for(int k = i;k < j ;k++){
               dp[i][j] = Min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]);
           }
       }
   }
   cout<<dp[1][n];
}
 
