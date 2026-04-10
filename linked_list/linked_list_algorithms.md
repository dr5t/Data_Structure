# Linked List Algorithms (Step-by-Step)

## 1. Insertion Algorithms
### At the Beginning (Head)
1. **Create** a new node.
2. **Assign** the input data to the new node.
3. **Point** new node's `next` to the current `head`.
4. **Update** the `head` pointer to point to the new node.

### At the End (Tail)
1. **Create** a new node.
2. If list is empty, make new node the `head`.
3. Otherwise, **Traverse** the list until `temp->next` is `NULL`.
4. **Point** the current last node's `next` to the new node.

---

## 2. Deletion Algorithms
### From the Beginning
1. Check if the list is empty (`head == NULL`).
2. Store the current `head` in a `temp` pointer.
3. **Update** `head` to `head->next`.
4. **Free** the `temp` memory.

### From the End
1. Traverse to the **second-to-last** node (`temp->next->next == NULL`).
2. Store the last node in a `temp2` pointer.
3. **Update** second-to-last node's `next` to `NULL`.
4. **Free** `temp2`.

---

## 3. Merging Two Sorted Lists
1. Compare the data of the first nodes of both lists.
2. The smaller node becomes the starting node of the merged list.
3. Move the pointer of the list from which the element was taken.
4. Repeat until one list is exhausted.
5. Attach the remaining part of the non-empty list to the end.

---

## 4. Removing Nth Node from End (Two-Pointer Logic)
1. Use two pointers: `fast` and `slow`.
2. Move `fast` pointer $N$ steps forward.
3. Move both `fast` and `slow` forward one step at a time until `fast` reaches the end.
4. Now, `slow` is pointing to the node **immediately before** the targeted $N$th node.
5. Skip $N$th node: `slow->next = slow->next->next`.
6. **Free** the memory of the skipped node.
