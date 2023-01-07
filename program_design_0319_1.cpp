#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;
struct listNode
{
    string data;
    listNode *link;
};
void append(listNode **first, string item)
{
    listNode *temp;
    temp = (listNode *)malloc(sizeof(*temp)); // temp = new listNode; 
    temp->link = NULL;
    temp->data = item;
    if (*first)
    { /*first是一個址*/
        //用一個temp2 去找接在誰後面
        listNode *temp2;
        temp2 = *first;
        for (; temp2->link != NULL; temp2 = temp2->link)
            ;
        temp2->link = temp;
    }
    else
    {
        /* first = temp; */ //Is wrong!
        *first = temp;
    }
}

void insert_before(listNode **first, string target, string item)
{
    listNode *temp;
    temp = (listNode *)malloc(sizeof(*temp));
    temp->data = item;
    //case1
    //first -> node1 -> null; 差在第一位
    //差在first的下面 temp->link = first->link; *first = temp;
    //case2
    //first -> node1 -> node2 -> null; 差在第二位
    //
    //first -> node1 -> node2 -> node3 -> null

    if ((*first)->data == target)
    { //若要差在第一個前面
        temp->link = *first;
        *first = temp;
    }
    else
    {
        listNode *temp2;
        temp2 = *first;
        for (; temp2->link->data != target; temp2 = temp2->link) //因為這樣寫就會跳過第一個判斷是否為target所以才把要插在第一位的例外出來
            ;
        temp->link = temp2->link;
        temp2->link = temp;
    }
}
void remove(listNode **first, string target)
{
    // first->node1->node2->node3
    if ((*first)->data == target)
    {
        *first = (*first)->link;
    }
    else
    {
        listNode *temp2;
        temp2 = *first;
        for (; temp2->link->data != target; temp2 = temp2->link) //因為這樣寫就會跳過第一個判斷是否為target所以才把要插在第一位的例外出來
            ;
        temp2->link = temp2->link->link;
    }
}

void print_list(listNode *first)
{
    while (first)
    {
        cout << first->data;
        first = first->link;
        if (first != NULL)
        {
            cout << " ";
        }
    }
    cout << endl;
}

// void printList(listNode *ALL)
// {
//     cout << "Created Linked list is: ";
//     for (; ALL != NULL; ALL = (*ALL).link)
//         cout << " " << (*ALL).data << " ";
//     cout << endl;
// }
int main()
{
    listNode *head;
    head = NULL;
    string input_op;
    while (cin >> input_op)
    {
        if (input_op == "ADD")
        {
            string input_item;
            cin >> input_item;
            append(&head, input_item);
        }
        else if (input_op == "INSERT")
        {
            string input_item;
            cin >> input_item;
            string target;
            cin >> target;
            insert_before(&head, target, input_item);
        }
        else if (input_op == "REMOVE")
        {
            string target;
            cin >> target;
            remove(&head, target);
        }
        else if (input_op == "SHOW")
        {
            print_list(head);
        }
    }

    return 0;
}
