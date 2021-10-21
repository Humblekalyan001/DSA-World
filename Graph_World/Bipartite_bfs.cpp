
// BFS code  // Leetcode code
bool isBipartite(vector<int> adj[], int src, vector<int> &color)
  {
    queue<int> qu;
    qu.push(src);
    color[src] = 1;
    
    while(!qu.empty())
    {
      int curr = qu.front();
      qu.pop();
      
      for(auto child : adj[curr])
      {
        if(color[child] == color[curr]) // odd length check
        {
          return false;
        }
        if(color[child] == -1)
        {
          color[child] = 1 - color[curr];
          qu.push(child);
        }
      }
    }
    return true;
  }


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
      vector<int> adj[n+1]; // size of adjacency list
      
      for(int i=0; i<dislikes.size(); i++)
      {
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
      }
      
      // make color vector // kin of visited array
      vector<int> color(n+1,-1); // initially all are -1
      
      for(int i=0; i<n; i++) // using for loop for multiple components check
      {
        if(color[i] == -1) // check color or not
        {
          if(isBipartite(adj,i,color) == false)
          {
            return false;
          }
        }
      }
      return true;
        
    }
