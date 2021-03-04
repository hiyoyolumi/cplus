给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//使用栈的思想
//把左半部分的符号放入栈顶
//如果遇到后半部分的符号，且和栈顶的前一个字符不相同
//因为后遇到的左括号要先闭合，所以直接return false

char pairs(char p)
{
    if(p == ')')   return '(';
    else if(p == ']')  return '[';
    else if(p == '}')  return '{';
    else return 0;
}

bool isValid(char * s){
    int top=0;
    int n = strlen(s);
    int arr[n+1];
    char ch;
	
	//如果输入的字符串是奇数
    if(n%2 == 1)		
    {
        return false;
    }

    for(int i=0;i<n;i++)
    {
        ch = pairs(s[i]);
        //如果输入的是后半部分		//且栈为空或者栈顶的前一个元素与ch不相同
        if(ch)						//则直接返回false
        {
            if(top == 0 || arr[top-1]!=ch)
            {
                return false;
            }
            top--;
        }
		//如果输入的是前半部分
        else
        {
            arr[top++] = s[i];	//则栈顶增加元素
        }
    }
    return (top == 0);
}
