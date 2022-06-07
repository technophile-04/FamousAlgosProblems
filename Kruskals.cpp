#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class edge
{
    public:
    
    int s;
    int d;
    int w;

    edge(){}
    edge(int s,int d ,int w)
    {
        this->s=s;
        this->d=d;
        this->w=w;
    }
};

bool comp(edge const & a , edge const & b)
{
		return a.w < b.w;
}
int findparent(int * parent ,int v)
{
    if(parent[v]==v)
    return v;
    
    return findparent(parent,parent[v]);
}
void kruskalMST(edge * input, int v , int e)
{
    sort(input,input+e, comp);
    
    int* parent =new int[v];
    for(int i=0 ;i <v ;i++)
    {
        parent[i]=i;
    }
    
    edge *output=new edge[v-1];
    int count=0;
    int i=0;
    while(count!=v-1)
    {
        edge currentEdge =input[i];
        
        int parent_s=findparent(parent,currentEdge.s);
        int parent_d=findparent(parent,currentEdge.d);
        
        if(parent_s != parent_d)
        {
            output[count]=currentEdge;
            count++;
            
            parent[parent_s]= parent_d;
        }
        i++;
        
    }

    int totalWeight = 0;
    for(int i=0 ; i< v-1 ;i++ )
    {
        totalWeight += output[i].w;
        if( output[i].s< output[i].d)
            cout<<output[i].s<<"-->"<< output[i].d<<" = "<<output[i].w<< endl;
        else{
           cout<<output[i].d<<"-->"<< output[i].s<<" = "<<output[i].w<< endl;

        }
    }

    cout<<"The cost of MST is : "<<totalWeight;
     delete [] output;

    delete [] parent;
}
int main()
{
    int V, E;
    cout<<"Enter the number of vertices and number of edges : ";
    cin >> V >> E;

  cout<<"Enter the edges in the format (v1 v2 and weight) : "<<endl;
  edge *input= new edge[E];
  for(int i= 0; i<E ;i++)
  {   int s,d,w;
      cin>>s>>d>>w;
      input[i]=edge(s,d,w);
  }
    
	cout<<"The MST is (v1->v2 = weight) : "<<endl;
  kruskalMST(input,V,E);
    
  delete [] input;

    return 0;
}