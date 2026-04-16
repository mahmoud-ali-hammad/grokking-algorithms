# 📘 Grokking Algorithms — Chapter 7 Notes

## Dijkstra’s Algorithm (Shortest Path in Weighted Graphs)

This chapter extends graph problems from unweighted to **weighted graphs** and introduces **Dijkstra’s algorithm** for finding minimum-cost paths.

---

## 1) What this chapter teaches

- What a **weighted graph** is
- Why BFS is not enough for weighted shortest paths
- How **Dijkstra’s algorithm** works step by step
- How to reconstruct the actual shortest path using **parents**
- Why Dijkstra fails with **negative-weight edges**
- Relationship between cycles, DAGs, and shortest-path assumptions

---

## 2) BFS vs Dijkstra

- **BFS** (Chapter 6): shortest path by **fewest edges** (unweighted graphs)
- **Dijkstra**: shortest path by **minimum total weight/cost** (weighted graphs with non-negative weights)

If edges have travel times, prices, risks, etc., use Dijkstra (not BFS).

---

## 3) Core idea of Dijkstra

At each step:

1. Pick the unprocessed node with the smallest known cost
2. Relax/update costs of its neighbors
3. If a cheaper path is found, update:
   - `cost[neighbor]`
   - `parent[neighbor]`
4. Mark node as processed
5. Repeat until all reachable nodes are processed

---

## 4) Terminology

- **Weight**: value on an edge (time, money, distance, ...)
- **Weighted graph**: graph with edge weights
- **Unweighted graph**: graph without edge weights
- **Cycle**: path that returns to the same node

> In this chapter’s framing, use Dijkstra on directed graphs with non-negative weights.

---

## 5) Why parents table matters

Dijkstra computes best costs, but to get the full path, track `parent` for each node.

Example:

- `parent["fin"] = "a"`
- `parent["a"] = "b"`
- `parent["b"] = "start"`

Then path is reconstructed backward:
`fin <- a <- b <- start`  
Reverse it → `start -> b -> a -> fin`

---

## 6) Important limitation: negative edges

Dijkstra assumes once a node is finalized (processed), no cheaper path to it will appear later.  
This assumption breaks with negative edges.

So:

- ✅ Dijkstra works with **non-negative** edge weights
- ❌ Dijkstra is not correct with **negative** edge weights
- Use **Bellman-Ford** when negative weights exist

---

## 7) Complexity

With a simple implementation:

- `O(V^2 + E)` (or commonly `O(V^2)` in dense settings)

With a min-priority queue (heap):

- `O((V + E) log V)` (common practical form)

---

## 8) Key takeaways

- Use BFS for unweighted shortest paths.
- Use Dijkstra for weighted shortest paths (all weights >= 0).
- Track both `costs` and `parents`.
- Negative-weight edges require Bellman-Ford.
- “Shortest” can mean minimal time, money, risk, not only physical distance.

---
