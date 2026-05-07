# Autocomplete Search System using Trie (Design Document)

## Overview
This project implements an advanced Autocomplete Search System using the Trie (Prefix Tree) data structure in C++.  
It efficiently supports prefix-based searching, frequency-based ranking, and dynamic updates.

# Trie Working

A **Trie (Prefix Tree)** is a tree-based data structure used for storing and retrieving strings efficiently, especially when dealing with prefix-based queries.

## Structure of Trie Node
Each node contains:
- `children[26]` → pointers to next characters (a–z)
- `isEnd` → indicates end of a valid word
- `frequency` → stores how many times a word has been inserted or searched

---

## 🔹 How Trie Works

### Step 1: Insertion
Words are inserted character by character.

---

### Step 2: Prefix Search
To search suggestions:
1. Traverse Trie using the given prefix
2. Reach the node corresponding to last prefix character
3. Perform DFS from that node
4. Collect all possible words
5. Sort them by frequency

---

### Step 3: Autocomplete Output
Words with higher frequency appear first in suggestions.

---

# Time Complexity Analysis

## Insert Operation → O(L)
Where:
- `L = length of word`

Each character is processed once while traversing or creating nodes.

## Search Operation → O(L)
- Prefix is traversed character by character
- Independent of number of stored words


## DFS Traversal → O(N)
Where:
- `N = number of nodes in the subtree`

Used to collect all valid words under a prefix.

---

# Why Trie Instead of Arrays?

## Using Arrays / Lists
- Requires scanning all words
- Prefix search is slow → O(N × L)
- Not efficient for large datasets

---

## Advantages of Trie

### 1. Fast Prefix Search
- Search complexity: **O(L)**
- Independent of total number of words

---

### 2. Efficient Autocomplete
- Naturally supports prefix-based suggestions
- Ideal for search engines and keyboards

---

### 3. Memory Optimization
- Common prefixes are shared
Example:
apple
application
Both share: `"appl"`

---

### 4. Better Performance
- Faster than arrays, vectors, and hash-based scanning for prefix queries

---

# Key Features of This System

- ✔ Prefix-based search
- ✔ Frequency-based ranking
- ✔ Dynamic insertion of words
- ✔ File-based dictionary loading
- ✔ Efficient DFS-based suggestion retrieval

---

# Conclusion

The Trie-based Autocomplete System provides:
- High-speed prefix searching
- Optimized memory usage
- Real-time suggestion capability

It is widely used in:
- Search engines (Google-like autocomplete)
- Mobile keyboards
- File explorers
- AI-based suggestion systems

---

#  Author
Aina Fatima  
BS Computer Science Student  
