// 371. Sum of Two Integers
/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5

Constraints:
-1000 <= a, b <= 1000
*/
// CPP Solution
class Solution {
public:
    int getSum(int a, int b) {
        int xor1=a^b;
        unsigned  carry=a&b;
        if(carry==0)return xor1;
        else return getSum(xor1, carry<<1);
    }
};

// Python Solution
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        while b:
            carry = (a & b)<<1
            a = (a ^ b) & mask
            b = carry & mask
        return ~(a^mask) if mask//2 < a else a