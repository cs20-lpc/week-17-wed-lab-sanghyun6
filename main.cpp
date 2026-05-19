#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 9});
    adj[0].push_back({4, 2});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 7});
    adj[2].push_back({5, 4});
    adj[3].push_back({5, 1});
    adj[4].push_back({2, 3});
    adj[4].push_back({5, 8});

    cout << "Shortest distances from node 0:" << endl;
    vector<int> res0 = dijkstra(0, n, adj);
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": ";
        if (res0[i] == INT_MAX)
            cout << "unreachable" << endl;
        else
            cout << res0[i] << endl;
    }

    cout << endl;

    cout << "Shortest distances from node 1:" << endl;
    vector<int> res1 = dijkstra(1, n, adj);
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": ";
        if (res1[i] == INT_MAX)
            cout << "unable" << endl;
        else
            cout << res1[i] << endl;
    }

    return 0;
}