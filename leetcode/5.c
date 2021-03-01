给你一个字符串 s，找到 s 中最长的回文子串。


示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：
输入：s = "cbbd"
输出："bb"

示例 3：
输入：s = "a"
输出："a"

示例 4：
输入：s = "ac"
输出："a"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//这道题一眼看过去没有一点思路
//以下是暴力解法

char * longestPalindrome(char * s){
    char *s1,*s2;
    int slen = strlen(s);
    int length = 1;			//记录回文串的长度
    char *tar = s;			//记录回文串的首字符的地址

	//这里暴力解题的思路是通过两个指针s1和s2，找到每一个s1和s2都相等的字符串
	//双重遍历字符串
    for(int i=0;i<slen;i++)
    {
        for(int j=i+length;j<slen;j++)
        {
            s1 = s+i;		//不断扩大s1s2的区间
            s2 = s+j;
            while(s1<s2)	//这里是单纯的比大小
            {
                if(*(s1)!=*(s2))	//如果有s1!=s2的情况就直接break
                {
                    break;
                }
                s1++;				//如果s1s2满足相等的条件的话
                s2--;				//缩小间距，继续判断
            }
            if(s1>=s2)				//当s1>=s2时，证明区间[i,j]内是回文字符串
            {
                tar = s+i;			//把回文字符串的首字符地址赋给tar
                length = j-i+1;		//重新计算回文字符串的长度
            }
        }
    }
    tar[length] = '\0';
    return tar;
}
