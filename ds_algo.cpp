#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        } else { // If target is smaller, ignore right half
            right = mid - 1;
        }
    }
    
    // Target was not found
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    
    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in array" << endl;
    }
    return 0;
}