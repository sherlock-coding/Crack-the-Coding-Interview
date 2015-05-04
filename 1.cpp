/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  unique string, 假定 ASCII字符
 *
 *        Version:  1.0
 *        Created:  2015年03月24日 19时06分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sherlock-coding 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <string>

bool isUnique(const std::string &str)
{
    if (str.size() == 0) return true;
    if (str.size() > 256) return false; 

    bool hash[256];
    std::fill(hash, hash+256, false);

    for (size_t i = 0; i < str.size(); ++i) {
        int tmp = str[i];
        if (hash[tmp]) return false;
        hash[tmp] = true;
    }

    return true;
}

/*通过位运算来减少空间的使用量.用每一位表征相应位置字符的出现.对于ASCII字符,我们需要256位,即一个长度为8的int 数组a即可(BitMap) */
bool isUnique2(const std::string &str)
{
    if (str.size() == 0) return true;
    if (str.size() > 256) return false;

    int bucket[4] = {0}; // 一个int4个字节，32位，256需要8个int
    
    for (size_t i = 0; i < str.size(); ++i) {
        int tmp = str[i];
        int num = tmp / 32; // 数组下标
        int shift = tmp % 32; // 字节中相应的位

        if (bucket[num] & 1 << shift) return false;
        bucket[num] |= (1 << shift);
    }

    return true;
}

int main()
{
    std::string s = "fasb3d";
    std::cout << isUnique2(s) << std::endl << isUnique(s) << std::endl;
    
}

