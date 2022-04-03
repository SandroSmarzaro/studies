#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[3];

void* facaAlgumaCoisa(void *arg)
{
    unsigned int i;
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        printf("\n Processando Primeira Thread\n");
    }else if(pthread_equal(id,tid[1]))
    {
        printf("\n Processando Segunda Thread\n");
    }else if(pthread_equal(id,tid[2])){
        printf("\n Processando Terceira Thread\n");
    }

    //sleep(2);
    for(i=0;i<(0xFFFFFFFF);i++);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    while(i < 3)
    {
        err = pthread_create(&(tid[i]), NULL, &facaAlgumaCoisa, NULL);
        if (err != 0)
            printf("\nNao eh possivel criar a Thread: [%s]", strerror(err));
        else
            printf("\nThread criada com sucesso!\n");

        i++;
    }

    sleep(5);
    return 0;
}
// Para Compilar #gcc -g -Wall -pthread thread.c -lpthread -o thread
