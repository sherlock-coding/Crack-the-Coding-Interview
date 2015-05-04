/*
 * =====================================================================================
 *
 *       Filename:  3.cpp
 *
 *    Description:  C风格字符串翻转
 *
 *        Version:  1.0
 *        Created:  2015年03月27日 14时56分03秒
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

int reverse(char *str)
{
    if (str == nullptr) {
        // error
        return 0;
    }

    int len = strlen(str);
    int begin = 0;
    int end = len - 1;
    while (begin < end) {
        char t = str[begin];
        str[begin++] = str[end];
        str[end--] = t;
    }

    return 1;
}

int main()
{
    char  str[] = "abcd";
    if (reverse(str)) {
        cout << str << endl;
    }

    return 0;
}
