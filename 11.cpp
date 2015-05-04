/*
 * =====================================================================================
 *
 *       Filename:  11.cpp
 *
 *    Description:  从链表中删除制定结点
 *
 *        Version:  1.0
 *        Created:  2015年04月23日 20时18分27秒
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

typedef struct Node
{
    int data;
    struct Node * next;
}Node, *PNode;

PNode init(int a[], int n)
{
    PNode head, p;
    for (int i = 0; i < n; ++i)
    {
        PNode nn = new Node;
        nn -> data = a[i];
        if (i == 0)
        {
            head = p = nn;
            continue;
        }

        p->next = nn;
        p = nn;
    }

    return head;
}

void print(PNode head)
{
    PNode p = head;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

//不处理c为尾结点的情况
bool remove(PNode c)
{
    if (!c || c->next ==NULL )
        return false;

    PNode p = c->next;
    c->data = p->data;
    c->next = p->next;
    delete p;
    return true;
}



int main()
{

    int a[] = {1,2,3,4,5,6,7,8,9};
    PNode head = init(a,9);
    if (remove(head->next->next))
    {
        print(head);
    }

    return 0;
}
