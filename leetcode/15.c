
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：
输入：nums = []
输出：[]

示例 3：
输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


//比较函数
int compInt(const void *a,const void *b) {
    return *(int *)a - *(int *)b;	//快排构造递增序列
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    //returnSize用来作为二维数组行的下标
	//且必须在函数开头就设置为0
	//否则在输入为空的情况下无法通过
    *returnSize = 0;

    if(numsSize <3)
    {
        return NULL;
    }

    int i=0,left,right;

    //排序函数qsort()
    qsort(nums,numsSize,sizeof(int),compInt);

    int **ans;
    ans = (int **)malloc(sizeof(int)*numsSize*numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int)*numsSize*numsSize);
    //returnColumbSizes 用来记录列数    非常诡异	也非常难理解

    while(nums[i]<=0 && i<numsSize-2)
    {
        left = i+1;
        right = numsSize-1;
        while(left<right)
        {
            if(nums[i]+nums[left]+nums[right] == 0)
            {
                ans[*returnSize] = (int *)malloc(sizeof(int)*3);     //每次找到一组就分配3个空间
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[left];
                ans[*returnSize][2] = nums[right];
                (*returnSize)++;    //*取值运算符与++自增运算符都是二级优先，且结合方向是从右向左
                
                while(nums[left] == nums[++left] && left<right);        //去重
                while(nums[right] == nums[--right] && left<right);     //去重
            }

            else if(nums[i]+nums[left]+nums[right] < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        while(nums[i] == nums[++i] && i<numsSize-2);                //去重
    }
    return ans;
}
