# 📘 Grokking Algorithms — Chapter 11 Notes

## Where to Go Next

Chapter 11 gives a guided tour of important algorithms and data structures not fully covered earlier, plus ideas on where to continue learning.

---

## 1) What this chapter teaches

- A high-level overview of advanced topics:
  - Trees / balanced trees
  - Inverted indexes
  - Fourier transform
  - Parallel and distributed algorithms (MapReduce)
  - Bloom filters / HyperLogLog
  - SHA and locality-sensitive hashing
  - Diffie-Hellman key exchange
  - Linear programming
- How to choose topics based on your interests (databases, search, security, optimization, large-scale systems)

---

## 2) Trees

A **binary search tree (BST)** maintains ordering:

- left subtree values < node
- right subtree values > node

### Complexity

- Search/insert/delete average: `O(log n)`
- Worst case (unbalanced): `O(n)`

Balanced variants improve reliability:

- Red-Black Trees
- AVL Trees
- B-Trees (common in databases)

---

## 3) Inverted index (search engines)

Maps:

- **word → list of documents/pages containing that word**

This enables fast lookup for queries like:

- “show pages containing `hello`”

Foundational for text search systems.

---

## 4) Fourier Transform

Transforms signal from time/spatial domain into frequency components.

Use cases:

- Audio processing and compression (e.g., MP3 concepts)
- Image compression (e.g., JPEG-related transforms)
- Signal analysis, earthquake analysis, DNA analysis, music recognition

---

## 5) Parallel and distributed algorithms

As CPUs scale by cores, performance gains often require parallelism.

Challenges:

- task splitting overhead
- merge/synchronization overhead
- load balancing

### MapReduce

Distributed model using:

- **Map**: transform each input item
- **Reduce**: aggregate mapped outputs

Useful for huge datasets across many machines.

---

## 6) Probabilistic data structures

### Bloom Filter

- Very memory-efficient membership testing
- Possible false positives
- No false negatives

Great when approximate membership is acceptable.

### HyperLogLog

- Approximates number of distinct elements (cardinality)
- Extremely memory-efficient vs exact counting

---

## 7) SHA and hashing in security

SHA family maps input → fixed-size digest.

Use cases:

- File integrity checking
- Password verification (hash comparison)

Important notes:

- Small input change causes very different hash
- Prefer modern secure choices (SHA-2/SHA-3)
- For passwords, dedicated password hash functions (e.g., bcrypt/Argon2) are preferred over plain SHA

---

## 8) Locality-sensitive hashing (LSH)

Unlike SHA, LSH keeps similar inputs mapped to similar hashes.

Useful for:

- near-duplicate detection
- plagiarism checks
- document similarity filtering

Example concept: SimHash.

---

## 9) Diffie-Hellman key exchange

Allows two parties to establish a shared secret over an insecure channel using:

- public values
- private secrets

Foundation for secure communication protocols.

---

## 10) Linear programming

General framework for maximizing/minimizing objectives under linear constraints.

Examples:

- production planning
- resource allocation
- scheduling and optimization

Often solved using simplex or interior-point methods.

---

## 11) Final takeaways

- You now have a strong algorithmic foundation.
- Pick one domain and go deeper:
  - databases → B-trees, indexing
  - search → inverted indexes, ranking
  - security → SHA, key exchange, crypto
  - scalability → parallel/distributed systems
  - optimization → LP, advanced DP, graph optimization

---
