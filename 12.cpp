/*
 * =====================================================================================
 *
 *       Filename:  12.cpp
 *
 *    Description:  链表相加
 *
 *        Version:  1.0
 *        Created:  2015年05月02日 20时15分35秒
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

typedef struct Node {
    int data;
    Node *next;
}Node, *PNode;

PNode createList(int a[], int n)
{
    PNode head, p;
    for (int i= 0 ; i < n; ++i)
    {
        PNode newNode = new Node;
        newNode->data = a[i];
        newNode->next = NULL;
        if (i == 0)
            head = p = newNode;
        else
        {
            p->next = newNode;
            p = newNode;
        }
    }

    return head;
}

void print(PNode head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

PNode addLink(PNode head1, PNode head2)
{
    if (head1==NULL)
        return head2;
    if (head2==NULL)
        return head1;

    PNode newhead = NULL, p = NULL;
    int c = 0; // 进位
    int sum = 0;

    while (head1!=NULL && head2!=NULL)
    {
        PNode tmp = new Node;
        sum = head1->data + head2->data + c;
        tmp->data = sum % 10;
        tmp->next = NULL;
        c = sum / 10;
        if (!p)
            newhead = p = tmp;
        else
        {
            p->next = tmp;
            p = tmp;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1!= NULL)
    {
        PNode tmp = new Node;
        sum = head1->data + c;
        tmp->data = sum % 10;
        c = sum / 10;
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        PNode tmp = new Node;
        sum = head2->data + c;
        tmp->data = sum % 10;
        c = sum / 10;
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;
        head2 = head2->next;
    }

    if (c)
    {
        PNode tmp = new Node;
        tmp->data = c;
        tmp->next = NULL;
        p->next = tmp;
    }

    return newhead;
}

int main()
{
    int a[] = {1,2,9,3};
    int b[] = {9,9,2};

    PNode head1 = createList(a,4);
    PNode head2 = createList(b,3);

    PNode ret = addLink(head1, head2);

    print(ret);

    return 0;
}
