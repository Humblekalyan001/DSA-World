void dfs(int v, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[v] = true;
    
    for(auto child : adj[v])
    {
        if(visited[child] == false)
        {
            dfs(child , visited , adj);
        }
    }
    return;
}

int Solution::solve(int V, vector<vector<int> > &edges) 
{
    vector<bool> visited(V+1, false);
    
    vector<vector<int>> adj(V+1);
    for(int i=0; i<edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    int cc = 0;
    for(int i=1; i<=V; i++)
    {
        if(visited[i] == false)
        {
            dfs(i, visited , adj);
            cc++;
        }
    }
    
    return cc;
    
}
