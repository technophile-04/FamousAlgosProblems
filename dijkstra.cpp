#include<bits/stdc++.h>
using namespace std;

int findMin(int *dist, bool *visited, int v){

  int min = INT_MAX;
  int min_index = -1;
  
  for(int i = 0; i < v; i++){
    if(dist[i] < min && !visited[i]){
      min = dist[i];
      min_index = i;
    }
  }

  return min_index;
  
}

void dijkstra(int **edges, int v, int src){
  int *dist = new int[v];
  bool *visited = new bool[v];

  for(int i = 0; i < v; i++){

    dist[i] = INT_MAX;
    visited[i] = false;
    
  }

  dist[src] = 0;

  for(int i = 0; i < v - 1; i++){

    int minVertex = findMin(dist, visited, v);

    visited[minVertex] = true;
    
    for(int j = 0; j < v; j++){

      if(edges[minVertex][j] != 0 && !visited[j]){
        int dis = edges[minVertex][j] + dist[minVertex];
        if(dis < minVertex){
          dist[j] = dis;
        }
        
      }
      
    }
    
  }

  for(int i=0; i < v; i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }

}

int main(){
  int v, e;
  cin>>v>>e;

  int **edges = new int*[v];

  for(int i = 0; i < v; i++){

    edges[i] = new int[v];

  }

  for(int i = 0; i < e; i++){
    int s, e, d;
    cin>>s>>e>>d;

    edges[s][e] = d;
    edges[e][s] = d;
    
  }

  dijkstra(edges, v, 0);
  


  return 0;
}