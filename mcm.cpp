#include<bits/stdc++.h>
using namespace std;

void printParenthesis(int i , int j, int n, int**bracket, char &name){
  if(i == j){
    cout<<name++;
    return;
  }

  cout<<"(";

  printParenthesis(i, bracket[i][j], n, bracket, name);
  printParenthesis(bracket[i][j] + 1, j, n , bracket, name);
  cout << ")";
  
}

int mcm(int *p, int n){
  int **m = new int*[n];
  int **bracket = new int*[n];

  for(int i = 0; i < n; ++i){
    m[i] = new int[n];
    bracket[i] = new int[n];
    m[i][i] = 0;
  }

  for(int L = 2; L < n; L++){

    for(int i = 1; i < n-L+1; i++){
      int j = i + L - 1;
      m[i][j] = INT_MAX;
      for(int k = i; k <= j - 1; k++){

        
        int cst = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
        if(cst < m[i][j]){
          m[i][j] = cst;
          bracket[i][j] = k;
        }
        
        
      }
      
      
    }

    
  }

  
  char name = 'A';

  printParenthesis(1, n-1, n, bracket, name);
  
}



int main(){

  int noOfMatrices;
  cout<<"Enter the number of matrices : ";
  cin>>noOfMatrices;

  int *matrices = new int[noOfMatrices+1];

  for(int i = 0 ; i < noOfMatrices; i++){
    char c = 65 + i;
    cout<<"Enter the dimension for matrix "<<c<<" : ";
    int n , m;
    cin>>n>>m;
  
    matrices[i] = n;
    matrices[i+1] = m;
  }

  cout<<"The matrix is : "<<endl;

  for(int i = 0; i < noOfMatrices + 1; i++){
    cout<<matrices[i]<<" ";
  }

  cout<<endl;

  int cost = mcm(matrices, noOfMatrices);

  cout<<endl;
  cout<<"The Minimum cost is : "<<cost;

  return 0;
}