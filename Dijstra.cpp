
#include<bits/stdc++.h>
using namespace std;
#define MAX 99999
#define pii pair<int, int>

long long nodes, edges, startingNode, u, v, w, dist[MAX];
bool visit[100000];
vector<pii> adj[MAX];

struct ascending
{
    bool operator() (const pii &a, const pii &b)
  {
    return a.second > b.second;
  }
};
priority_queue<pii, vector<pii>, ascending > Q; // adjacent's values are ascending order.

void dijstra(int starting_node)
{
    for(int i = 1; i <= nodes; i++)dist[i] = INT_MAX;// Initially all nodes weight is infinity.
    dist[startingNode] = 0; // Starting node weight is 0
    Q.push(make_pair(startingNode, 0));
    while(!Q.empty())
    {
        u = Q.top().first; // Queues first elements is node.
        Q.pop();
        if(visit[u])continue;
        for(int i = 0; i < adj[u].size(); i++) // Loops upto adjacency list size.
        {
            v = adj[u][i].first; // U's adjacency nodes.
            w = adj[u][i].second; // U's adjacency nodes weight.
            if(!visit[v] and dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w; // Current node's weight and summation of previous visited node's weight sum.
                Q.push(make_pair(v, dist[v]));
            }
        }
        visit[u] = 1; // Marks the visited node.
    }
}
int main()
{
    cout << "Enter the node and edge number:" << endl;
    cin >> nodes >> edges;
    cout << "Enter the parent node, child node and corresponding weight:\n";
    for(int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w)); // Insert the value using adjacency list.
        adj[v].push_back(make_pair(u, w));
    }
    cout << "Enter the starting node:\n";
    cin >> startingNode;
    dijstra(startingNode); // Calls the dijstra function

    for(int i = 1; i <= nodes; i++)
    {
        cout << "Node " << i << " weight " << dist[i] << endl;
    }

}
