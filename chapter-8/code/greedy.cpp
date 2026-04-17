#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cmath>

using namespace std;

/* =========================================================
   Part 1: Classroom Scheduling (Interval Scheduling)
   Greedy by earliest finish time (optimal for this problem)
   ========================================================= */

struct ClassInterval {
    string name;
    int start; // e.g., 930 = 9:30
    int end;   // e.g., 1030 = 10:30
};

vector<ClassInterval> scheduleMaxClasses(vector<ClassInterval> classes) {
    sort(classes.begin(), classes.end(),
         [](const ClassInterval& a, const ClassInterval& b) {
             return a.end < b.end;
         });

    vector<ClassInterval> chosen;
    int currentEnd = -1;

    for (const auto& c : classes) {
        if (c.start >= currentEnd) {
            chosen.push_back(c);
            currentEnd = c.end;
        }
    }
    return chosen;
}

/* =========================================================
   Part 2: Set Cover (Greedy Approximation)
   Pick station covering most uncovered states each round
   ========================================================= */

unordered_set<string> greedySetCover(
    unordered_set<string> statesNeeded,
    const unordered_map<string, unordered_set<string>>& stations
) {
    unordered_set<string> finalStations;

    while (!statesNeeded.empty()) {
        string bestStation;
        unordered_set<string> statesCovered;

        for (const auto& [station, statesForStation] : stations) {
            unordered_set<string> covered;
            for (const string& s : statesForStation) {
                if (statesNeeded.count(s)) covered.insert(s);
            }

            if (covered.size() > statesCovered.size()) {
                bestStation = station;
                statesCovered = move(covered);
            }
        }

        if (bestStation.empty()) {
            // No progress possible (some states cannot be covered)
            break;
        }

        finalStations.insert(bestStation);
        for (const string& s : statesCovered) {
            statesNeeded.erase(s);
        }
    }

    return finalStations;
}

/* =========================================================
   Part 3: TSP Nearest-Neighbor (Greedy Approximation)
   Not optimal in general, but fast heuristic
   ========================================================= */

struct Point {
    string name;
    double x, y;
};

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

pair<vector<int>, double> nearestNeighborTSP(const vector<Point>& cities, int start = 0) {
    int n = (int)cities.size();
    vector<bool> visited(n, false);
    vector<int> route;
    route.reserve(n + 1);

    int current = start;
    visited[current] = true;
    route.push_back(current);

    double total = 0.0;

    for (int step = 1; step < n; ++step) {
        int nextCity = -1;
        double best = numeric_limits<double>::infinity();

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                double d = dist(cities[current], cities[i]);
                if (d < best) {
                    best = d;
                    nextCity = i;
                }
            }
        }

        visited[nextCity] = true;
        route.push_back(nextCity);
        total += best;
        current = nextCity;
    }

    // Return to start (tour)
    total += dist(cities[current], cities[start]);
    route.push_back(start);

    return {route, total};
}

/* =========================================================
   Demo
   ========================================================= */

int main() {
    // -------- 1) Classroom Scheduling --------
    cout << "=== Classroom Scheduling (Greedy: earliest finish) ===\n";
    vector<ClassInterval> classes = {
        {"Math",   900, 1030},
        {"Art",    930, 1000},
        {"English",1000,1130},
        {"CS",     1030,1200},
        {"Music",  1130,1230}
    };

    auto selected = scheduleMaxClasses(classes);
    cout << "Chosen classes:\n";
    for (const auto& c : selected) {
        cout << "- " << c.name << " (" << c.start << " -> " << c.end << ")\n";
    }
    cout << "Total: " << selected.size() << " classes\n\n";

    // -------- 2) Set Cover Approximation --------
    cout << "=== Set Cover (Greedy Approximation) ===\n";
    unordered_set<string> statesNeeded = {"mt","wa","or","id","nv","ut","ca","az"};

    unordered_map<string, unordered_set<string>> stations = {
        {"kone",   {"id","nv","ut"}},
        {"ktwo",   {"wa","id","mt"}},
        {"kthree", {"or","nv","ca"}},
        {"kfour",  {"nv","ut"}},
        {"kfive",  {"ca","az"}}
    };

    auto finalStations = greedySetCover(statesNeeded, stations);
    cout << "Chosen stations:\n";
    for (const auto& st : finalStations) {
        cout << "- " << st << "\n";
    }
    cout << "Count: " << finalStations.size() << "\n\n";

    // -------- 3) TSP Nearest Neighbor --------
    cout << "=== TSP (Nearest-Neighbor Greedy Approximation) ===\n";
    vector<Point> cities = {
        {"A", 0, 0},
        {"B", 2, 5},
        {"C", 5, 3},
        {"D", 6, 7},
        {"E", 8, 2}
    };

    auto [route, totalDistance] = nearestNeighborTSP(cities, 0);
    cout << "Route: ";
    for (size_t i = 0; i < route.size(); ++i) {
        cout << cities[route[i]].name;
        if (i + 1 < route.size()) cout << " -> ";
    }
    cout << "\nTotal distance (approx): " << totalDistance << "\n";

    return 0;
}