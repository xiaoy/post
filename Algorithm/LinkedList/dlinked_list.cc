#include <stdlib.h>
#include <stdio.h>

struct DoubleLinkedNode
{
    int item;
    DoubleLinkedNode* prev;
    DoubleLinkedNode* next;
};

DoubleLinkedNode* push_back(DoubleLinkedNode* head, int item);

DoubleLinkedNode* get_node_by_item(DoubleLinkedNode* node, int item);

void update_node(DoubleLinkedNode* cur, int item);

void add_node(DoubleLinkedNode* cur, DoubleLinkedNode* node);

void remove_node(DoubleLinkedNode* head, DoubleLinkedNode* node);

DoubleLinkedNode* reverse(DoubleLinkedNode* head);

DoubleLinkedNode* new_node();

void print_linked_list(DoubleLinkedNode* head);

int main()
{
    int arr[] = {9, 8, 6, 4, 3};
    int i;
    int arr_len = sizeof(arr) / sizeof(int);

    DoubleLinkedNode* head = NULL;

    for(i = 0; i < arr_len; ++i)
    {
        head = push_back(head, arr[i]);
    }

    printf("source node list:\n");
    print_linked_list(head);

    DoubleLinkedNode* find_node = get_node_by_item(head, 4);

    DoubleLinkedNode* node = new_node();
    node->item = 11;

    add_node(find_node, node);

    printf("after add node %d list:\n", 11);
    print_linked_list(head);

    update_node(node, 666);
    printf("after update node %d list:\n", 666);
    print_linked_list(head);

    remove_node(head, node);
    printf("after remove node %d list:\n", 11);
    print_linked_list(head);


    head = reverse(head);
    printf("after reverse\n");
    print_linked_list(head);
}

DoubleLinkedNode* new_node()
{
    return (DoubleLinkedNode*)malloc(sizeof(DoubleLinkedNode));
}

DoubleLinkedNode* push_back(DoubleLinkedNode* head, int item)
{
    DoubleLinkedNode* cur = head;
    if(cur == NULL)
    {
        cur = new_node();
        cur->prev = NULL;
        cur->next = NULL;
        cur->item = item;
        return cur;
    }

    while(cur)
    {
        if(cur->next == NULL)
        {
            cur->next = new_node();
            cur->next->prev = cur;
            cur->next->next = NULL;
            cur->next->item = item;
            break;
        }

        cur = cur->next;
    }

    return head;
}

void add_node(DoubleLinkedNode* cur, DoubleLinkedNode* node)
{
    node->next = cur->next;
    node->prev = cur;
    cur->next = node;
}

void remove_node(DoubleLinkedNode* head, DoubleLinkedNode* node)
{
     while(head)
     {
         if(head == node)
         {
             node->prev->next = node->next;
             node->next->prev = node->prev;
             free(node);
             break;
         }

         head= head->next;
     }
}

DoubleLinkedNode* get_node_by_item(DoubleLinkedNode* node, int item)
{
    while(node)
    {
        if(node->item == item)
        {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

void update_node(DoubleLinkedNode* cur, int item)
{
     cur->item = item;
}

DoubleLinkedNode* reverse(DoubleLinkedNode* head)
{
     DoubleLinkedNode* next = NULL;
     DoubleLinkedNode* cur = head;

     while(cur->next)
     {
         cur->prev = cur->next;
         cur->next = next;

         next = cur;
         cur = cur->prev;
     }
     cur->next = next;

     return cur;
}

void print_linked_list(DoubleLinkedNode* head)
{
    DoubleLinkedNode* cur = head;
    while(cur)
    {
        printf("item:%d\n", cur->item);
        cur = cur->next;
    }
}
