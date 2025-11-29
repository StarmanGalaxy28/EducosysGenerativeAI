#include <iostream>
#include <vector>
#include <algorithm>

/*
Detailed Explanation of Binary Search:

Binary Search is an efficient algorithm for finding an item from a sorted list of items.
It works by repeatedly dividing in half the portion of the list that could contain the item,
until you've narrowed down the possible locations to just one.

Key Principles:
1.  **Sorted Array**: Binary search only works on sorted arrays (or lists). If the array is not sorted, you must sort it first.
2.  **Divide and Conquer**: The algorithm follows a divide and conquer strategy. It repeatedly divides the search interval in half.
3.  **Middle Element**: In each step, it compares the target value with the middle element of the array.
    *   If the target matches the middle element, the search is successful.
    *   If the target is less than the middle element, the search continues in the lower half of the array.
    *   If the target is greater than the middle element, the search continues in the upper half of the array.
4.  **Efficiency**: Binary search has a time complexity of O(log n), which makes it significantly faster than linear search (O(n)) for large datasets.

Algorithm Steps:
1.  Initialize two pointers, `left` and `right`, to the beginning and end of the array, respectively.
2.  While `left` is less than or equal to `right`:
    a.  Calculate the middle index: `mid = left + (right - left) / 2`.
    b.  Compare the element at `arr[mid]` with the `target`:
        i.   If `arr[mid] == target`, return `mid` (target found).
        ii.  If `arr[mid] < target`, discard the left half by setting `left = mid + 1`.
        iii. If `arr[mid] > target`, discard the right half by setting `right = mid - 1`.
3.  If the loop finishes and the target is not found, return -1.

Dry Run Example:
Array: arr = {2, 3, 4, 10, 40}
Target: 10

Initial State:
left = 0
right = 4

Iteration 1:
-   left <= right (0 <= 4) is true.
-   mid = 0 + (4 - 0) / 2 = 2
-   arr[mid] = arr[2] = 4
-   target (10) > arr[mid] (4), so discard the left half.
-   left = mid + 1 = 2 + 1 = 3

Current State:
left = 3
right = 4

Iteration 2:
-   left <= right (3 <= 4) is true.
-   mid = 3 + (4 - 3) / 2 = 3 + 1 / 2 = 3 (integer division)
-   arr[mid] = arr[3] = 10
-   target (10) == arr[mid] (10), so target found!
-   Return mid = 3.

Result: Element 10 is found at index 3.

Dry Run Example 2:
Array: arr = {2, 3, 4, 10, 40}
Target: 5

Initial State:
left = 0
right = 4

Iteration 1:
-   left <= right (0 <= 4) is true.
-   mid = 0 + (4 - 0) / 2 = 2
-   arr[mid] = arr[2] = 4
-   target (5) > arr[mid] (4), so discard the left half.
-   left = mid + 1 = 2 + 1 = 3

Current State:
left = 3
right = 4

Iteration 2:
-   left <= right (3 <= 4) is true.
-   mid = 3 + (4 - 3) / 2 = 3
-   arr[mid] = arr[3] = 10
-   target (5) < arr[mid] (10), so discard the right half.
-   right = mid - 1 = 3 - 1 = 2

Current State:
left = 3
right = 2

Iteration 3:
-   left <= right (3 <= 2) is false.
-   The loop terminates.

Result: Target 5 is not found, return -1.
*/

// Function to perform binary search
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // If target was not present in the array
    return -1;
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearch(arr, target);
    if (result != -1) {
        std::cout << "Element is present at index " << result << std::endl;
    } else {
        std::cout << "Element is not present in array" << std::endl;
    }

    target = 5;
    result = binarySearch(arr, target);
    if (result != -1) {
        std::cout << "Element is present at index " << result << std::endl;
    } else {
        std::cout << "Element is not present in array" << std::endl;
    }

    return 0;
}