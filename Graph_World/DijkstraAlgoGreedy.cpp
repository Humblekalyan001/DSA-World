//*********************************** Hackerearth ************************************************************************
// TC: O(V+ElogV)
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

#define SIZE 100000 + 1

vector < pair < int , int > > v [SIZE];   // each vertex has all the connected vertices with the edges weights //
//Adjacency List representation : u -> (v,w), v->(u,weight)
      
int dist [SIZE];
bool vis [SIZE];

void dijkstra(){
                                                // set the vertices distances as infinity
    memset(vis, false , sizeof(vis));            // set all vertex as unvisited
    dist[1] = 0;
 // priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert({0 , 1});                          // insert the source node with distance = 0 // (weight,vertex)

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.s;  // p.second
        int wei = p.f;  // p.second
      
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].f;  // weight value
            int w = v[x][i].s;  // vertex value
            if(dist[x] + w < dist[e]  )  // check if the next vertex distance could be minimized
            {            
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e});           // insert the next vertex with the updated distance
            }
        }
    }
}
********************************************************************************************************************************************************************************
// Striver

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
  
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() )
  {
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++)
    {
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist)
      {
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}

********************************************************************************************************************************************************************************
// Tech Dose

#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices

int selectMinVertex(vector<int>& value,vector<bool>& processed)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(processed[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V])
{
	int parent[V];		//Stores Shortest Path Structure
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	vector<bool> processed(V,false);	//TRUE->Vertex is processed

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	for(int i=0;i<V-1;++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(value,processed);
		processed[U] = true;	//Include new Vertex in shortest Path Graph

		//Relax adjacent vertices (not yet included in shortest path graph)
		for(int j=0;j<V;++j)
		{
			/* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX
			&& (value[U]+graph[U][j] < value[j]))
			{
				value[j] = value[U]+graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

	dijkstra(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)
