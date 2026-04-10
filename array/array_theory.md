# Array Theory & Concepts (Exam Guide)

## 1. Definitions
### What is an Array?
An **Array** is a collection of elements of the same data type stored in contiguous memory locations. It is the simplest data structure where each data element can be randomly accessed by using its index number.

- **Index**: A number used to identify the location of an element in the array (starts from 0 in C).
- **Size**: Total number of elements an array can hold.

### 1D vs 2D Arrays
| Feature | 1D Array | 2D Array |
| :--- | :--- | :--- |
| **Logic** | Elements are stored in a single list (row). | Elements are stored in rows and columns (matrix). |
| **Syntax** | `int arr[5];` | `int matrix[3][3];` |
| **Dimension** | Single subscript `[i]`. | Two subscripts `[i][j]`. |

---

## 2. Memory Representation
Computer memory is linear. To store a 2D array, we must map its 2-dimensional coordinates $(i, j)$ to a 1-dimensional address space.

### Row-Major Order (Used in C)
Elements are stored **row by row**. 
**Formula for Address of $A[i][j]$**:
$$\text{Address} = \text{Base Address} + \text{Width} \times (i \times N + j)$$
*(Where $N$ is the number of columns, and $W$ is the size of one element)*

### Column-Major Order
Elements are stored **column by column**.
**Formula for Address of $A[i][j]$**:
$$\text{Address} = \text{Base Address} + \text{Width} \times (j \times M + i)$$
*(Where $M$ is the number of rows)*

---

## 3. Concept Questions
### Why is an array "Static"?
In C, the size of a standard array must be known at **compile-time**. Once defined, its size cannot be changed during program execution. This is because memory is allocated on the **stack** in a fixed block.

### Overflow & Underflow
- **Overflow**: Occurs when you try to insert an element into an array that is already full.
- **Underflow**: Occurs when you try to delete an element from an empty array.

### Array vs Linked List
| Comparison | Array | Linked List |
| :--- | :--- | :--- |
| **Memory** | Contiguous (sequential). | Non-contiguous (nodes are linked). |
| **Access** | Random access (O(1)). | Sequential access (O(n)). |
| **Insertion** | Slow (requires shifting). | Fast (just change pointers). |
| **Size** | Fixed (static). | Dynamic (grows as needed). |
