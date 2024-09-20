#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> distFrom1;
vector<int> distFromU;
vector<int> distFromV;

// BFS to calculate distances from a given vertex
void bfs(int start, vector<int> &dist, int n)
{
    queue<int> q;
    vector<bool> visited(n + 1, false);

    dist[start] = 0;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // Resize adjacency list and distance arrays
        adj.assign(n + 1, vector<int>());
        distFrom1.assign(n + 1, 0);
        distFromU.assign(n + 1, 0);
        distFromV.assign(n + 1, 0);

        // Read the tree edges
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // Read the special vertices u and v
        int u, v;
        cin >> u >> v;

        // BFS from vertex 1, u, and v to calculate distances
        bfs(1, distFrom1, n); // Distances from vertex 1
        bfs(u, distFromU, n); // Distances from vertex u
        bfs(v, distFromV, n); // Distances from vertex v

        // Determine the winner for all possible starting positions of Bob
        int distance_uv = distFromU[v]; // The distance between u and v

        if (distFrom1[u] < distFrom1[v])
        {
            cout << "Alice" << '\n';
        }
        else
        {
            cout << "Bob" << '\n';
        }
    }

    return 0;
}
