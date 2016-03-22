#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int* pArr;
    int index;
    int len;
};

struct Stack* new_stack(int len);

int push(struct Stack* s, int item);

int push_0(struct Stack* s, int item);

int pop(struct Stack* s);

int empty(struct Stack* s);

int main()
{
    struct Stack* s = new_stack(2);
    int i;
    for(i = 0; i < 100; ++i)
    {
        push(s, i);
    }
    printf("stack len:%d\n", s->len);

    for(i = 0; i < 100; ++i)
    {
        printf("pop:%d\n", pop(s));
    }
}

struct Stack* new_stack(int len)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->len = len;
    stack->pArr = (int*)malloc(sizeof(int) * len);
    stack->index = -1;

    return stack;
}

int push_0(struct Stack* s, int item)
{
    if(s->index == (s->len - 1))
    {
        int new_len = s->len * 2;
        s->len = new_len;
        int* new_arr = (int*)malloc(sizeof(int) * new_len);
        int i = 0;
        for(;i <= s->index; ++i)
        {
            new_arr[i] = s->pArr[i];
        }
        int* temp_arr = s->pArr;
        s->pArr = new_arr;
        free(temp_arr);
    }
    s->index += 1;
    s->pArr[s->index] = item;

    return 1;
}

int push(struct Stack* s, int item)
{
    if(s->index == (s->len - 1))
    {
        int new_len = s->len * 2;
        s->len = new_len;
        int* new_arr = (int*)realloc(s->pArr, new_len * sizeof(int));
        s->pArr = new_arr;
        /*
        int* new_arr = (int*)malloc(sizeof(int) * new_len);
        int i = 0;
        for(;i <= s->index; ++i)
        {
            new_arr[i] = s->pArr[i];
        }
        int* temp_arr = s->pArr;
        s->pArr = new_arr;
        free(temp_arr);
        */
    }
    s->index += 1;
    s->pArr[s->index] = item;

    return 1;
}

int pop(struct Stack* s)
{
    int ret;
    if(!empty(s))
    {
        ret = s->pArr[s->index];
        s->index -= 1;
    }
    else
    {
        printf("error stack is empty\n");
    }


    return ret;
}

int empty(struct Stack* s)
{
    return s->index < 0;
}
