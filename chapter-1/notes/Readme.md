# 📘 Grokking Algorithms — Chapter Notes

These are my summarized notes and highlights from **Grokking Algorithms** after reading each chapter.  
I rewrote and organized the content for clarity and added small examples.

---

## 1) What is an algorithm?

An **algorithm** is a set of instructions for accomplishing a task.

- In practice, every program contains algorithms.
- In this book, each topic usually follows this flow:
  1. Explain the algorithm
  2. Show an example
  3. Analyze running time with **Big O notation**
  4. Discuss related problem types solved by the same idea

> Note: Most algorithms already have implementations in popular languages, but understanding their **trade-offs** is what matters.

---

## 2) Why trade-offs matter

Knowing how to code an algorithm is not enough.  
You should compare algorithms based on trade-offs such as:

- **Speed (time complexity)**
- **Memory usage (space complexity)**
- **Simplicity vs performance**

---

## 3) Prerequisite knowledge

Basic algebra is enough to start.

Example:

- If `f(x) = x * 2`, then `f(5) = 10`

If this is easy for you, you’re ready.

---

## 4) Binary Search (core idea)

**Binary search** works on a **sorted** list.

- Input: sorted list + target value
- Output:
  - index/position of target if found
  - `null` (or not found) otherwise

### Why it’s fast

Instead of checking one by one, it repeatedly cuts the search space in half.

- Simple search worst case: `n` checks
- Binary search worst case: `log2(n)` checks

Example comparison:

- `n = 100`
  - simple search: up to 100 checks
  - binary search: up to 7 checks
- `n = 4,000,000,000`
  - simple search: up to 4 billion checks
  - binary search: up to 32 checks

---

## 5) Logarithms (quick intuition)

`log10(100) = 2` means:

> “How many times do we multiply 10 by itself to get 100?”

Answer: `10 * 10`, so 2 times.

Logarithms are the inverse (flip side) of exponentials.

---

## 6) Running time and Big O notation

When analyzing algorithms, we usually care about how performance grows as input size grows.

**Big O notation** describes growth rate, not exact seconds.

- Binary search: `O(log n)`
- Simple/linear search: `O(n)`

### Important

Big O is commonly discussed as a **worst-case bound**.

- Example: searching a phone book linearly can require checking every entry in the worst case → `O(n)`

---

## 7) Common Big O classes (with examples)

- `O(log n)` — logarithmic time
  - Example: binary search
- `O(n)` — linear time
  - Example: simple search
- `O(n log n)` — efficient sorting
  - Example: quicksort (average case)
- `O(n²)` — slower nested-loop behavior
  - Example: selection sort
- `O(n!)` — extremely slow for larger n
  - Example: brute-force traveling salesperson

---

## 8) Key takeaways

- Binary search is much faster than simple search on large sorted lists.
- `O(log n)` scales much better than `O(n)` as data grows.
- Algorithm speed is not measured in seconds in Big O analysis.
- We measure how operation count grows with input size.
- Big O helps compare algorithms and choose better trade-offs.

---
