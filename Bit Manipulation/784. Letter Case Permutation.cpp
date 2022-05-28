// 784. Letter Case Permutation
/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]

Constraints:
1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.
*/
// CPP Solution
class Solution {
public:
   vector<string> ans;
    
    void backtrack(int idx, string s){
        
        if(idx==s.size()){
            ans.push_back(s);
            return;
        }
        if(s[idx]>=65 and s[idx]<=90){
            s[idx]= s[idx]+32;
            backtrack(idx+1, s);
            s[idx]= s[idx]-32;
        }
        else if(s[idx]>=97 and s[idx]<=122){
            s[idx]= s[idx]-32;
            backtrack(idx+1, s);
            s[idx]= s[idx]+32;
        }
        //if number
        backtrack(idx+1, s);
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        backtrack(0, s);
        return ans;
    }
};

// Python Solution 

class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        
        def solve(i):
            if i==len(a):
                k=""
                for j in a:
                    k+=j
                b.append(k)
                return
            solve(i+1)
            if a[i] in n:
                return
            if a[i].islower():
                a[i]=a[i].upper()
                solve(i+1)
                return
            a[i]=a[i].lower()
            solve(i+1)
            return
        b=[]
        n={'1','2','3','4','5','6','7','8','9','0'}
        a=list(s)
        solve(0)
        return b