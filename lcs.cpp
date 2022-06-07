#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){

  int m = s1.length();
  int n = s2.length();

  int **dp = new int*[m + 1];

  for(int i = 0; i <= m; i++){
    dp[i] = new int[n+1];
    for(int j = 0; j <= n; j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
    }
  }

  for(int i = 1; i <= m ; i++){

    for(int j = 1; j <=n; j++){

      if(s1[i - 1] == s2[j - 1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
      
    }
    
  }

  char lcsString[dp[m][n] + 1];
  lcsString[dp[m][n]] = '\0';
  int lIndex = dp[m][n];

  int i = m, j = n;

  while( i > 0 && j > 0){
    if(s1[i-1] == s2[j-1]){
      lcsString[lIndex - 1] = s1[i-1];
      i--;
      j--;
      lIndex -- ;
    }else if(dp[i-1][j] > dp[i][j-1]){
        i--;
    }else if(dp[i-1][j] < dp[i][j-1]){
      j--;
    }else{
      i--;
    }
  }

  cout<<lcsString<<endl;
  
  return dp[m][n];

  
}


int main(){

  string s1;
  string s2;

  cin>>s1; 
  cin>>s2;

  int max = lcs(s1, s2);

  cout<<max;
  
  return 0;
}
