# 📘 Grokking Algorithms — Chapter 2 Notes

## Arrays, Linked Lists, and Selection Sort

This chapter introduces two foundational data structures (**arrays** and **linked lists**) and a basic sorting algorithm (**selection sort**).  
Even if most languages provide built-in sorting, understanding selection sort helps build intuition for faster sorts later (like quicksort).

---

## 1) Prerequisites

To fully understand this chapter’s performance analysis, you should know:

- **Big O notation**
- **Logarithms** (from Chapter 1)

---

## 2) Storing a list in memory

When building apps (like a todo app), you often need to store a list of items in memory.

Example:  
`["Buy milk", "Read 10 pages", "Workout"]`

Two common ways to store such data:

- **Array**
- **Linked list**

---

## 3) Arrays

### How arrays are stored

In an array, elements are stored in **contiguous memory locations** (next to each other).

Think of memory as a row of seats in a movie theater:

- If your group grows and no adjacent seat is free, you may need to move the whole group to a bigger open block.

### Issue with array growth

If the array runs out of space, you may need to allocate a new larger block and copy items.

A common workaround:

- Reserve extra capacity in advance (pre-allocation), e.g., allocate 10 slots even if you only need 3 now.

### Downsides of pre-allocation

- You might waste memory if extra slots are never used.
- You can still outgrow capacity and need to move data anyway.

### Performance intuition

- **Reading by index** is fast (`O(1)`) because position is directly calculable.
- **Inserting/deleting in middle/beginning** is slower (`O(n)`) because elements must shift.

---

## 4) Linked Lists

### How linked lists are stored

Linked list elements can be scattered anywhere in memory.  
Each node stores:

1. The value
2. The address (reference) of the next node

So nodes are connected by pointers instead of physical adjacency.

### Trade-off

- You **cannot** instantly jump to element #50.
- To read the last element, you start at the first and follow links one by one.

### Performance intuition

- **Insert/delete** at known position (especially near head) is efficient (`O(1)` after locating position).
- **Random access** is slow (`O(n)`), since traversal is sequential.

---

## 5) Random access vs sequential access

- **Random access**: Jump directly to any element by index (arrays).
- **Sequential access**: Read items one by one from the start (linked lists).

This is one major reason arrays are heavily used in practice.

---

## 6) Array vs Linked List (common operations)

| Operation           |                           Array |                       Linked List |
| ------------------- | ------------------------------: | --------------------------------: |
| Read by index       |                          `O(1)` |                            `O(n)` |
| Insert at beginning |                          `O(n)` |                          `O(1)`\* |
| Insert in middle    |                          `O(n)` |                          `O(1)`\* |
| Insert at end       | `O(1)` amortized / `O(n)` worst | `O(1)`\* (if tail known) / `O(n)` |
| Delete at beginning |                          `O(n)` |                            `O(1)` |
| Delete in middle    |                          `O(n)` |                          `O(1)`\* |
| Delete at end       |                          `O(1)` |              `O(n)` (singly list) |

\* For linked lists, this assumes you already have a reference to the insertion/deletion position.  
If you must search first, add `O(n)` traversal cost.

---

## 7) Selection Sort

Selection sort repeatedly finds the smallest item from the unsorted part and moves it to the sorted part.

### Example

Unsorted list:  
`[5, 3, 6, 2, 10]`

Passes:

1. Smallest is `2` → `[2, 5, 3, 6, 10]`
2. Smallest in remaining is `3` → `[2, 3, 5, 6, 10]`
3. Then `5`, then `6`, then `10`

Final sorted list:  
`[2, 3, 5, 6, 10]`

### Runtime

Selection sort performs about:

- `n + (n-1) + (n-2) + ... + 1` comparisons
- This is approximately `n² / 2`
- Big O ignores constants like `1/2`, so runtime is:

✅ **`O(n²)`**

---

## 8) Why `O(n²)` even though checks decrease each round?

Good question: each round examines fewer elements.

Total work is still proportional to:

`n + (n-1) + ... + 1 = n(n+1)/2`

That simplifies to roughly `n²/2`, and Big O drops constants → `O(n²)`.

---

## 9) Key Takeaways (Chapter Summary)

- Computer memory is like a giant set of drawers (addresses).
- For storing multiple elements, common choices are **arrays** and **linked lists**.
- Arrays store elements contiguously; linked lists connect scattered nodes by references.
- Arrays give fast random reads.
- Linked lists give efficient inserts/deletes (when position is known).
- Selection sort is simple but slow on large inputs: `O(n²)`.
- Built-in sorting is usually better in real projects, but learning selection sort builds algorithmic intuition.
- In many low-level or statically typed contexts, arrays typically store elements of the same type.

---
