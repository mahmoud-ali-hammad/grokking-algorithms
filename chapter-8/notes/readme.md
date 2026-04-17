# 📘 Grokking Algorithms — Chapter 8 Notes

## Greedy Algorithms and NP-Complete Problems

This chapter introduces **greedy algorithms**, **approximation algorithms**, and how to recognize **NP-complete** problems.

---

## 1) What this chapter teaches

- How greedy algorithms work: make the best local choice at each step
- Why some hard problems have no known fast exact solution (NP-complete)
- When to stop chasing perfect answers and use approximations
- Why greedy methods are often fast and practical

---

## 2) Greedy strategy

A greedy algorithm repeatedly chooses the **locally best** move.

- Simple to implement
- Usually fast
- Sometimes optimal, sometimes only near-optimal

---

## 3) Classroom scheduling problem (interval scheduling)

Goal: choose maximum number of non-overlapping classes in one classroom.

Greedy rule:

1. Pick the class that **ends earliest**
2. Remove overlapping classes
3. Repeat

✅ This greedy strategy gives the **optimal** solution for this problem.

---

## 4) Knapsack example (where simple greedy can fail)

If you always pick the most expensive item that still fits:

- you may miss a better combination

So simple greedy is not always globally optimal (especially for 0/1 knapsack).

---

## 5) Set-covering problem

Goal: choose minimum stations to cover all required states.

Exact approach:

- enumerate all subsets (power set)
- exponential time `O(2^n)`

Greedy approximation:

1. Pick station covering the most uncovered states
2. Repeat until all states are covered

This is fast and often close to optimal.

---

## 6) NP-complete intuition

NP-complete problems are “famously hard”:

- no known polynomial-time exact algorithm
- brute force often grows exponentially/factorially

Examples:

- Set cover (optimization version)
- Traveling Salesperson Problem (TSP)
- Clique-related problems (decision forms)

---

## 7) Traveling salesperson (TSP)

Exact TSP requires checking many permutations:

- grows as factorial (`n!`)
- infeasible for large `n`

Greedy approximation idea:

- start anywhere
- always go to nearest unvisited city (nearest-neighbor heuristic)

Not always optimal, but fast and practical.

---

## 8) Signs your problem might be NP-complete

- Works on small input, explodes on larger input
- Requires checking “all combinations”
- Requires trying “every possible ordering/arrangement”
- Sequence/set optimization with global constraints
- Can be reduced to set cover or TSP style problem

---

## 9) Exercise answers (8.3–8.8)

### 8.3 Quicksort

❌ Not a greedy algorithm (divide-and-conquer sort)

### 8.4 Breadth-first search

❌ Not greedy (level-order graph traversal)

### 8.5 Dijkstra’s algorithm

✅ Often considered greedy (finalizes cheapest frontier node each step)

### 8.6 Postman shortest route visiting 20 homes

✅ NP-complete style (TSP formulation)

### 8.7 Largest clique

✅ NP-complete / NP-hard family

### 8.8 Minimum colors for map (graph coloring)

✅ NP-complete optimization family

---

## 10) Key takeaways

- Greedy = local optimum first.
- Some problems can’t be solved exactly fast (as far as known).
- For NP-complete problems, use approximation/heuristics.
- Greedy algorithms are great approximation tools: simple + fast.
- Know when “good enough” beats “perfect but too slow.”

---
