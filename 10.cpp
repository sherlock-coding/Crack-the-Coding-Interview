/*
 * =====================================================================================
 *
 *       Filename:  10.cpp
 *
 *    Description:  获取单链表倒数第n个数
 *
 *        Version:  1.0
 *        Created:  2015年04月22日 19时24分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
    int data;
    struct Node * next;
} Node, *PNode;

PNode init(int a[], int n)
{
    PNode head, p;
    for (int i = 0; i < n; ++i)
    {
        PNode nd = new Node;
        nd->data = a[i];
        if (!i)
            head = p = nd;
        p->next = nd;
        p = nd;
    }

    return head;
}

void print(PNode head)
{
    PNode p = head;
    while (p)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

// 使用栈
int findNthToLast(PNode p, int n)
{
    stack<int> s;
    while (p)
    {
        s.push(p->data);
        p = p->next;
    }

    int i = n;
    while (i > 1)
    {
        s.pop();
        --i;
    }

    return s.top();
}

//递归
int begin = 0;
int ndata = 0;
void findNthToLast1(PNode p, int n)
{
    if (p)
    {
        findNthToLast1(p->next, n);
        ++begin;
        if (begin == n)
            ndata = p->data;
    }
    else
        return;
}

//维护两个相距n的指针
int findNthToLast2(PNode head, int n)
{
    PNode p = head;
    // 获取与p相距n的指针
    PNode q = head;
    for (int i = 0; i < n; ++i)
    {
        q = q->next;
    }
    while(q)
    {
        p = p -> next;
        q = q -> next;
    }

    return p->data;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    PNode head = init(a, 10);
    cout << findNthToLast(head,10) << endl;
    findNthToLast1(head,10); 
    cout << ndata << endl;
    cout << findNthToLast2(head, 10) << endl;
    return 0;
}
