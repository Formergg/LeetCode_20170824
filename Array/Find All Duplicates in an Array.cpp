// Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
// Date : 2017-08-25

/**********************Description**************************
Given an array of integers, 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
************************************************************/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int flag[65535] = {0};
        for(vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); it ++)
        {
            flag[*it] ++;
        }
        vector<int> duplicates;
        for(int i =0; i <=nums.size();i++)
        {
            if(2 == flag[i])
            {
                duplicates.push_back(i);
            }
        }
        return duplicates;
    }
};