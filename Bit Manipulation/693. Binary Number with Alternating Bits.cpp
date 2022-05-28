// 693. Binary Number with Alternating Bits
/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
 

Constraints:

1 <= n <= 231 - 1
*/

// CPP Solution

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> num(n);
        int i = 31;
        while(i >= 0 and num[i] == 0) i--;
        for(int j = i; j > 0; j--) {
            if(num[j]^num[j-1] == 0) return false;
        }
        
        return true;
    }
};

// Pyhton Solution
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n = bin(n).replace("0b", "")
        n = str(n)
        for i in range(len(n)-1):
            if(n[i] == n[i+1]):return False
        return True