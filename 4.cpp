/*
 * =====================================================================================
 *
 *       Filename:  4.cpp
 *
 *    Description:  字符串去重
 *
 *        Version:  1.0
 *        Created:  2015年03月27日 15时23分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>

using namespace std;

void removeDuplicate(char *str)
{
    if (str==nullptr) {
        return;
    }
    int len = strlen(str);
    int index = 0; // 存放过滤后的字符串的索引

    for (int i = 0; i < len; ++i)
    {
        if (str[i] != '\0')
        {
            str[index++] = str[i];
            for (int j = i+1; j < len; ++j)
            {
                if(str[j]!='\0' && str[j]==str[i])
                {
                    str[j] = '\0';
                }
            }
        }
    }

    str[index] = '\0';
}


int main()
{
    char str[] = "13434343435568889hhhhhhhfdcvbb";

    removeDuplicate(str);
    cout << str << endl;

    return 0;
}
