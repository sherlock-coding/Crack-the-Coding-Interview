/*
 * =====================================================================================
 *
 *       Filename:  6.cpp
 *
 *    Description:  矩阵旋转90度
 *
 *        Version:  1.0
 *        Created:  2015年04月03日 20时49分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

const int N = 4;

int a[][4] = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}};


void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void print()
{
    for(int i=0; i < N; ++i)
    {
        for(int j=0; j<N; ++j)
            cout <<a[i][j] << " ";
        cout << endl;
    }
}



//顺时针
//分两步，第一步交换主对角线元素，第二部i和n-1-i列交换
void rotate()
{
    for (int i=0; i< N; ++i)
    {
        for(int j=0; j< i; ++j)
        {
            swap(a[i][j],a[j][i]);
        }
    }
    for (int i=0; i < N/2; ++i)
    {
        for(int j=0; j < N; ++j)
            swap(a[j][i],a[j][N-1-i]);
    }
}
//逆时针
//分两步，第一步交换主对角线元素，第二步i和n-1-i行交换
void rotate1()
{
    for (int i=0; i< N; ++i)
    {
        for(int j=0; j< i; ++j)
        {
            swap(a[i][j],a[j][i]);
        }
    }

    for (int i=0; i < N/2; ++i)
    {
        for(int j=0; j < N; ++j)
            swap(a[i][j],a[N-1-i][j]);
    }
}


int main()
{
    rotate();
    print();

    rotate1();
    print();

    return 0;
}

