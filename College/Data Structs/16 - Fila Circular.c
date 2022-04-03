#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct strcutQueue
{
    int first;
    int last;
    int data[MAX];
} typeQueue;


void creatQueue (typeQueue *queue);
int fullQueue (typeQueue *queue);
int emptyQueue (typeQueue *queue);
void enqueue (typeQueue *queue, int value);
void dequeue (typeQueue *queue);
void printQueue(typeQueue *queue);
void initialMenu(int *option);
void inputMenu(int *value);

int main ()
{
    typeQueue *queue = malloc (sizeof (typeQueue));
    int option;
    int value;

    creatQueue(queue);
    do
    {
        initialMenu(&option);
        switch (option)
        {
        case 0:
            break;

        case 1:
            printQueue(queue);
            break;
        
        case 2:
            inputMenu(&value);
            enqueue(queue, value);
            break;
        
        case 3:
            dequeue(queue);
            break;

        default:
            puts("\n\nINVALID OPTION!");  
            break;
        }
    } while (option != 0);

    return 0;
}

void creatQueue (typeQueue *queue)
{
    queue->first = 0;
    queue->last = 0;
}

int fullQueue (typeQueue *queue)
{
    return (queue->last + 1) % MAX == queue->first;
}

int emptyQueue (typeQueue *queue)
{
    return queue->last == queue->first;
}

void enqueue (typeQueue *queue, int value)
{
    if (!fullQueue(queue))
    {
        queue->data[queue->last] =  value;
        queue->last == (MAX - 1) ? queue->last = 0 : queue->last++;
    }
    else 
    {
        printf("\n\nFull queue! Cant not enqueue %d.\n", value);
    }
}

void dequeue (typeQueue *queue)
{

    if (!emptyQueue(queue))
    {
        queue->first == (MAX - 1) ? queue->first = 0 : queue->first++;
    } 
    else
    {
        puts("\n\nEmpty queue! Can not dequeue.");
    }
}

void printQueue (typeQueue *queue)
{
    //int index;
    //int size;

    puts("\n");
    int index = queue->first;
    if(!emptyQueue(queue))
    {
        while(index != queue->last)
        {
            printf("Index [%d] = %d \n", index, queue->data[index]);
            index = (index + 1) % MAX;
        }
    } 
    /*
    if (!emptyQueue(queue))
    {
        puts("\n");
        if (queue->last > queue->first)
        {
            index = queue->first;
            size = queue->last;
            for (; index < size; index++)
            {
                if (index != queue->last) 
                {
                    printf("Index[%d] = %d\n", index, queue->data[index]);
                }
            }
            printf("\nFirst: [%d] Last: [%d]\n", queue->first, queue->last);
        }
        else
        {
            index = 0;
            size = MAX;
            for (; index < size; index++)
            {
                if (index >= queue -> first || index < queue -> last)
                {
                    printf("Index[%d] = %d\n", index, queue -> data[index]);
                }
            }
            printf("First: %d Last: %d\n", queue->first, queue->last);
        }
        */
        /*
        for (int index = 0; index < MAX; index++)
        {
            printf("Index[%d] = %d\n", index, queue -> data[index]);
        }
        
    }
    */
    else puts("\n\nEmpty queue! Can not print.\n");
}

void initialMenu(int *option)
{
    puts("\n\nSELECT OPTION");
    puts("\n1 - Print Queue");
    puts("\n2 - Enqueue");
    puts("\n3 - Dequeue");
    puts("\n0 - Exit");
    printf("\nACTION: ");
    scanf("%d", option);
}

void inputMenu(int *value)
{
    printf("\n\nVALUE: ");
    scanf("%d", value);
}