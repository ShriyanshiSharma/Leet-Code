// 28. Find the Index of the First Occurrence in a String

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

// Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.

Solution:

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) 
            return 0;
        vector<int> pi(m);
        pi[0] = 0;
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && needle[j] != needle[i]) {
                j = pi[j - 1];
            }
            if (needle[j] == needle[i]) {
                j++;
            }
            pi[i] = j;
        }
        j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = pi[j - 1];
            }
            if (needle[j] == haystack[i]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};