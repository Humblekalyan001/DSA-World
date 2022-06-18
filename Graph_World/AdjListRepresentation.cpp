// This is the Representaion of Adjacency List of a Undirected Graph//
#include<iostream>
#include<vector>
using namespace std;
void addEdges(std::vector<int> adj[],int u, int v)
{
    // I am creating Adjacency List for Undirected Graph//
    adj[u].push_back(v);  // connecting two edges
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int V) 
{ 
    for (int i = 0; i < V; i++) 
    { 
        for (int x : adj[i]) 
           cout << x <<" "; 
        cout<<"\n"; 
    } 
}
int main()
{
    int V = 4; // here v is number of vertices
    vector<int> adj[4];
    addEdges(adj,0,1); // it will create edge 0---1,1----0,
    addEdges(adj,0,2);// it will create  edge 0----2,2---0
    
    addEdges(adj,2,1);// it will create edge 2----1,1----2
    addEdges(adj,2,3); // it will create edge 2----3,3---2
 
 printGraph(adj,V);   
 return 0;
    
}


