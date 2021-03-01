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

//中心扩散
//简单的思路就是遍历字符串
//每遍历一个字符就以其为中点向两边扩散
//每一个中点扩散结束之后都要重新计算maxlen的值
//如果大于maxlen则maxlen的值更新
//时间复杂度o(n^2)

//并且中心扩散算法有一个难点在于回文字符串的单双数情况下的处理方法是不一样的
//以下这个算法分别计算单双数的情况，比较巧妙的避开了这一难点

char * longestPalindrome(char * s){
    int slen = strlen(s);
    char *tar = s;
    int left,right,maxlen=0;

    for(int i=0;i<slen;i++)			//奇数长度的回文字符串
    {
        left = i-1;
        right = i+1;
        while(left>=0 && right<slen && s[left] == s[right])
        {
            left--;
            right++;
        }
        left++;		//这里两行代码是为了还原我们预想的情况
        right--;	//因为while循环结束之前，进行了left--和right++的操作
					//使得实际的情况比我们预想的情况又多进行了一次扩大
        if(right-left+1>maxlen)
        {
            maxlen = right-left+1;
            tar = s+left;
        }
    }
    for(int i=0;i<slen;i++)			//偶数长度的回文字符串
    {
        left = i;
        right = i+1;
        while(left>=0 && right<slen && s[left] == s[right])
        {
            left--;
            right++;
        }
        left++;
        right--;
        if(right-left+1 > maxlen)
        {
            maxlen = right-left+1;
            tar = s+left;
        }
    }
    
    tar[maxlen] = '\0';
    return tar;
}
