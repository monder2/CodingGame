
#include<stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 7
struct Buffer;

typedef bool (*BufferPushFunc)(struct Buffer *oBuffer, int nValue);
typedef bool (*BufferPopFunc)(void);

typedef struct Buffer
{
    unsigned int uBuffer[BUFFER_SIZE];
    int PushIndx;
    int PopIndex;
    BufferPushFunc fpPush;
    BufferPopFunc fpPop;
}Buffer;

bool Push(Buffer *oBuffer, int nValue);
bool Pop(void);
void PrintBuffer(Buffer oBuffer);

Buffer oBuffer =
{
    .uBuffer = {0},
    .PushIndx = 0,
    .PopIndex = 0,
    .fpPush = &Push,
    .fpPop = &Pop,
};

bool Push(Buffer *oBuffer, int nValue)
{
    bool bResult= false;

    oBuffer->uBuffer[oBuffer->PushIndx] = nValue;
    
    if(oBuffer->PushIndx == oBuffer->PopIndex)
    {
        printf("Buffer OverWrite Index %d\n",oBuffer->PopIndex);
        oBuffer->PopIndex++;
        if(oBuffer->PopIndex == BUFFER_SIZE)
        {
            oBuffer->PopIndex = 0;
        }
    }
    else
    {
        printf("Push to Buffer \n");
    }
    oBuffer->PushIndx++;
    if(oBuffer->PushIndx == BUFFER_SIZE)
    {
        oBuffer->PushIndx = 0;
    }
    bResult= true;

    return bResult;
}

bool Pop(void)
{
    bool bResult= false;

    if(oBuffer.PushIndx == oBuffer.PopIndex)
    {
        printf("Can't Pop Buffer is empty\n");
        bResult= true;
    }
    else
    {
        oBuffer.PopIndex++;
        if(oBuffer.PopIndex == BUFFER_SIZE)
        {
            oBuffer.PopIndex = 0;
        }
        bResult= true;
    }
    return bResult;
}

void PrintBuffer(Buffer oBuffer)
{
    // if(oBuffer.PopIndex == oBuffer.PushIndx)
    // {
    //     printf("The buffer is empty.");
    // }
    // else
    // {
        printf("[buffer] = \n");
        // for (size_t i = oBuffer.PopIndex; i < oBuffer.PopIndex; i++)
        for (size_t i = 0; i < BUFFER_SIZE; i++)
        {
            printf(" %X",oBuffer.uBuffer[i]);
        }
        printf("\n");
    // }
}

int main(void)
{
    oBuffer.fpPush(&oBuffer,8);
    oBuffer.fpPush(&oBuffer,9);
    oBuffer.fpPush(&oBuffer,10);
    oBuffer.fpPush(&oBuffer,11);

    PrintBuffer(oBuffer);

    return 0;
}