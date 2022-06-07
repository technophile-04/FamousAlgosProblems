#include <iostream>
#include<climits>
using namespace std;
#define INF INT_MAX;

int shortestDist(int **graph, int N) {
 
    int dist[N];
 
    dist[N-1] = 0;
 
 
    for (int i = N-2 ; i >= 0 ; i--)
    {
 
       
        dist[i] = INF;
 
        for (int j = i ; j < N ; j++)
        {
            
            if (graph[i][j] == INT_MAX)
                continue;
 
            dist[i] = min(dist[i], graph[i][j] +
                                        dist[j]);
        }
    }
 
    return dist[0];
}



int main() {
  int vertices, sourceVertex; 
  cout<<"Enter the number of vertices : ";
  cin>>vertices;

  cout<<"Enter the adjacency matrix :"<<endl;
  
  int **graph = new int*[vertices];

  for(int i = 0; i < vertices; i++){
    graph[i] = new int[vertices];
    for(int j = 0; j < vertices; j++){
      cin>>graph[i][j];
    }
  }

  cout<<"Enter the source vertex : ";
  cin>>sourceVertex;
  shortestDist(graph,vertices);
  cout<<endl;
  for(int i= 0; i < vertices; i++){
    for(int j = 0; j < vertices; j++){
      cout<<graph<<" ";
    }
    cout<<endl;
  }
  
  return 0;                           
  
}