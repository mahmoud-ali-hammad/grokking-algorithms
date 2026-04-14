# 📘 Grokking Algorithms — Chapter 5 Notes

## Hash Tables

Hash tables are one of the most useful data structures in programming.  
They provide very fast lookups, inserts, and deletes in the average case.

---

## 1) What this chapter teaches

- What a hash table is and why it is powerful
- How hash tables work internally:
  - hash functions
  - collisions
  - load factor
  - resizing
- Common real-world use cases:
  - lookups
  - duplicate detection
  - caching

---

## 2) Motivation: faster than searching a list

If you store item prices in an unsorted list, lookup is `O(n)` (linear search).  
If sorted, binary search gives `O(log n)`.  
But with a hash table, lookup is typically **`O(1)` average case**.

That’s why hash tables feel “instant” for key-based access.

---

## 3) What is a hash table?

A hash table combines:

1. **Array** (storage)
2. **Hash function** (maps key → valid index)

A hash table stores **key-value pairs**:

- key: `"apple"`
- value: `0.67`

---

## 4) Hash function basics

A hash function maps input data to an index.

### Good hash function requirements

- **Deterministic/consistent**: same key always gives same index
- **Good distribution**: different keys spread across slots
- **Valid range**: output must fit array bounds

### Consistency exercises (5.1–5.4)

- `f(x) = 1` → **consistent** (but poor distribution)
- `f(x) = rand()` → **not consistent**
- `f(x) = next_empty_slot()` → **not consistent**
- `f(x) = len(x)` → **consistent** (may still collide a lot)

---

## 5) Python dictionary example (hash table)

```python
book = {}
book["apple"] = 0.67
book["milk"] = 1.49
book["avocado"] = 1.49

print(book["avocado"])  # 1.49
```

In Python, `dict` is a hash table.

---

## 6) Main use cases

### A) Fast lookups

Example: phone book (name → number)

```python
phone_book = {}
phone_book["jenny"] = 8675309
phone_book["emergency"] = 911
print(phone_book["jenny"])
```

### B) Prevent duplicates

Example: voting system (person can vote once)

```python
voted = {}

def check_voter(name):
    if voted.get(name):
        print("kick them out!")
    else:
        voted[name] = True
        print("let them vote!")
```

### C) Caching

Store expensive results so they can be reused quickly.

```python
cache = {}

def get_page(url):
    if cache.get(url):
        return cache[url]
    data = get_data_from_server(url)
    cache[url] = data
    return data
```

---

## 7) Collisions

A **collision** happens when two keys map to the same index.

Example:

- `"apple"` and `"avocado"` both map to slot 0

One simple handling strategy: **chaining** with linked lists at each slot.

Problem:

- too many collisions → long chains → slower operations

So performance strongly depends on:

- hash function quality
- table size/load factor

---

## 8) Performance summary

### Average case (good hash + controlled load factor)

- Search: `O(1)`
- Insert: `O(1)`
- Delete: `O(1)`

### Worst case (many collisions)

- Search/Insert/Delete: `O(n)`

Hash tables are fast _on average_, but can degrade if poorly configured.

---

## 9) Load factor and resizing

### Load factor formula

\[
\text{load factor} = \frac{\text{number of items}}{\text{number of slots}}
\]

Examples:

- 2 items in 5 slots → `0.4`
- 3 items in 3 slots → `1.0`

### Why it matters

Higher load factor usually means more collisions.

### Resizing rule

When load factor becomes high (common threshold: **> 0.7**), resize:

- create a bigger array (often 2× size)
- rehash/reinsert all items

Resizing is expensive occasionally, but average operations remain `O(1)` (amortized behavior).

---

## 10) Hash function distribution exercises (5.5–5.7)

Given hash functions:

a) returns constant `1`  
b) index = length of string  
c) index = first character  
d) sum(prime value of chars) mod table size

### 5.5 Names: Esther, Ben, Bob, Dan

Best: **d**  
Acceptable-ish: c (not ideal), b (collisions likely), a (worst)

### 5.6 Battery sizes: A, AA, AAA, AAAA

Best: **b** (different lengths map cleanly)  
Also reasonable: **d**  
Poor: c (all start with A), a (worst)

### 5.7 Titles: Maus, Fun Home, Watchmen

Best: **d**  
Also okay here: **b** and **c** may work for this tiny set  
Worst: a

---

## 11) Key takeaways

- Hash table = hash function + array.
- Great for key→value mapping.
- Excellent for lookups, caching, and duplicate detection.
- Collisions are unavoidable; minimize them with a good hash function.
- Keep load factor under control (commonly resize after `> 0.7`).
- In practice, use your language’s built-in implementation (`dict`, `map`, etc.).

---
