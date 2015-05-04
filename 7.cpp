/*
 * =====================================================================================
 *
 *       Filename:  7.cpp
 *
 *    Description:  矩阵处理
 *
 *        Version:  1.0
 *        Created:  2015年04月04日 17时47分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
//遍历一次矩阵，当遇到元素等于0时，记录下这个元素对应的行和列。 可以开一个行数组row和列数组col，当元素a[i][j]等于0时， 就把row[i]和col[j]置为true。第二次遍历矩阵时，当某个元素对应的行row[i] 或列col[j]被设置为true，说明该元素在需要被置0的行或列上，因此将它置0

#include <iostream>
using namespace std;

const int m = 4;
const int n = 3;
int a[4][3] = {{0,1,2,},{4,5,6,},{8,9,10},{11,12,0}};
int row[m] = {0};
int col[n] = {0};

void print()
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << a[i][j]<<" ";
        cout << endl;
    }
}

void zero()
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j]==0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (row[i] || col[j])
            {
                a[i][j] = 0;
            }
        }
    }
}

int main()
{
    print();
    zero();
    print();

    return 0;
}

