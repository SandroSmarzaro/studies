#include <stdio.h>
#include <stdlib.h>

struct listNode {            
    char name[20];
    float weight;
    float height;                
    struct listNode *nextPtr;
}; 

typedef struct listNode ListNode; /* definição de tipo para  struct listNode */
typedef ListNode *ListNodePtr;    /* definição de tipo para  ListNode* */

void insert (ListNodePtr *sPtr, char value);
char delete (ListNodePtr *sPtr, char value);
int isEmpty (ListNodePtr sPtr);
void printList (ListNodePtr currentPtr);
int instructions ();

int main()
{ 
    ListNodePtr startPtr = NULL;
    int choice = 0; /* Escolha do usuário */
    char item = 0;  /* caracter digitado pelo usuário */

    instructions(); /* mostra menu de opções */

    /* se matem no loop até o usuário entrar com a opção 3 */
    while ( choice != 3 ) { 
        switch ( choice ) { 
        case 1:
            printf( "Entre com um Caracter: " );
            scanf( "\n%c", &item );
            insert( &startPtr, item ); /* insere itens na lista */
            printList( startPtr );
            break;
        case 2:
            /* se a lista não estiver vazia */
            if ( !isEmpty( startPtr ) ) { 
                printf( "Entre com caracter a ser deletado: " );
                scanf( "\n%c", &item );
                /* caso encontre o caracter, remove o caracter */
                if ( delete( &startPtr, item ) ) { /* remove caracter */
                    printf( "%c apagado.\n", item );
                    printList( startPtr );
                }
                else {
                    printf( "%c não encontrado.\n\n", item );
                }
            }
            else {
                printf( "Lista Vazia.\n\n" );
            }
            break;
        default:
            printf( "Escolha inválida.\n\n" );
            instructions();
            break;
        }
        printf( "? " );
        scanf( "%d", &choice );
    } // fim do while
    printf( "Fim...\n" );
    return 0; 

}  

/* Insere um valor em ordem na lista */
void insert( ListNodePtr *sPtr, char value )
{ 
    ListNodePtr newPtr = NULL;             /* ponteiro para o novo nó */
    ListNodePtr previousPtr = NULL;        /* ponteiro para o nó anterior na lista */
    ListNodePtr currentPtr = NULL;         /* ponteiro para o nó corrente na lista */
    newPtr = malloc( sizeof( ListNode ) ); /* cria nó na memória */

    if ( newPtr != NULL ) { /* verifica se há espaço */
        newPtr->data = value; /* coloca o valor no nó (B)*/ 
        newPtr->nextPtr = NULL; /* não liga o nó a outro nó */
        previousPtr = NULL;
        currentPtr = *sPtr;

        /* loop para encontrar o local na lista */
        while ( currentPtr != NULL && value > currentPtr->data ) { 
            previousPtr = currentPtr;          /* Caminha para  ...   */
            currentPtr = currentPtr->nextPtr;  /* ... Próximo nó */
        }

        /* insere um novo nó no início da lista */
        if ( previousPtr == NULL ) { 
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } /* end if */
        else { /* insere um novo nó entre previousPtr e currentPtr */
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf( "%c not inserted. No memory available.\n", value );
    }
} /* fim da função insert */

/* Apaga um elemento da lista */
char delete( ListNodePtr *sPtr, char value ){ 
    ListNodePtr previousPtr = NULL; /* aponta para o nó anterior na lista */
    ListNodePtr currentPtr = NULL;  /* aponta para o nó corrente na lista */
    ListNodePtr tempPtr = NULL;     /* ponteiro temporário para um nó */
    /* Apaga o primeiro nó*/
    if ( value == ( *sPtr )->data ) { 
        tempPtr = *sPtr; /* segura a posição enquanto um nó é removido */
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* libera o espaço alocado para o nó */
        return value;
    }
    else { 
        previousPtr = *sPtr;
        currentPtr = ( *sPtr )->nextPtr;
        /* loop para encontrar posição corrente */
        while ( currentPtr != NULL && currentPtr->data != value ) { 
            previousPtr = currentPtr;         /* Caminha para ...   */
            currentPtr = currentPtr->nextPtr; /* ... Próximo nó */  
        }
        /* apaga o nó na posição currentPtr */
        if ( currentPtr != NULL ) { 
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free( tempPtr );
            return value;
        }
    } /* fim do else */
    return '\0';
} /* fim da função delete */

/* Retorna 1 (verdadeiro) se alista estiver vazia, 0 caso contrário */
int isEmpty( ListNodePtr sPtr )
{ 
    return sPtr == NULL;
}
/* Imprime a lista */
void printList( ListNodePtr currentPtr ){
    if ( currentPtr == NULL ) {  //  verifica se a lista está vazia
        printf( "List is empty.\n\n" );
    }
    else { 
        printf( "The list is:\n" );
        /* enquanto não for fim da lista */
        while ( currentPtr != NULL ) { 
            printf( "%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;   
        }
        printf( "NULL\n\n" );
    }
}

int instructions () {
    int option;

    puts ("CHOOSE AN OPTION");
    puts ("1 - Insert Person");
    puts ("2 - Show Table");
    puts ("3 - Exit");
    printf("\nOPTION: ");
    scanf ("%d", &option);

    return option;
}