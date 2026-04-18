#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* =========================================================
   1) 0/1 Knapsack (DP) + chosen items reconstruction
   ========================================================= */
struct Item {
    string name;
    int weight;
    int value;
};

struct KnapsackResult {
    int maxValue;
    vector<string> chosenItems;
};

KnapsackResult knapsack01(const vector<Item>& items, int capacity) {
    int n = (int)items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        int wt = items[i - 1].weight;
        int val = items[i - 1].value;
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w]; // skip item
            if (wt <= w) {
                dp[i][w] = max(dp[i][w], val + dp[i - 1][w - wt]); // take item
            }
        }
    }

    // Reconstruct chosen items
    vector<string> chosen;
    int w = capacity;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen.push_back(items[i - 1].name);
            w -= items[i - 1].weight;
        }
    }
    reverse(chosen.begin(), chosen.end());

    return {dp[n][capacity], chosen};
}

/* =========================================================
   2) Longest Common Substring (contiguous)
   ========================================================= */
struct LCSubstringResult {
    int length;
    string substring;
};

LCSubstringResult longestCommonSubstring(const string& a, const string& b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int bestLen = 0;
    int endPosA = 0; // end index in a (1-based in DP)

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > bestLen) {
                    bestLen = dp[i][j];
                    endPosA = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    string sub = (bestLen > 0) ? a.substr(endPosA - bestLen, bestLen) : "";
    return {bestLen, sub};
}

/* =========================================================
   3) Longest Common Subsequence (not necessarily contiguous)
   ========================================================= */
struct LCSResult {
    int length;
    string subsequence;
};

LCSResult longestCommonSubsequence(const string& a, const string& b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct one LCS string
    string seq;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            seq.push_back(a[i - 1]);
            --i; --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(seq.begin(), seq.end());

    return {dp[n][m], seq};
}

/* =========================================================
   Demo
   ========================================================= */
int main() {
    // ---------- Knapsack example ----------
    cout << "=== 0/1 Knapsack ===\n";
    vector<Item> items = {
        {"Guitar", 1, 1500},
        {"Stereo", 4, 3000},
        {"Laptop", 3, 2000}
    };
    int capacity = 4;

    auto kRes = knapsack01(items, capacity);
    cout << "Max value: " << kRes.maxValue << "\nChosen items: ";
    for (size_t i = 0; i < kRes.chosenItems.size(); ++i) {
        cout << kRes.chosenItems[i] << (i + 1 < kRes.chosenItems.size() ? ", " : "\n");
    }
    cout << "\n";

    // ---------- Longest Common Substring ----------
    cout << "=== Longest Common Substring ===\n";
    string s1 = "hish";
    string s2 = "fish";
    auto lcSub = longestCommonSubstring(s1, s2);
    cout << "Strings: \"" << s1 << "\" vs \"" << s2 << "\"\n";
    cout << "Length: " << lcSub.length << ", Substring: \"" << lcSub.substring << "\"\n\n";

    // ---------- Longest Common Subsequence ----------
    cout << "=== Longest Common Subsequence ===\n";
    string a = "fosh";
    string b = "fish";
    auto lcs = longestCommonSubsequence(a, b);
    cout << "Strings: \"" << a << "\" vs \"" << b << "\"\n";
    cout << "Length: " << lcs.length << ", Subsequence: \"" << lcs.subsequence << "\"\n";

    return 0;
}