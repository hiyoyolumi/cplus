编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 

提示：
0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


char * longestCommonPrefix(char ** strs, int strsSize){
	//建立一个每位都是'\0'的字符串，即空串
    char *returnstr = (char *)malloc(sizeof(char)*201);
    memset(returnstr,0,sizeof(char)*201);		//memset()
										/*void *memset(void *str, int c, size_t n) 复制字符 c（一个无符号											字符）到参数 str 所指向的字符串的前 n 个字符。*/	
	//如果传入空字符串，直接返回空串
    if(strsSize == 0)	
    {
        return returnstr;
    }
    char map[123]={0};
    int i=0,j=0,flag=0;

	//遍历字符串们
	//具体思路是纵向对比字符串们相同位置的字符是否相同
	//实现方法是通过map[]数组来记录第一行的第j个字符，然后对比其他字符串
	while(1)
    {
        i = 0;
        if(strs[i][j] == '\0')
        {
            break;
        }
        map[(int)strs[i++][j]] = 1;			//记录第一行第j个字符
        for(;i<strsSize;i++)
        {
            if(map[(int)strs[i][j]] == 0)	//纵向对比其他字符串
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            break;
        }
        returnstr[j] = strs[0][j];
        map[(int)strs[0][j]] = 0;
        j++;
    }
    return returnstr;
}
