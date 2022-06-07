#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> minMax(int *arr, int s, int e){

  if(s == e){
    pair<int, int> ans = make_pair(arr[s], arr[s]);
    return ans;  
  }

  int mid = (s+e)/2;

  pair<int,int> leftAns = minMax(arr, s, mid);
  pair<int,int> rightAns = minMax(arr, mid+1, e);

  int minValue = min(leftAns.first, rightAns.first);
  int maxValue = max(leftAns.second, rightAns.second);
  
  pair<int, int> finalAns = make_pair(minValue, maxValue);

  return finalAns;
  
}


int main(){
  int n;
  cout<<"Enter the size : ";
  cin>>n;
  int *arr = new int[n];

  cout<<"Enter the elements of array : "<<endl;
  for(int i = 0; i < n; ++i){
    cin>>arr[i];
  }

  pair<int, int> finalAns = minMax(arr, 0, n-1);

  cout<<"Min value is : "<<finalAns.first<<endl;
  cout<<"Max value is : "<<finalAns.second<<endl;
  
  
  return 0;
}