#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>Recdfs(vector<int> adj[], vector<int>& vec1, int s, vector<bool>& visited)
    {
        visited[s] = true;								// initially sourse s is visited
        vec1.push_back(s);								// and push into vector for answer,,, for printing just cout<< s<<;
        for(int u : adj[s])								// explore its neighbour node
        {
            if(visited[u]== false)						// check nbr  is visited or not
            {
                Recdfs(adj,vec1,u,visited);				// if not, just call again
            }
        }
        return vec1;									// at last return vector,where all vertices stores in any DFS sequence//
    }
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
    {
	    vector<int> vec1;         						// for answer returning        
	    vector<bool> visited(V, false);					// initially visited vector are all false
	    Recdfs(adj,vec1, 0, visited); 					// caall DFS
	    return vec1;									// Return answer vector
	}
};


int main(){
	int tc;         // no. of test case
	cin >> tc;      
	while(tc--){        
		int V, E;               // V = vertices
    	cin >> V >> E;          // E = number of e
        

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}
