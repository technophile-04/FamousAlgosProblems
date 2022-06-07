#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void util_copy2DMatrix(int **firstMat, int **secondMat, int n){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        firstMat[i][j] = secondMat[i][j];
      }
    }
}

void util_print2DMatrix(int **matrix , int n){
  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout<<matrix[i][j]<<" ";
      }
    cout<<endl;
  }
    
}


bool check(int** input,int** target,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(input[i][j]!=target[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int cost(int** input,int** target,int n,int fx)
{
    int mismatches=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(input[i][j]!=target[i][j] )
            {
                mismatches++;
            }
        }
    }
    return fx+mismatches; 

}


int main()
{
    int n;
    cout<<"Enter the size of puzzle"<<endl;
    cin>>n;

    int** inputMatrix=new int*[n];
    int** targetMatrix=new int*[n];
    int** intermediateMatrix=new int*[n];
    int** tempMatrix=new int*[n];
    for(int i=0;i<n;i++)
    {
        inputMatrix[i]=new int[n];
        targetMatrix[i]=new int[n];
        intermediateMatrix[i]=new int[n];
        tempMatrix[i]=new int[n];
    }
    cout<<"Enter the input matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>inputMatrix[i][j];
        }
    }
    cout<<"Enter the target matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>targetMatrix[i][j];
        }
    }

  cout<<"Input Matrix: "<<endl;
  util_print2DMatrix(inputMatrix, n);
  cout<<endl;

    int fx=0; // Looop variable / height of tree
    

    while(!check(inputMatrix,targetMatrix,n))
    {   int Dmin=INT_MAX;// MINIMUM COST OF EACH MOVE INITIALIAZTION
        int d; // just a temp variable to store cost of each move
        int blankXCordinate=0,blankYCordinate=0;// blank tile's position in input matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(inputMatrix[i][j]==0) // blank tile represented by 0 
                {
                    blankXCordinate=i;
                    blankYCordinate=j;
                    break;
                }
            }
        }
        // Now we'll move blank tile in all four directions
        // Moving up

        // first copy the input matrix to temp matrix
        util_copy2DMatrix(tempMatrix, inputMatrix, n);
        
      // Now moving up i.e swapping blank tile with tile above it i.e same column , row-1
        // only if its not the top row
        if(blankXCordinate!=0)
        {
            tempMatrix[blankXCordinate][blankYCordinate]=tempMatrix[blankXCordinate-1][blankYCordinate]; // copying above tile's value to blank tile
            tempMatrix[blankXCordinate-1][blankYCordinate]=0; // blank tile value is set to 0 i.e of above tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
          util_copy2DMatrix(intermediateMatrix, tempMatrix, n);
        }

        // Moving down
        // first copy the input matrix to temp matrix
        util_copy2DMatrix(tempMatrix, inputMatrix, n);
        // Now moving down i.e swapping blank tile with tile below it i.e same column , row+1
        // only if its not the last row
        if(blankXCordinate!=n-1) 
        {
            tempMatrix[blankXCordinate][blankYCordinate]=tempMatrix[blankXCordinate+1][blankYCordinate]; // copying below tile's value to blank tile
            tempMatrix[blankXCordinate+1][blankYCordinate]=0; // blank tile value is set to 0 i.e of below tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
            util_copy2DMatrix(intermediateMatrix, tempMatrix, n);
        }

        // Moving left
        // first copy the input matrix to temp matrix
        util_copy2DMatrix(tempMatrix, inputMatrix, n);
        // Now moving left i.e swapping blank tile with tile left it i.e same row , col-1
        // only if its not the first col
        if(blankYCordinate!=0)
        {
            tempMatrix[blankXCordinate][blankYCordinate]=tempMatrix[blankXCordinate][blankYCordinate-1]; // copying left tile's value to blank tile
            tempMatrix[blankXCordinate][blankYCordinate-1]=0; // blank tile value is set to 0 i.e of left tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
            util_copy2DMatrix(intermediateMatrix, tempMatrix, n);
        }

        // Moving right 
        // first copy the input matrix to temp matrix
        util_copy2DMatrix(tempMatrix, inputMatrix, n);
        // Now moving right i.e swapping blank tile with tile right it i.e same row , col+1
        // only if its not the last col since we cannot move right
        if(blankYCordinate!=n-1)
        {
            tempMatrix[blankXCordinate][blankYCordinate]=tempMatrix[blankXCordinate][blankYCordinate+1]; // copying right tile's value to blank tile
            tempMatrix[blankXCordinate][blankYCordinate+1]=0; // blank tile value is set to 0 i.e of right tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
            util_copy2DMatrix(intermediateMatrix, tempMatrix, n);
        }

        // Now setting the intermediate matrix as input matrix (i.e matrix due to the best possible move) // Also printing the intermedite matrix
        cout<<"Intermediate matrix :"<<fx+1<<endl;
        util_copy2DMatrix(inputMatrix,intermediateMatrix, n);
      
        util_print2DMatrix(inputMatrix, n);

     fx++; // incrementing loop variable i.e height of tree after each iteration
    }
// After we ae out of the loop => we have reached the target matrix

cout<<"Target matrix"<<endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<targetMatrix[i][j]<<" ";
    }
    cout<<endl;
}


    for(int i=0;i<n;i++)
    {
        delete [] inputMatrix[i];
        delete [] targetMatrix[i];
        delete [] intermediateMatrix[i];
        delete [] tempMatrix[i];
    }
    delete [] inputMatrix;
    delete [] targetMatrix;
    delete [] intermediateMatrix;
    delete [] tempMatrix;
}


/*
input matrix:
1
2
3
4
5
6
0
8
9
10
7
11
13
14
15
12


target matrix:
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
0



*/