# Hashing Practice Questions (5-Level Roadmap)

## 🔰 LEVEL 1: BASICS (Foundation)

- **Hash Functions:** Discuss and implement basic hash functions like Modulo (`key % size`) and Mid-square.
- **Node Implementation:** Define a structure for Chaining (Hash Table with Linked List).
- **Direct Address Table:** Explain the difference between hashing and standard indexing.

## ⚙️ LEVEL 2: OPEN ADDRESSING (Collision Resolution)

- **Linear Probing ⭐⭐⭐:** Implement a hash table where collisions are handled by searching for the next available slot.
- **Quadratic Probing ⭐:** Handle collisions using $i^2$ increments to avoid primary clustering.
- **Double Hashing:** Use a second hash function to find the next skip interval.

## 🧠 LEVEL 3: CLOSED ADDRESSING (Chaining)

- **Separate Chaining ⭐⭐⭐:** Handle collisions by creating a linked list at each index.
- **Search Complexity:** Discuss why the worst-case for chaining is $O(n)$ while average is $O(1)$.

## 🚀 LEVEL 4: INTERMEDIATE (Management)

- **Load Factor:** Calculate the ratio of filled slots to total size.
- **Rehashing ⭐⭐:** Implement logic to double the table size and re-map all keys when the load factor exceeds a threshold (e.g., 0.7).

## 🔥 LEVEL 5: HARD / APPLICATIONS

- **Find Duplicates:** Use a hash table to find duplicates in an array in $O(n)$ time.
- **Subset Check:** Check if array $A$ is a subset of array $B$ using hashing.
- **Check for Disjoint:** Check if two sets have any common elements.

## 🎯 HASHING "DO OR DIE" MASTER SET

1. **Hash Table with Linear Probing** ⭐⭐⭐
2. **Concept of Chaining (Linked List)** ⭐⭐
3. **Collision Resolution Theory** (Probing vs Chaining) ⭐⭐⭐
4. **Load Factor & Rehashing** ⭐
