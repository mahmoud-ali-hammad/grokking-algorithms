# 📘 Grokking Algorithms — Chapter 4 Notes

## Divide and Conquer + Quicksort

Chapter 4 introduces **Divide and Conquer (D&C)**, a powerful problem-solving strategy, and applies it to **quicksort**, one of the most practical sorting algorithms.

---

## 1) What this chapter teaches

- A general problem-solving technique: **Divide and Conquer**
- How to think recursively with:
  - **base case**
  - **recursive case**
- How quicksort works step by step
- Why quicksort is fast in practice
- Why constants (hidden in Big O) sometimes matter in real life

---

## 2) Divide and Conquer (D&C)

D&C is not one fixed algorithm; it’s a **strategy**:

1. Find the **base case** (smallest solvable input)
2. Reduce the problem toward that base case recursively

This mindset helps solve new problems when no obvious direct algorithm appears.

---

## 3) Visual intuition (farm plot problem)

Problem:  
You have a rectangular farm (e.g., `1680 x 640`) and want to divide it into the **largest possible equal squares**.

D&C idea:

- Fit the largest possible square
- Apply the same logic to the remaining rectangle
- Repeat until no remainder

This process is equivalent to the **Euclidean algorithm** (for GCD).  
For `1680 x 640`, largest square size is `80 x 80`.

---

## 4) D&C on arrays (recursive sum)

Example problem: Sum all numbers in an array.

### Iterative version

```python
def sum_arr(arr):
    total = 0
    for x in arr:
        total += x
    return total
```

### Recursive idea

- Base case: empty array (`0`) or one element (that element)
- Recursive case: first element + sum(remaining elements)

```python
def sum_arr(arr):
    if arr == []:
        return 0
    return arr[0] + sum_arr(arr[1:])
```

> Tip: For recursive array problems, base case is often `[]` or length `1`.

---

## 5) Quicksort

Quicksort is a sorting algorithm based on D&C.

### Core steps

1. Choose a **pivot**
2. **Partition** array into:
   - elements `<= pivot`
   - pivot
   - elements `> pivot`
3. Recursively quicksort left and right parts
4. Combine: `sorted_left + [pivot] + sorted_right`

### Base case

Arrays of size `0` or `1` are already sorted.

### Python implementation

```python
def quicksort(array):
    if len(array) < 2:
        return array  # base case
    pivot = array[0]
    less = [i for i in array[1:] if i <= pivot]
    greater = [i for i in array[1:] if i > pivot]
    return quicksort(less) + [pivot] + quicksort(greater)

print(quicksort([10, 5, 2, 3]))  # [2, 3, 5, 10]
```

---

## 6) Quicksort runtime: best, average, worst

Quicksort performance depends on pivot quality.

- **Best case**: pivot splits array roughly in half each time

  - levels: `O(log n)`
  - work per level: `O(n)`
  - total: **`O(n log n)`**

- **Worst case**: pivot gives very uneven splits (e.g., sorted input + first-element pivot)

  - levels: `O(n)`
  - work per level: `O(n)`
  - total: **`O(n²)`**

- **Average case** (with random pivots):
  - typically **`O(n log n)`**

---

## 7) Why quicksort is often faster than merge sort in practice

Both are often `O(n log n)` in common scenarios, but:

- Big O hides constants
- Quicksort usually has smaller constants
- Quicksort often performs very well on real datasets

So same Big O does not always mean same real-world speed.

---

## 8) Big O exercises answers (4.5–4.8)

- **4.5** Print each element in array → **`O(n)`**
- **4.6** Double each element in array → **`O(n)`**
- **4.7** Double only first element → **`O(1)`**
- **4.8** Multiplication table across all elements (nested loop over same array) → **`O(n²)`**

---

## 9) Key takeaways

- D&C solves problems by reducing them into smaller versions.
- For list recursion, base case is often empty or single-element list.
- Quicksort is a major D&C algorithm and very practical.
- Choose pivots carefully (random pivot is a good default).
- Average quicksort runtime is `O(n log n)`.
- Constants in Big O can matter when comparing algorithms with same complexity class.
- Constants matter less when comparing very different growth rates (e.g., `O(log n)` vs `O(n)`).

---
