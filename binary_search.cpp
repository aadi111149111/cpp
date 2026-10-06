#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        // Calculate mid this way to avoid overflow
        int mid = (left + right) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // Target was not found
    return -1;
}

int main() {
    // Note: The array MUST be sorted for binary search to work
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int target = 4;
    
    int result = binarySearch(numbers, target);
    
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    
    return 0;
}