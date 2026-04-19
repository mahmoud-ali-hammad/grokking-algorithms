#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

struct Sample {
    vector<double> features;
    string label;      // For classification
    double target = 0; // For regression
};

// Euclidean distance
double euclideanDistance(const vector<double>& a, const vector<double>& b) {
    if (a.size() != b.size()) {
        throw runtime_error("Feature vectors must have same dimension.");
    }
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        double d = a[i] - b[i];
        sum += d * d;
    }
    return sqrt(sum);
}

// Return indices of k nearest samples
vector<int> kNearestIndices(const vector<Sample>& data, const vector<double>& query, int k) {
    vector<pair<double, int>> distIdx;
    distIdx.reserve(data.size());

    for (int i = 0; i < (int)data.size(); ++i) {
        double d = euclideanDistance(data[i].features, query);
        distIdx.push_back({d, i});
    }

    sort(distIdx.begin(), distIdx.end(),
         [](const auto& x, const auto& y) { return x.first < y.first; });

    k = min(k, (int)data.size());
    vector<int> idx;
    idx.reserve(k);
    for (int i = 0; i < k; ++i) idx.push_back(distIdx[i].second);
    return idx;
}

// KNN classification (majority vote)
// Tie-break: choose class with smallest average distance among tied classes
string knnClassify(const vector<Sample>& data, const vector<double>& query, int k) {
    vector<pair<double, int>> distIdx;
    distIdx.reserve(data.size());

    for (int i = 0; i < (int)data.size(); ++i) {
        double d = euclideanDistance(data[i].features, query);
        distIdx.push_back({d, i});
    }

    sort(distIdx.begin(), distIdx.end(),
         [](const auto& x, const auto& y) { return x.first < y.first; });

    k = min(k, (int)data.size());

    unordered_map<string, int> count;
    unordered_map<string, double> distSum;

    for (int i = 0; i < k; ++i) {
        const auto& [d, idx] = distIdx[i];
        const string& lbl = data[idx].label;
        count[lbl]++;
        distSum[lbl] += d;
    }

    string bestLabel;
    int bestCount = -1;
    double bestAvgDist = 1e100;

    for (const auto& [lbl, c] : count) {
        double avgD = distSum[lbl] / c;
        if (c > bestCount || (c == bestCount && avgD < bestAvgDist)) {
            bestCount = c;
            bestAvgDist = avgD;
            bestLabel = lbl;
        }
    }

    return bestLabel;
}

// KNN regression (simple average)
double knnRegress(const vector<Sample>& data, const vector<double>& query, int k) {
    auto idx = kNearestIndices(data, query, k);
    if (idx.empty()) return 0.0;

    double sum = 0.0;
    for (int i : idx) sum += data[i].target;
    return sum / idx.size();
}

// Optional: weighted KNN regression (closer neighbors count more)
// weight = 1 / (distance + eps)
double knnRegressWeighted(const vector<Sample>& data, const vector<double>& query, int k) {
    vector<pair<double, int>> distIdx;
    distIdx.reserve(data.size());

    for (int i = 0; i < (int)data.size(); ++i) {
        double d = euclideanDistance(data[i].features, query);
        distIdx.push_back({d, i});
    }

    sort(distIdx.begin(), distIdx.end(),
         [](const auto& x, const auto& y) { return x.first < y.first; });

    k = min(k, (int)data.size());
    const double eps = 1e-9;
    double weightedSum = 0.0;
    double weightTotal = 0.0;

    for (int i = 0; i < k; ++i) {
        double d = distIdx[i].first;
        int idx = distIdx[i].second;
        double w = 1.0 / (d + eps);
        weightedSum += w * data[idx].target;
        weightTotal += w;
    }

    return (weightTotal == 0.0) ? 0.0 : weightedSum / weightTotal;
}

int main() {
    cout << "=== KNN Classification: Orange vs Grapefruit ===\n";
    // Features: [size, redness]
    vector<Sample> fruitData = {
        {{1.0, 1.0}, "orange", 0},
        {{1.2, 1.1}, "orange", 0},
        {{3.0, 3.2}, "grapefruit", 0},
        {{2.9, 3.0}, "grapefruit", 0},
        {{1.4, 1.3}, "orange", 0}
    };

    vector<double> unknownFruit = {1.8, 1.7};
    int kClass = 3;

    string predictedFruit = knnClassify(fruitData, unknownFruit, kClass);
    cout << "Unknown fruit [" << unknownFruit[0] << ", " << unknownFruit[1]
         << "] predicted class = " << predictedFruit << "\n\n";

    cout << "=== KNN Regression: Bakery demand prediction ===\n";
    // Features: [weather(1-5), weekend_or_holiday(0/1), game_day(0/1)]
    // target: loaves sold
    vector<Sample> bakeryData = {
        {{5, 1, 1}, "", 260},
        {{4, 1, 0}, "", 220},
        {{4, 0, 1}, "", 210},
        {{3, 1, 1}, "", 200},
        {{2, 0, 0}, "", 130},
        {{5, 0, 0}, "", 180},
        {{1, 0, 0}, "", 90}
    };

    vector<double> today = {4, 1, 0}; // good weather, weekend, no game
    int kReg = 4;

    double predAvg = knnRegress(bakeryData, today, kReg);
    double predWeighted = knnRegressWeighted(bakeryData, today, kReg);

    cout << "Today features = [" << today[0] << ", " << today[1] << ", " << today[2] << "]\n";
    cout << "Predicted loaves (average KNN, k=" << kReg << "): " << predAvg << "\n";
    cout << "Predicted loaves (weighted KNN, k=" << kReg << "): " << predWeighted << "\n";

    return 0;
}