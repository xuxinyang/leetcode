/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.00%)
 * Likes:    526
 * Dislikes: 0
 * Total Accepted:    189.6K
 * Total Submissions: 420.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *value = (int*) malloc (sizeof(int) * digitsSize);
    int temp = digits[digitsSize-1];
    if (temp < 9)
    {
        temp ++;
        digits[digitsSize-1] = temp;
        value = digits;
        return value;
    }
    else
    {
        if (/* condition */)
        {
            /* code */
        }
        
    }
    
}
// @lc code=end

