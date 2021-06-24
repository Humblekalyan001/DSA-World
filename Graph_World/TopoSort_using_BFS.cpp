// Kanh's Algorithm // 



***************************************************
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void Topo_DFS(vector<int> adj[], int s, stack<int> &stk ,vector<bool> &visited)
	{
	    visited[s] = true; // visited
	    
	    for(auto u : adj[s])
	    {
	        if(visited[u] == false)
	        {
	            Topo_DFS(adj, u,stk, visited);
	        }
	    }
	    stk.push(s);  // during backtrack  we need to store vertices
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    // adjacency list given
	    // total vectices given
	    
	    vector<int> res; // for storing result
	    vector<bool> visited(v,false); // visited array
	    
	    stack<int> stk; // for storing vertex permutation
	    for(int i=0; i<v; i++)
	    {
	        if(!visited[i])
	        {
	            Topo_DFS(adj,i,stk,visited);
	        }
	    }
	    while(!stk.empty())
	    {
	        res.push_back(stk.top());
	        stk.pop();
	    }
	    
	    return res;
	}
};
