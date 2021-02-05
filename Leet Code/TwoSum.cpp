// ProblemLink : https://leetcode.com/problems/two-sum/submissions/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);

                }

            }
        }
        return result;
    }
};

// Time Complexity => O(n^2)
// Space Complexity => O(1)

// ----------------------------------------------------------------------

/* Approach 2 Two Pass Hash Table */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;
    
    for (int i = 0;; ++i) {
        auto it = imap.find(target - nums[i]);
        
        if (it != imap.end()) 
            return vector<int> {i, it->second};
            
        imap[nums[i]] = i;
    }
   
    }
        
};



// Time Complexity => O(n)
// Space Complexity => O(n)
