#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int* pArr;
    int index;
    int len;
};

struct Queue* new_queue(int len);

int enqueue(struct Queue* q, int item);

int dequeue(struct Queue* q);

int peek(struct Queue* q);

int isempty(struct Queue* q);

int main()
{
    struct Queue* q = new_queue(2);
    int i;
    for(i = 0; i < 5; ++i)
    {
        enqueue(q, i);
    }

    for(i = 0; i < 3; ++i)
    {
        printf("dequeue:%d\n", dequeue(q));
    }

    for(i = 7; i < 14; ++i)
    {
        enqueue(q, i);
    }

    printf("other dequeue:\n");
    for(i = 0; i < 7; ++i)
    {
        printf("dequeue:%d\n", dequeue(q));
    }

    printf("peek:%d\n", peek(q));

}

struct Queue* new_queue(int len)
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->len = len;
    q->index = -1;
    q->pArr = (int*)malloc(sizeof(int) * len);
    return q;
}

int enqueue(struct Queue* q, int item)
{
    if(q->index == (q->len - 1))
    {
        int len = q->len * 2;
        int* new_arr = (int*)realloc(q->pArr, sizeof(int) * len);
        q->pArr = new_arr;
    }
    q->index += 1;
    q->pArr[q->index] = item;
    return 1;
}

int dequeue(struct Queue* q)
{
    int item;
    if(q->index >= 0)
    {
        item = q->pArr[0];
        int i;
        for(i = 1; i <= q->index; ++i)
        {
            q->pArr[i - 1] = q->pArr[i];
        }
        q->index -= 1;
    }

    return item;
}

int peek(struct Queue* q)
{
    int item;
    if(q->index >= 0)
    {
        item = q->pArr[0];
    }

    return item;
}

int isempty(struct Queue* q)
{
    return q->index == -1;
}
