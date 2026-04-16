#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

// Adjacency list: graph[u] = list of {v, weight}
using Graph = unordered_map<string, vector<pair<string, int>>>;

struct DijkstraResult {
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;
};

DijkstraResult dijkstra(const Graph& graph, const string& start) {
    const int INF = numeric_limits<int>::max();

    unordered_map<string, int> dist;
    unordered_map<string, string> parent;

    // Initialize distances to INF for all nodes in graph keys
    for (const auto& kv : graph) {
        dist[kv.first] = INF;
        parent[kv.first] = "";
    }

    // Also ensure neighbors exist in dist/parent even if not keys in map
    for (const auto& kv : graph) {
        for (const auto& edge : kv.second) {
            const string& v = edge.first;
            if (!dist.count(v)) {
                dist[v] = INF;
                parent[v] = "";
            }
        }
    }

    dist[start] = 0;

    // Min-heap: {distance, node}
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        // Skip stale heap entries
        if (currentDist > dist[u]) continue;

        // If u has no outgoing edges, continue
        if (!graph.count(u)) continue;

        for (const auto& [v, w] : graph.at(u)) {
            // Dijkstra requires non-negative weights
            if (w < 0) {
                cerr << "Error: Negative edge detected (" << u << " -> " << v
                     << " = " << w << "). Dijkstra is invalid here.\n";
                continue;
            }

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return {dist, parent};
}

vector<string> reconstructPath(const unordered_map<string, string>& parent,
                               const string& start,
                               const string& target) {
    vector<string> path;
    string cur = target;

    // Walk backward from target using parent pointers
    while (!cur.empty()) {
        path.push_back(cur);
        if (cur == start) break;
        auto it = parent.find(cur);
        if (it == parent.end() || it->second.empty()) {
            // No path
            return {};
        }
        cur = it->second;
    }

    reverse(path.begin(), path.end());

    if (path.empty() || path.front() != start) return {};
    return path;
}

int main() {
    // Example graph from chapter:
    // start -> a (6), start -> b (2)
    // b -> a (3), b -> fin (5)
    // a -> fin (1)
    Graph graph;
    graph["start"] = {{"a", 6}, {"b", 2}};
    graph["a"]     = {{"fin", 1}};
    graph["b"]     = {{"a", 3}, {"fin", 5}};
    graph["fin"]   = {};

    string start = "start";
    string target = "fin";

    DijkstraResult result = dijkstra(graph, start);

    const int INF = numeric_limits<int>::max();
    if (!result.dist.count(target) || result.dist[target] == INF) {
        cout << "No path from " << start << " to " << target << ".\n";
        return 0;
    }

    vector<string> path = reconstructPath(result.parent, start, target);

    cout << "Shortest cost from " << start << " to " << target << " = "
         << result.dist[target] << "\n";

    cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
    }

    return 0;
}