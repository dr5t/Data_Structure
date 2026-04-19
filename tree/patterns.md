# Tree Algorithm Patterns (The "Cheat Sheet")

Mastering trees is about mastering **Recursion**. Instead of memorizing problems, learn these 3 core patterns.

---

## 1. DFS: Recursive Thinking (Bottom-Up)

**The Core Logic**: "Ask your children for information, process it, and send it to your parent."

### Template (Java-style pseudo code)

```c
int solve(Node* root) {
    if (root == NULL) return 0; // Base Case

    int leftResult = solve(root->left);   // 1. Ask left child
    int rightResult = solve(root->right); // 2. Ask right child

    // 3. Process results and return
    return max(leftResult, rightResult) + 1;
}

```

### Problems to solve with this:

1.  **Height/Max Depth** (as shown above).
2.  **Count Nodes**: `return leftResult + rightResult + 1`.
3.  **Balanced Check**: Return `-1` if unbalanced, else return `height`.
4.  **LCA**: If `root` is one of the nodes, return `root`.

---

## 2. BFS: Level-Order Pattern (Level-wise)

**The Core Logic**: "Examine one layer at a time before moving deeper."

### Template (Using a Queue)

```c
void bfs(Node* root) {
    Queue q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at current level

        for (int i = 0; i < levelSize; i++) {
            Node* current = q.pop();
            // Process node...

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
}

```

### Problems to solve with this:

1.  **Print Levels**: Print each level on a new line.
2.  **Zig-zag**: Use two stacks or reverse the list at each level.
3.  **Right View**: Only print the last node of each level.
4.  **Connect Siblings**: Set `next` pointer of `current` to `q.front()`.

---

## 3. Divide & Conquer (Top-Down)

**The Core Logic**: "Solve the problem for the root, then recursively solve for subtrees."

### Template

```c
bool isSymmetric(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    // Check if current roots are equal AND subtrees are symmetric
    return (root1->data == root2->data) &&
           isSymmetric(root1->left, root2->right) &&
           isSymmetric(root1->right, root2->left);
}

```

### Problems to solve with this:

1.  **Mirror Check**: Is one tree the mirror of another?
2.  **Identical Trees**: Are two trees exactly the same?
3.  **Subtree Check**: Is `treeB` a subtree of `treeA`?

---

## 🎯 Pro-Tip: Single Traversal Thinking

When you find yourself calling a recursive function *inside* another recursive function (like `isBalanced` calling `height`), you are likely at $O(n^2)$.
**To fix it**: Modify the `height` function to return a special value (like `-1`) if it finds an imbalance, instead of just the height. This reduces complexity to $O(n)$.
