给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//执行用时：4 ms, 在所有 C 提交中击败了98.79%的用户
//内存消耗：5.7 MB, 在所有 C 提交中击败了60.11%的用户
//这道题目的思路是排序+双指针，解题思想与15_三数之和相似
//用这种思路顺下来的话时间复杂度为o(n^3)，很容易超出时间限制
//所以需要对这种做法进行优化
//
//具体的优化措施：
//	加入一个条件判断语句if(sum > target) && if(sum < target)
//	当sum>target时，(因为已知数组是升序的，因此如果想要三数之和与target更接近的话，就只需要right--来使得su//  m减小)
//	sum<target同理

int compInt(const void *a,const void *b) {
    return *(int *)a - *(int *)b;	//快排构造递增序列
}

int numdistance(int num, int target)
{
    if(num > target)
    {
        return (num-target);
    }
    else
    {
        return (target-num);
    }
}


int threeSumClosest(int* nums, int numsSize, int target){
    //排序函数qsort()
    qsort(nums,numsSize,sizeof(int),compInt);

    int i=0, left=i+1, right=numsSize-1;

    //smallnum是三数之和与target的差值的最小值
    //returnnum是要返回的数
	//sum用来记录三数之和
    //给定smallnum的初始值
    int returnnum = nums[i]+nums[left]+nums[right];
    int sum = nums[i]+nums[left]+nums[right];
    int smallnum = numdistance(sum, target);

    while(i<numsSize-2)
    {
        left = i+1;
        right = numsSize-1;
 
        while(left<right)
        {
            sum = nums[i]+nums[left]+nums[right];
            if(sum == target)
            {
                return sum;
            }

            if(numdistance(sum, target) < smallnum)
            {
                smallnum = numdistance(sum, target);
                returnnum = sum;
                if(sum > target)
                {
                    right--;
                    continue;
                }
                else
                {
                    left++;
                    continue;
                }
            }
            else
            {
                if(sum > target)
                {
                    right--;
                    continue;
                }
                else
                {
                    left++;
                    continue;
                }
            }
            
        }
        i++;
    }

    return returnnum;
}
