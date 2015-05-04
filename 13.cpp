/*
 * =====================================================================================
 *
 *       Filename:  13.cpp
 *
 *    Description:  获取有环单链表环的起点
 *
 *        Version:  1.0
 *        Created:  2015年05月04日 20时26分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node, *PNode;

PNode createList(int a[], int n, int k)
{
    PNode head, p, loopStart;
    for (int i = 0; i < n; ++i)
    {
        PNode newNode = new Node;
        newNode->data = a[i];
        newNode->next = NULL;
        if (i == 0)
        {
            head = p = newNode;
            if (i == k)
                loopStart = p;
        }
        else
        {
            p->next = newNode;
            p = newNode;
            if (i == k)
                loopStart = p;
        }
    }

    p->next = loopStart;

    return head;
}

void print(PNode head, int n)
{
    int i = 0;
    while (i++ < n)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

/*
 * 首先利用快慢指针找到相遇点。然后相遇点和头指针同时开始走，再次相遇的就是换的起点
 */
PNode getLoopStart(PNode head)
{
    PNode slow, fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }

    if (!fast || !fast->next)
        return NULL;

    //如果是循环链表的情况
    if (fast->next == head)
        return head;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

//利用哈希
PNode getLoopStart1(PNode head)
{
    unordered_map<PNode, bool> hash;
    PNode p = head;
    while(p)
    {
        if (hash.count(p) == 0)
        {
            hash.insert(make_pair(p, true));
            p = p->next;
        }
        else
            return p;
    }

    return NULL;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 4; 

    PNode head = createList(a,10,k);
    cout << getLoopStart(head)->data << endl;
    cout << getLoopStart1(head)->data << endl;
    return 0;
}
