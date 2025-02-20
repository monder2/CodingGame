


#include <stdio.h>
#include "stdbool.h"

#define QUEUE_SIZE 5

struct Queue ;

typedef bool (*FunctionPointerDeQueue)(Queue oQueue);
typedef bool (*FunctionPointerEnQueue)(Queue oQueue);


static void Swap(int a, int b);
static SwapQueue(Queue oQueue);

bool DeQueue(Queue oQueue);
bool EnQueue(Queue oQueue);

typedef struct Queue
{
    int Queue[QUEUE_SIZE];
    int Head;
    int Tile;
    FunctionPointerDeQueue fpDeQueue;
    FunctionPointerEnQueue fpEnQueue;
}Queue;

static void Swap(int a, int b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

static SwapQueue(Queue oQueue)
{
    for (size_t i = QUEUE_SIZE; i > 0; i--)
    {
        Swap(oQueue.Queue[i],oQueue.Queue[i])
    }
}

bool DeQueue(Queue oQueue)
{
    bool Result = false;


    return Result;
}
bool EnQueue(Queue oQueue)
{
    bool Result = false;


    return Result;
}


void PrintQueue(Queue oQueue);



int main(void)
{

printf("main work\n");

    return 0;
}