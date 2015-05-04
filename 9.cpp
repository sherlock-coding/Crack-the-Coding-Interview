/*
 * =====================================================================================
 *
 *       Filename:  9.cpp
 *
 *    Description:  链表去重
 *
 *        Version:  1.0
 *        Created:  2015年04月21日 21时42分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


//如果可以使用额外的存储，可以使用哈希
//如果不允许使用额外空间，使用两个指针，删除与前一指针相同的元素

#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct Node{
    int data;
    Node * next;
} Node, *PNode;

void removeDuplicate(PNode head)
{
    if (head == NULL)
        return;
    unordered_map<int, int> tmp;
    PNode p = head->next;
    PNode q =  head;
    tmp.insert(make_pair(head->data,1));
    while (p != NULL)
    {
        if (tmp.count(p->data) == 0)
            tmp.insert(make_pair(p->data,1));
        else
        {
            q->next = p->next;
            delete p;
            p = q->next;
            continue;
        }
        q = p;
        p = p->next;
    }
}

void removeDuplicate2(PNode head)
{
    if (head == NULL)
        return;
    PNode p= head;
    PNode prev;
    PNode q;
    while(p!=NULL)
    {
        prev = p;
        q = p->next;
        while(q!=NULL)
        {
            if (p->data == q->data )
            {
                prev->next = q->next;
                delete q;
                q =prev->next;
                continue;
            }
            else
            {
                prev = q;
                q = q->next;
            }
        }

        p = p->next;
    }
}

PNode init(int a[], int n)
{
    PNode head,p;
    for (int i= 0 ; i < n; ++i)
    {
        PNode nd = new Node();
        nd->data = a[i];
        if (i == 0)
        {
            head = p = nd;
        }
        p->next = nd;
        p = nd;
        
    }

    return head;
}

void print(PNode head)
{
    PNode p = head;
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int n = 10;
    int a[] = {3, 2, 1, 3, 5, 6, 2, 6, 3, 1};

    PNode head = init(a,10);
    print(head);
   // removeDuplicate(head);
    removeDuplicate2(head);
    print(head);

    return 0;
}
