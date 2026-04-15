#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

// Example condition from the book:
// A "mango seller" is someone whose name ends with 'm'
bool personIsSeller(const string& name) {
    return !name.empty() && name.back() == 'm';
}

// BFS search: returns true if a seller is found, false otherwise
bool searchSeller(const unordered_map<string, vector<string>>& graph, const string& start) {
    queue<string> q;
    unordered_set<string> searched;

    // Add all neighbors of start node to queue
    auto it = graph.find(start);
    if (it == graph.end()) return false;

    for (const string& neighbor : it->second) {
        q.push(neighbor);
    }

    while (!q.empty()) {
        string person = q.front();
        q.pop();

        // If already checked, skip
        if (searched.count(person)) continue;

        if (personIsSeller(person)) {
            cout << person << " is a mango seller!" << endl;
            return true;
        }

        // Add this person's neighbors to queue (if any)
        auto personIt = graph.find(person);
        if (personIt != graph.end()) {
            for (const string& neighbor : personIt->second) {
                q.push(neighbor);
            }
        }

        searched.insert(person);
    }

    return false;
}

int main() {
    // Graph as adjacency list
    unordered_map<string, vector<string>> graph;
    graph["you"]    = {"alice", "bob", "claire"};
    graph["bob"]    = {"anuj", "peggy"};
    graph["alice"]  = {"peggy"};
    graph["claire"] = {"thom", "jonny"};
    graph["anuj"]   = {};
    graph["peggy"]  = {};
    graph["thom"]   = {};
    graph["jonny"]  = {};

    bool found = searchSeller(graph, "you");
    if (!found) {
        cout << "No mango seller found in your network." << endl;
    }

    return 0;
}