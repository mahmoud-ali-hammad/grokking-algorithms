#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>

// Optional SHA-256 (requires OpenSSL):
// g++ -std=c++17 chapter11_overview_demo.cpp -lssl -lcrypto -o ch11
#include <openssl/sha.h>

using namespace std;

/* =========================================================
   1) Binary Search Tree (basic)
   ========================================================= */
struct BSTNode {
    string key;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
    BSTNode(const string& k) : key(k) {}
};

class BST {
private:
    BSTNode* root = nullptr;

    BSTNode* insert(BSTNode* node, const string& key) {
        if (!node) return new BSTNode(key);
        if (key < node->key) node->left = insert(node->left, key);
        else if (key > node->key) node->right = insert(node->right, key);
        return node;
    }

    bool search(BSTNode* node, const string& key) const {
        if (!node) return false;
        if (node->key == key) return true;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }

public:
    void insert(const string& key) { root = insert(root, key); }
    bool search(const string& key) const { return search(root, key); }
};

/* =========================================================
   2) Inverted Index
   ========================================================= */
unordered_map<string, set<string>> buildInvertedIndex(
    const unordered_map<string, vector<string>>& docsWords
) {
    unordered_map<string, set<string>> index;
    for (const auto& [doc, words] : docsWords) {
        for (const auto& w : words) {
            index[w].insert(doc);
        }
    }
    return index;
}

/* =========================================================
   3) Map + Reduce style demo (single-machine simulation)
   ========================================================= */
vector<int> mapDouble(const vector<int>& arr) {
    vector<int> out;
    out.reserve(arr.size());
    for (int x : arr) out.push_back(2 * x);
    return out;
}

int reduceSum(const vector<int>& arr) {
    int s = 0;
    for (int x : arr) s += x;
    return s;
}

/* =========================================================
   4) SHA-256 helper
   ========================================================= */
string sha256(const string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);

    static const char* hex = "0123456789abcdef";
    string out;
    out.reserve(SHA256_DIGEST_LENGTH * 2);
    for (unsigned char c : hash) {
        out.push_back(hex[c >> 4]);
        out.push_back(hex[c & 0x0F]);
    }
    return out;
}

/* =========================================================
   5) Diffie-Hellman (toy example, not production-safe)
   ========================================================= */
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    // ---------- BST ----------
    cout << "=== Binary Search Tree Demo ===\n";
    BST bst;
    bst.insert("david");
    bst.insert("manning");
    bst.insert("maggie");
    bst.insert("alice");

    cout << "Search 'maggie': " << (bst.search("maggie") ? "found" : "not found") << "\n";
    cout << "Search 'tom': " << (bst.search("tom") ? "found" : "not found") << "\n\n";

    // ---------- Inverted Index ----------
    cout << "=== Inverted Index Demo ===\n";
    unordered_map<string, vector<string>> docs = {
        {"A", {"hi", "there"}},
        {"B", {"hi"}},
        {"C", {"there"}}
    };
    auto index = buildInvertedIndex(docs);

    for (const auto& query : {"hi", "there"}) {
        cout << "Query '" << query << "' -> pages: ";
        if (index.count(query)) {
            bool first = true;
            for (const auto& page : index[query]) {
                if (!first) cout << ", ";
                cout << page;
                first = false;
            }
        }
        cout << "\n";
    }
    cout << "\n";

    // ---------- MapReduce style ----------
    cout << "=== Map + Reduce Demo ===\n";
    vector<int> arr = {1, 2, 3, 4, 5};
    auto doubled = mapDouble(arr);
    int total = reduceSum(doubled);

    cout << "Mapped (x2): ";
    for (int x : doubled) cout << x << " ";
    cout << "\nReduced sum: " << total << "\n\n";

    // ---------- SHA-256 ----------
    cout << "=== SHA-256 Demo ===\n";
    string text1 = "hello world";
    string text2 = "hello worle"; // one char changed
    cout << "SHA256(\"" << text1 << "\") = " << sha256(text1) << "\n";
    cout << "SHA256(\"" << text2 << "\") = " << sha256(text2) << "\n";
    cout << "(Notice how very different hashes are.)\n\n";

    // ---------- Diffie-Hellman (toy) ----------
    cout << "=== Diffie-Hellman Toy Demo ===\n";
    // Public values
    long long p = 23; // prime (tiny for demo only)
    long long g = 5;  // primitive root modulo p

    // Private secrets
    long long a = 6;  // Alice private
    long long b = 15; // Bob private

    // Public keys
    long long A = modPow(g, a, p); // Alice sends A
    long long B = modPow(g, b, p); // Bob sends B

    // Shared secret
    long long secretAlice = modPow(B, a, p);
    long long secretBob   = modPow(A, b, p);

    cout << "Public p=" << p << ", g=" << g << "\n";
    cout << "Alice public A=" << A << ", Bob public B=" << B << "\n";
    cout << "Shared secret (Alice): " << secretAlice << "\n";
    cout << "Shared secret (Bob):   " << secretBob << "\n";
    cout << "Match: " << (secretAlice == secretBob ? "YES" : "NO") << "\n";

    return 0;
}