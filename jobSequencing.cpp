#include<bits/stdc++.h>
using namespace std;

class Job {
  public : 
      int jobId;
      int deadline;
      int profit;
};

bool sortOnProfit(Job j1, Job j2){
  return j1.profit > j2.profit;
}


int getMaxProfit(Job *jobs, int n, int *allocations, int maxDeadline){

  int totalProfit = -1;

  for(int i = 0; i < n; i++){

    int currJobDeadline = jobs[i].deadline;

    while(currJobDeadline >= 0){
      if(allocations[currJobDeadline] == -1){
        allocations[currJobDeadline] = jobs[i].jobId;
        totalProfit += jobs[i].profit;
        break;
      }
      currJobDeadline--;
    }
    
  }

  
  return totalProfit;

  
}



int main(){
  int noOfJobs;
  cout<<"Enter the number of jobs : ";
  cin>>noOfJobs;

  Job *jobs = new Job[noOfJobs];

  for(int i = 0; i < noOfJobs; i++){

    int dead, pro;

    cout<<"Enter the deadline and profit for job "<<i+1<<" ";
    cin>>dead;
    dead -= 1;
    jobs[i].deadline = dead;
    cin>>jobs[i].profit;
    jobs[i].jobId = i+1;
    cout<<endl;
    
  }

  cout<<endl;
  
  sort(jobs, jobs+noOfJobs, sortOnProfit);

  int maxDeadLine = -1;

  for(int i = 0; i < noOfJobs; i++){
    if(jobs[i].deadline > maxDeadLine){
      maxDeadLine = jobs[i].deadline;
    }
  }

  maxDeadLine += 1;
  
  int *allocations = new int[maxDeadLine];

  for(int i = 0; i < maxDeadLine; i++){
    allocations[i] = -1;
  }

  int totalProfit = getMaxProfit(jobs, noOfJobs, allocations, maxDeadLine);

  cout<<totalProfit<<endl;

  for(int i = 0; i < maxDeadLine; i++){
    cout<<allocations[i]<<" ";
  }
  
  
}