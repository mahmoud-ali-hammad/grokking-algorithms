# 📘 Grokking Algorithms — Chapter 6 Notes

## Breadth-First Search (BFS) and Graph Basics

This chapter introduces **graphs** and **breadth-first search (BFS)**, one of the most useful graph algorithms.

---

## 1) What this chapter teaches

- How to model real problems as **graphs**
- How BFS answers:
  1. Is there a path from A to B?
  2. What is the shortest path from A to B? (fewest edges/steps)
- Difference between **directed** and **undirected** graphs
- Why BFS needs a **queue (FIFO)**
- Why we track **visited nodes** (to avoid repeated work/infinite loops)
- Idea of **topological sort** for dependency ordering
- What a **tree** is (special graph)

---

## 2) Graph fundamentals

A graph has:

- **Nodes (vertices)**: entities (people, cities, tasks)
- **Edges**: connections between nodes

### Neighbors

If node A has a direct edge to node B, then B is A’s neighbor.

### Directed vs undirected

- **Directed graph**: edges have direction (`A -> B`)
- **Undirected graph**: no direction (`A -- B`), relationship is two-way

---

## 3) Why BFS?

BFS is ideal for **unweighted shortest path** problems (fewest hops/steps), such as:

- Fewest bus transfers
- Fewest edits in word transformation
- Closest person/resource in a social network

BFS explores level by level:

- first-degree neighbors first
- then second-degree
- then third-degree, etc.

So the first time you reach a target, it is guaranteed to be the shortest path (in edge count).

---

## 4) Queue: required data structure for BFS

BFS must process nodes in insertion order.

- **Queue (FIFO)**: First In, First Out ✅
- **Stack (LIFO)**: Last In, First Out ❌ for shortest-path BFS

If order is not FIFO, shortest-path guarantee breaks.

---

## 5) Graph representation in Python

A common representation is an adjacency list via dictionary:

```python
graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []
```

---

## 6) BFS implementation (Python)

```python
from collections import deque

def person_is_seller(name):
    return name[-1] == "m"   # example condition

def search(graph, name):
    search_queue = deque()
    search_queue += graph[name]
    searched = set()

    while search_queue:
        person = search_queue.popleft()
        if person not in searched:
            if person_is_seller(person):
                print(person + " is a mango seller!")
                return True
            search_queue += graph[person]
            searched.add(person)
    return False
```

### Why `searched` is necessary

- Prevents checking same person multiple times
- Avoids infinite loops in cyclic graphs

---

## 7) BFS time complexity

Let:

- `V` = number of vertices (nodes)
- `E` = number of edges

BFS complexity is:

- **Time:** `O(V + E)`
- **Space:** `O(V)` (queue + visited tracking)

---

## 8) Topological sort (dependency ordering)

If tasks have dependencies (A must happen before B), represent as a directed graph.

A **topological sort** outputs a valid order where each dependency appears before dependent tasks.

Example idea:

- wake up → brush teeth → eat breakfast
- shower may be independent and can move as long as constraints are respected

Use case: project planning, build pipelines, course prerequisites, workflows.

---

## 9) Trees (special kind of graph)

A **tree** is a special graph structure (as introduced here):

- connected hierarchy
- no cycles/back edges in the parent-child direction

Example: family tree structure.

---

## 10) Key takeaways

- Model connection problems with graphs.
- Use BFS for shortest path in unweighted graphs.
- BFS works level by level using a queue (FIFO).
- Always track visited nodes.
- Directed and undirected graphs model different relationship types.
- Topological sort is useful when order depends on prerequisites.
- BFS is one of the most practical algorithms in real systems.

---
