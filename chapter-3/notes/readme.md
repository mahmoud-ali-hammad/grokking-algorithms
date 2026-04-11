# 📘 Grokking Algorithms — Chapter 3 Notes

## Recursion and the Call Stack

This chapter introduces **recursion**, a key programming technique used in many important algorithms.

---

## 1) What you learn in this chapter

- What recursion is and when to use it
- How every recursive solution needs:
  - a **base case** (stop condition)
  - a **recursive case** (self-call)
- How recursion relies on the **call stack**
- Why recursion can be elegant but may use more memory than loops

---

## 2) Recursion in simple words

**Recursion** is when a function calls itself to solve a smaller version of the same problem.

It is often useful when:

- the problem naturally contains smaller subproblems
- recursive structure makes code clearer than a loop

> Recursion is often about code clarity, not raw speed.  
> In some cases, loops are more memory-efficient.

---

## 3) Example: Searching nested boxes for a key

Imagine boxes inside boxes in an attic.

### Iterative approach (loop)

- Keep a pile/stack of boxes to inspect
- While pile is not empty:
  - open a box
  - add inner boxes to pile
  - stop if key is found

### Recursive approach

- Open a box
- If an item is a box, recursively search inside it
- If an item is a key, stop

Both solve the same problem, but recursion can feel more natural for nested structures.

---

## 4) Base case and recursive case

A recursive function must have **two parts**:

1. **Base case**  
   Condition where function stops calling itself.
2. **Recursive case**  
   Function calls itself with a smaller/simpler input.

Without a base case, recursion never ends (infinite recursion).

### Countdown example

```python
def countdown(i):
    print(i)
    if i <= 0:      # base case
        return
    else:           # recursive case
        countdown(i - 1)
```

---

## 5) The stack data structure (push/pop)

A **stack** supports two main operations:

- **push**: add item to top
- **pop**: remove/read top item

LIFO order: **Last In, First Out**.

---

## 6) The call stack

When functions run, your computer uses a special stack called the **call stack**.

Each function call gets a stack frame containing:

- function parameters
- local variables
- return position (where to continue after function finishes)

### Important idea

If function `A` calls function `B`:

- `A` is paused
- `B` runs
- when `B` returns, execution resumes in `A`

---

## 7) Recursion + call stack (factorial example)

Factorial definition:

- `5! = 5 × 4 × 3 × 2 × 1`
- recursively: `n! = n × (n-1)!`

---

## 8) Cost of recursion

Recursion is convenient because the call stack automatically tracks unfinished work.

But there is a memory cost:

- each function call adds a stack frame
- too many calls can cause a **stack overflow**

If recursion depth is too high, options include:

- rewrite with a loop
- use tail recursion (advanced, language-dependent)

---

## 9) Exercises explained

### 3.1 From a call stack snapshot, what can you infer?

You can infer:

- which function is currently running (top frame)
- which function called it (frames below)
- local variable values stored per frame
- what calls are paused and waiting

### 3.2 What happens if recursion runs forever?

- stack keeps growing with new frames
- memory is eventually exhausted
- program crashes with stack overflow / recursion depth error

---

## 10) Key takeaways

- Recursion = function calling itself.
- Every recursive function must have a base case.
- Recursive case breaks problem into smaller version.
- Call stack stores function state for each call.
- Recursion can make code elegant and easier to reason about.
- Deep recursion can be memory-heavy and may crash if unbounded.
