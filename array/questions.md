# Array Practice Questions in C

This document contains a curated list of array problems, ranging from basic operations to advanced algorithmic challenges, specifically designed for C.

## 1. Foundational Concepts
- **Traversal:** Write a program to print all elements in an array using both index-based and pointer-based traversal.
- **Insertion:** Insert an element at a specific index in an array. Handle the case where the array is full.
- **Deletion:** Delete an element at a specific index and shift the remaining elements.
- **Dynamic Allocation:** Use `malloc` to create an array of size `n` provided by the user, populate it, and then `free` the memory.
- **Pointer Arithmetic:** Given an array `int arr[] = {10, 20, 30}`, use a pointer `*p = arr` to access and print the second element using `*(p + 1)`.

## 2. Searching and Sorting (Basic)
- **Linear Search:** Find the index of a target element in an unsorted array.
- **Binary Search:** Implement binary search on a sorted array (Iterative and Recursive).
- **Find Min/Max:** Find the smallest and largest elements in an array.
- **Second Largest:** Find the second largest element without sorting the array.
- **Bubble Sort:** Implement the Bubble Sort algorithm to sort an array.

## 3. Intermediate Problem Solving
- **Reverse Array:** Reverse the elements of an array in-place.
- **Rotate Array:** Rotate an array to the right by `k` steps.
- **Move Zeros:** Move all `0`s to the end of the array while maintaining the relative order of non-zero elements.
- **Remove Duplicates:** Remove duplicates from a sorted array (return the new length).
- **Intersection of Two Arrays:** Find the common elements between two arrays.
- **Two Sum:** Find if there are two elements in the array that sum up to a specific target.

## 4. 2D Arrays (Matrices)
- **Matrix Addition:** Add two $m \times n$ matrices.
- **Matrix Multiplication:** Implement matrix multiplication for two compatible matrices.
- **Transpose:** Find the transpose of a square matrix.
- **Spiral Traversal:** Print the elements of a 2D matrix in spiral order.
- **Search in 2D:** Search for a target value in a row-wise and column-wise sorted matrix.

## 5. Advanced Challenges
- **Trapping Rain Water:** Given an array of heights, calculate how much water it can trap after raining.

---

## 🌳 BEYOND SYLLABUS (MASTER SET)

### 1. Pattern Mastery (High Efficiency)
- **Two Pointers**: Find if a sorted array has two elements that sum to `target`.
- **Sliding Window**: Find the maximum sum of any contiguous subarray of size `k`.
- **Prefix Sum**: Given `L` and `R`, return the sum of elements from index `L` to `R` in $O(1)$.

### 2. Expert Subarray Problems
- **Kadane's Algorithm ⭐⭐⭐**: Find the maximum sum of a contiguous subarray.
- **Subarray Sum Equals K**: Count total subarrays with sum `k` (using hashing).
- **Minimum Window Substring**: (Advanced) Find the smallest substring containing all characters.

### 3. 2D Matrix Optimization ⭐⭐
- **Rotate Matrix in-place**: Rotate a square matrix 90 degrees clockwise without extra space.
- **Search in 2D**: Search for a target in a row-wise and column-wise sorted matrix.

### 4. Logic & Tricks
- **Single Number**: Find the element that appears once in an array where every other element appears twice (using XOR).
- **Find the Missing Number**: Find the missing number in an array of $1 \dots n$.

---

## 🔥 EXAM ESSENTIALS (HIGH CHANCE)
- **Insert at Position** ⭐
- **Delete from Array**
- **Linear Search**
- **Binary Search** ⭐⭐
- **Largest & Smallest**
- **Reverse an Array** ⭐
- **Second Largest Element**
- **Rotate Array (k steps)**
- **Remove Duplicates**
- **Merge Two Arrays**

## C-Specific Tips
> [!TIP]
> - Always remember that arrays in C do not store their size. Pass the size as a separate parameter to functions.
> - Be careful with buffer overflows; always check index boundaries.
> - When using dynamic memory (`malloc`), always check if the returned pointer is `NULL`.
