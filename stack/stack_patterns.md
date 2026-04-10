# Stack Algorithm Patterns (The "Efficiency" Guide)

Stacks are more than just `push` and `pop`. They are the secret to turning $O(n^2)$ problems into $O(n)$.

---

## 1. Monotonic Stack (The "Right/Left Greater" Strategy)
**Logic**: Maintain a stack where elements are either strictly increasing or strictly decreasing.
**Efficiency**: Every element is pushed/popped at most once, leading to $O(n)$ complexity.

### C Template (Next Greater Element)
```c
// Array: [4, 5, 2, 10]
// Stack stores elements that haven't found their "Greater" yet.
for (int i = 0; i < n; i++) {
    while (!isEmpty(s) && stackTop(s) < arr[i]) {
        int val = pop(s);
        printf("Next greater for %d is %d\n", val, arr[i]);
    }
    push(s, arr[i]);
}
```

---

## 2. Min-Stack (The "Two-Stack" Strategy)
**Logic**: How to get the minimum of a stack in $O(1)$? Maintain an auxiliary stack.

### C Template
```c
void push(int x) {
    dataStack[++top] = x;
    if (isEmpty(minStack) || x <= minStackTop(minStack)) {
        pushMin(minStack, x);
    }
}

int getMin() {
    return minStackTop(minStack);
}
```

---

## 3. Circular Tour (The "Queue Reset" Strategy)
**Logic**: Finding a starting point in a circular array.

### Concept (Pseudo-code)
```c
int start = 0, balance = 0, total = 0;
for (int i = 0; i < n; i++) {
    int diff = fuel[i] - cost[i];
    total += diff;
    balance += diff;
    if (balance < 0) {
        start = i + 1; // Start over from next station
        balance = 0;
    }
}
return (total >= 0) ? start : -1;
```

---

## 🎯 Pro-Tip: Balanced Parentheses with Multiple Types
Always check if the stack is **empty** before checking `stackTop == matchingPair`. If the stack is empty and you see a closing bracket, it's immediately unbalanced!
