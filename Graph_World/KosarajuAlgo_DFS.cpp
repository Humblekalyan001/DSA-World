For finding Strongly Connected Componet We use Kosaraju Algorithm. It is a DFS algorithm.
  
 3 steps:
1. 1st time DFS + and store vectices in stack
2. Reverse The graph edge, Transpose Graph
3. 2nd time DFS call and print all SCC or Count  total SCC...according to question statement.
  
Time complexity takes: O(V+E)
*****************************************************************

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	// step 1: First DFS done and store vecrtices in stack during backtracking
	void DFS1(vector<int> adj[], int s, stack<int> &stk, bool visited[])
	{
	    visited[s] = true;
	    for(auto u : adj[s])
	    {
	        if(visited[u] == false)
	        {
	            DFS1(adj, u, stk,visited);
	        }
	    }
	    stk.push(s);  // store during backtracking
	}
	
	// Step 2: Reverse all edges of the given Graph G,

	// Step 3: 2nd time DFS call in Transpose Graph , no need to store in stack..based on question requirment
	void DFS2(vector<int> res[], int s,bool visited[])
	{
        // cout<<s<<" ";     // if u want to print each SCC
	    visited[s] = true;
	    for(auto u : res[s])
	    {
	        if(visited[u] == false)
	        {
	            DFS2(res, u, visited);
	        }
	    }
	    
	}
	
	//Function to find number of strongly connected components in the graph.
	
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        bool visited[v] = {false}; // visited array
        stack<int> stk;
        for(int i=0; i<v; i++)
        {
            if(visited[i]==false)
            {
                DFS1(adj, i, stk, visited);
            }
        }
        
        
        //Step 2:  reverse the graph 
        vector<int> revAdj[v];  //  so we need new Adjacency list
        
        for(int i=0; i<v; i++)
        {
            for(auto u:revAdj[i])
            {
                revAdj[u].push_back(i);
            }
        }
        
        // Step 3 : Second time DFS call coidng
        memset(visited, false, sizeof(visited));   // visited array . again making false for DFS2
        
        int count=0; // for counting SCC
        
        while(!stk.empty())
        {
            int val = stk.top();
            stk.pop();
            
            if(visited[val] == false)
            {
                count++;
                DFS2(revAdj,val,visited);
            }
        }
        return count;
    }
};
//****************************************//

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v); // directed
            // adj[v].push_back(u);  if undirected then both will under consideration. 
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }
    return 0;
}
