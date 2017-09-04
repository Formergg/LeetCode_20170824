// Link : https://leetcode.com/problems/beautiful-arrangement-ii/description/
// Date : 2017-08-27

/**********************Description**************************
Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.

Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.

Note:
The n and k are in the range 1 <= k < n <= 104.
************************************************************/

/*
	笔记：
	一开始理解错了题意，以为是间隔必须从k开始逐渐递减直至1，一直没AC。
	然后就找到博客http://blog.csdn.net/zjucor/article/details/77688541学习了一下思路，以下代码是根据该思路Coding。
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int start = 1, end = n;
        vector<int> result;
        int i = 0;
        for(; i < k; i++)
        {
            if(0 == i % 2)
            {
                result.push_back(start++);
            }
            else
            {
                result.push_back(end--);
            }
        }

        if(0 == i % 2)
        {
            for(; i < n; i++)
            {
                result.push_back(end--);
            }
        }
        else
        {
            for(; i < n; i++)
            {
                result.push_back(start++);
            }
        }
    
        return result;
    }
};

/*
class Solution {  // Discuss Answer
public:
    vector<int> constructArray(int n, int k) {
        vector<int> mVec;

        // 最大n-1
        for(int i = 1,j = n;i<=j;) {
            if(k>1) {
                mVec.push_back(k--%2?i++:j--);
            }else {
                mVec.push_back(i++);
            }
        }
        return mVec;

    }

};

*/