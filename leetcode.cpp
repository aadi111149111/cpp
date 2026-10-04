#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 1. Change the return type to a vector of vectors
    vector<vector<int>> findAllTwoSums(vector<int>& nums, int target) 
    {
        vector<vector<int>> allPairs; // Container to hold all our winning pairs
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++ )
            {
                if (nums[i] + nums[j] == target)
                {
                    // 2. Add the pair to our list instead of returning immediately
                    allPairs.push_back({i, j}); 
                }
            }
        }
        
        // 3. Return the entire list after checking every combination
        return allPairs;
    }
};

int main()
{
    // Added a '0' at the end so we have two pairs that equal 3: (1+2) and (3+0)
    vector<int> array = {1, 2, 3, 4, 5, 6, 0}; 
    int target = 3;
    Solution sol1;
    
    // Store the returned 2D vector
    vector<vector<int>> results = sol1.findAllTwoSums(array, target);
    
    // 4. Loop through the results to print each pair
    if (!results.empty()) {
        cout << "Found " << results.size() << " pairs:\n";
        for(int i = 0; i < results.size(); i++) {
            cout << "[" << results[i][0] << ", " << results[i][1] << "]\n";
        }
    } else {
        cout << "No matching pairs found.\n";
    }
    
    return 0;
}