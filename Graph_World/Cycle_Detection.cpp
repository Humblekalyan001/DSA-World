int Solution::solve(int N, vector<vector<int> > &edges) 
{
    // USe Kahn's Algorithm
    
    vector<vector<int>> adj(N+1);
    for(int i=0; i<edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    // step : 1// making indegree array
    vector<int> in_degree(N+1,0);
    for(int u=1; u<=N; u++)
    {
        for(auto x : adj[u])
        {
            in_degree[x]++;
        }
    }
    // step 2: store all 0 indegree virtices in queue
    queue<int> qu;
    for(int i=1; i<=N; i++)
    {
        if(in_degree[i] == 0)
        {
            qu.push(i);
        }
    }
    
    int count=0;
    // step 3: BFS
    while(!qu.empty())
    {
        int val = qu.front();
        qu.pop();
        
        for(auto x : adj[val])
        {
            if(--in_degree[x] == 0)
            {
                qu.push(x);
            }
        }
        count++;
    }
    if(count != N)
    {
        return 1;
    }
    return 0; 
}
