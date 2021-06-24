 Shortest path using DAG ----> Using Topo sort 
  
 Time Complexity : O(V+E);

**************************************************************
#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}

void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
	int vis[N] = {0};   // initially visited array is 0 == false
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9; 

	dist[src] = 0; // strating point ,so make its dist = 0.

	while(!st.empty()) 
	{  
		int node = st.top(); 
		st.pop(); 
 
		if (dist[node] != INF) 
        {
		    for(auto it : adj[node]) 
            {
		        if(dist[node] + it.second < dist[it.first]) 
                {
		            dist[it.first] = dist[node] + it.second; 
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) 
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 

int main() 
{ 
	int n, m;
    // n = vertices. m = edges
	cin >> n >> m;                //       w
	vector<pair<int,int>> adj[n]; //  u -------> v

	for(int i = 0;i<m;i++) 
    {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(1, n, adj); // suppose starting vertex is  0.

	return 0; 
} 

/*
i/o:
6 9
0 1 5
0 2 3
1 3 6
1 2 2
2 4 4
2 5 2
2 3 7
3 4 -1
4 5 -2

o/p:
INF 0 2 6 5 3 
*/
