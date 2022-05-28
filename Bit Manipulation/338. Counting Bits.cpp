// 338. Counting Bits
/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 
Constraints:
0 <= n <= 105
*/
// CPP Solution
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        if(n==0){
            return ans={0};
        }
        if(n==1){
            return ans={0, 1};
        }
        ans={0,1};
        for(int i=2; i<=n; i++){
            int temp=i;
            int count=0;
            while(temp>0){
                if(temp%2==1){
                    count++;
                }
                temp=temp/2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
// Python Solution
class Solution:
    def countBits(self, n: int) -> List[int]:
        s = []
        for i in range(n+1):
            c = 0
            while(i):
                if(i & 1):
                    c += 1
                i = i >> 1
            s.append(c)
        return s
                