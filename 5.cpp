/*
 * =====================================================================================
 *
 *       Filename:  5.cpp
 *
 *    Description:  判断两个字符串是否是变位词
 *
 *        Version:  1.0
 *        Created:  2015年04月02日 21时33分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(const string &left, const string &right)
{
    if (left.size() != right.size())
        return false;

    int count[256] = {0};
    int len = left.size();

    for (int i = 0; i < len; ++i)
    {
        ++count[left[i]];
        --count[right[i]];

    }

    for (int j = 0; j < 256; ++j)
    {
        if (count[j] != 0)
            return false;
    }

    return true;
}

int main()
{
    string a = "abbcd";
    string b = "abcdb";
    string c = "abcdd";

    cout << isAnagram(a,b) << endl;
    cout << isAnagram(a,c) << endl;
    return 0;
}
