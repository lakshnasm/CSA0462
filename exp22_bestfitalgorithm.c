#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

void initializeMemory()
{
    for(int i=0;i<MAX_MEMORY;i++)
        memory[i]=-1;
}

void allocateMemory(int processId,int size)
{
    int start=-1;
    int blockSize=MAX_MEMORY;
    int bestStart=-1;
    int bestSize=MAX_MEMORY;

    for(int i=0;i<MAX_MEMORY;i++)
    {
        if(memory[i]==-1)
        {
            if(blockSize==MAX_MEMORY)
                start=i;

            blockSize++;
        }
        else
        {
            if(blockSize>=size && blockSize<bestSize)
            {
                bestSize=blockSize;
                bestStart=start;
            }
            blockSize=0;
        }
    }

    if(bestSize>=size)
    {
        for(int i=bestStart;i<bestStart+size;i++)
            memory[i]=processId;

        printf("Allocated memory block %d-%d\n",
               bestStart,bestStart+size-1);
    }
}

int main()
{
    initializeMemory();
    return 0;
}
