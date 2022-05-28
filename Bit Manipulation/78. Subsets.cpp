// 78. Subsets
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

class Solution {
private:
    void solve(vector<int> nums,vector<int> o,int i ,vector<vector<int> >& ans){
        if(i >= nums.size()) {
            ans.push_back(o);
            return ;
        }
        solve(nums,o,i+1,ans);
        
        int  e = nums[i];
        o.push_back(e);
        solve(nums,o,i+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> o ;
        int i = 0 ;
        solve(nums,o,i,ans);
        return ans;
    }
};



// Python Solution

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        L, ans = len(nums), list([[]])
        mask = 2**L - 1
        while mask:
            copy, i, subset = mask, L - 1, list()
            while copy:
                if copy & 1: subset.append(nums[i])
                i, copy = i - 1, copy >> 1
            ans.append(subset)
            mask -= 1
        return ans