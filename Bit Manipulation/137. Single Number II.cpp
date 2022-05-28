// 137. Single Number II
/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/
// CPP Solution
class Solution {
public:
    int singleNumber(vector<int>& num) {
        bool flag = false;
        sort(num.begin(),num.end());
        for(int i = 0;i<num.size()-1;i++)
        {
            if(num[i]==num[i+1])
            {
               flag = true;
            }else
            {
                if(!flag)
                {
                    return num[i];
                }else
                    flag = false;
            }
        }
     return num[num.size()-1];
    }
};

// Python Solution
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        for i in nums:
            z = nums.count(i)
            if(z == 1):return i