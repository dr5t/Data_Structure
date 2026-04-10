#include <stdio.h>

/**
 * PROBLEM: TRAPPING RAIN WATER
 * ---------------------------
 * Logic: 
 * 1. Use two pointers, `left` and `right`.
 * 2. Maintain two variables, `leftMax` and `rightMax`.
 * 3. If `height[left] <= height[right]`:
 *    - If `height[left] >= leftMax`, update `leftMax`.
 *    - Else, add `leftMax - height[left]` to `totalWater`.
 *    - Move `left++`.
 * 4. Else:
 *    - If `height[right] >= rightMax`, update `rightMax`.
 *    - Else, add `rightMax - height[right]` to `totalWater`.
 *    - Move `right--`.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

int trap(int height[], int n) {
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                totalWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                totalWater += rightMax - height[right];
            }
            right--;
        }
    }

    return totalWater;
}

int main() {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);

    printf("Heights: ");
    for (int i = 0; i < n; i++) printf("%d ", height[i]);

    int result = trap(height, n);
    printf("\nTotal Water Trapped: %d units\n", result);

    return 0;
}
