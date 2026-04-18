# 📘 Grokking Algorithms — Chapter 9 Notes

## Dynamic Programming

This chapter introduces **dynamic programming (DP)**: solving a hard optimization problem by breaking it into smaller subproblems, solving each once, and building up to the final answer.

---

## 1) What this chapter teaches

- How to recognize DP-style optimization problems
- How to model problems using a **grid/table**
- How to define and fill DP states from smaller subproblems
- DP solutions for:
  - 0/1 Knapsack
  - Longest Common Substring
  - Longest Common Subsequence

---

## 2) Knapsack problem (0/1)

Given:

- Capacity limit (e.g., 4 lb)
- Items with weight + value
  Goal:
- Maximize total value without exceeding capacity
- Each item can be taken at most once

Brute force checks all subsets:

- `O(2^n)` (too slow for large n)

DP gives optimal solution efficiently by reusing subproblem answers.

---

## 3) Knapsack DP intuition

Build a table:

- Rows = items considered so far
- Columns = capacities (0..W)

State:

- `dp[i][w]` = max value using first `i` items with capacity `w`

Transition:

- If item `i` too heavy: `dp[i][w] = dp[i-1][w]`
- Else:
  - skip item: `dp[i-1][w]`
  - take item: `value[i] + dp[i-1][w - weight[i]]`
  - choose max

This is exactly “solve smaller knapsacks first, then bigger one.”

---

## 4) DP properties highlighted in chapter

- DP is for **optimization under constraints**
- Works when problem can be split into **discrete subproblems**
- Typical implementation uses a **grid/table**
- Each cell stores best known answer for a subproblem
- Final answer often in last row/column (but not always, e.g., longest common substring)

---

## 5) Longest Common Substring (contiguous)

Example idea:

- Compare two strings and find longest **continuous** matching block

State:

- `dp[i][j]` = length of longest common substring ending at `a[i-1]` and `b[j-1]`

Transition:

- if chars equal: `dp[i][j] = dp[i-1][j-1] + 1`
- else: `dp[i][j] = 0`

Answer:

- Maximum value anywhere in table (not necessarily last cell)

---

## 6) Longest Common Subsequence (not necessarily contiguous)

Find longest sequence of characters in same order (can skip characters).

State:

- `dp[i][j]` = LCS length for prefixes `a[0..i-1]`, `b[0..j-1]`

Transition:

- if chars equal: `dp[i][j] = dp[i-1][j-1] + 1`
- else: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`

Answer:

- `dp[n][m]`

---

## 7) Limits and caveats from chapter

- If fractional items are allowed, this becomes fractional knapsack (greedy works there)
- Dependencies between items can break simple DP modeling
- Granularity matters (e.g., 0.5 lb capacities require finer columns)
- No single universal DP formula: design state + transitions per problem

---

## 8) Real-world applications

- `diff` tools (e.g., git diff)
- Spell checking and string similarity (Levenshtein-related ideas)
- Bioinformatics (DNA/protein sequence comparison)
- Text layout/word wrap optimizations

---

## 9) Key takeaways

- DP = solve once, reuse many times.
- Think in terms of **state**, **transition**, **base cases**.
- Build from small subproblems to large problem.
- Excellent for optimization problems with overlapping subproblems.

---
