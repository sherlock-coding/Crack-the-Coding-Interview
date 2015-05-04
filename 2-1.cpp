/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  bitmap海量数据的快速查找和去重
 *
 *        Version:  1.0
 *        Created:  2015年03月25日 18时39分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sherlock-coding 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

/*
 * 对于40亿个整数，如果直接用int数组来表示的大约要用40*10^8*4B=16GB,超出了内存要求，这里
 *
 * 我们可以用bitmap来解决，bitmap基本思想是一位表示一个整数
 */

const int N = 100; // 总的数据量
int bucket[1+N/32];

// 对输入的数在数组中进行标注
void setVal(int val)
{
    bucket[val/32] |= (1<<(val%32));
}

// 检测整数是否存在
bool testVal(int val)
{
    return bucket[val/32] &(1<<(val%32));
}

int main()
{
    int a[] = {1, 4, 3 ,8, 9};

    for(int i=0; i<5; ++i)
    {
        setVal(a[i]);
    }

    std::cout << testVal(5) << std::endl;

    return 0;
}

