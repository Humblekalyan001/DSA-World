// Here input is giving User..from 0 only....

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
  
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<bool> visit(V+1,false); // visited vector
	    
	    vector<int> bfs; // for storing bfs answer
	    
        queue<int> qu;              // for bfs we need Queue for storing current vertex
        
        qu.push(0);                 // 1st I visited source s , so pushed it
        visit[0] = true;
        
         while(!qu.empty())         // explore its neighbour node
        {
            int u = qu.front();     // explored
            qu.pop();               // poped from queue
            
            bfs.push_back(u);       //store it for result purpose

            for(auto nbr :adj[u])    // now its neighbour will be pushed in queue one by one 
            {
                if(visit[nbr] == false)   // check if visited or not
                {                  
                    visit[nbr] = true;      // if not marked it as visited
                    qu.push(nbr);           // and push into queue for its exploration
                }
            }
        }
        
        return bfs; // return answer
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
