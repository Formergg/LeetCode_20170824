// Link : https://leetcode.com/problems/beautiful-arrangement-ii/description/
// Date : 2017-08-28

/**********************Description**************************
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
************************************************************/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int size = nums.size();
        vector<int> count(size, 0);
        
        vector<int> result;
        for(auto num : nums)
        {
            count[num - 1] ++;
        }
        
        for(int i = 0; i < size;i++)
        {
            if(0 == count[i])
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

/*
// Your runtime beats 34.41 % of cpp submissions.
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int size = nums.size();
        bool flag[size + 1]  = {false};
        vector<int> temp;
        for(int i = 0; i < size;i++)
        {
            flag[nums[i]] = true;
        }
        for(int i = 1; i <= size;i++)
        {
            if(!flag[i])
            {
                temp.push_back(i);   
            }
        }
        return temp;
    }
};
*/