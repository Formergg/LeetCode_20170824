// Link : https://leetcode.com/problems/max-consecutive-ones/description/
// Date : 2017-08-25

/**********************Description**************************
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
             The maximum number of consecutive 1s is 3.

Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
************************************************************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tmp = 0;
        int maxCount = 0;
        bool start = false;
        for(vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); it++)
        {
            if(*it)
            {
                tmp ++;
                if(!start)
                {
                    start = true;
                }
            }
            else if(start)
            {
                if(tmp > maxCount)
                {
                    maxCount = tmp;
                }
                start = false;
                tmp = 0;
            }
        }
        if(start)
        {
            if(tmp > maxCount)
            {
                maxCount = tmp;
            }
        }
        return maxCount;
    }
};