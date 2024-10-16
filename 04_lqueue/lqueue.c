    // SS 2019, KPI FEI TUKE

    #include "lqueue.h"
    #include "err.h"
    #include <stdlib.h>

    struct Node
    {
        PNode	Next;
        TElem	Elem;
    };

    struct LnkQueue
    {
        PNode	Front;
        PNode	Rear;
    };

    int IsEmptyQueue( LQueue Q )
    {
        if(Q == NULL) Error("IsEmptyQueue: incorrect queue!");
        return Q->Front == NULL;
    }

    LQueue CreateQueue( void )
    {
        LQueue Q;
        Q = malloc(sizeof(struct LnkQueue));
        if(Q == NULL)Error("CreateQueue: out of memory!");
        Q->Front = NULL;
        Q->Rear = NULL;
        return Q;
    }

    // Removes a queue
    // Receives a pointer to LQueue, not LQueue itself
    void RemoveQueue( LQueue *PQ )
    {
        if(PQ == NULL) Error("RemoveQueue: incorrect pointer!");
        if(*PQ == NULL) return;
        LQueue Q = *PQ;
        MakeEmptyQueue(Q);
        free(Q);
        *PQ = NULL;
    }

    // Removes elements from a queue
    void MakeEmptyQueue( LQueue Q )
    {
        if(Q == NULL) Error("MakeEmptyQueue: incorrect queue!");
        PNode PFirst;
        while(!IsEmptyQueue(Q)){
            PFirst = Q->Front;
            if(Q->Front == Q->Rear) Q->Rear = NULL;         // the only element in queue
            Q->Front = Q->Front->Next;
            free(PFirst);
        }
    }

    // Inserts element to the end of a list
    void Enqueue( TElem X, LQueue Q )
    {
        PNode PNew;
        if(Q == NULL) {
            Error("Enqueue: incorrect queue!");
            return;
        }
        PNew = malloc(sizeof(struct Node));
        if(PNew == NULL) Error("Enqueue: out of memory!");
        PNew->Elem = X;
        PNew->Next = NULL;
        if(IsEmptyQueue(Q)) Q->Front = PNew;
        else Q->Rear->Next = PNew;
        Q->Rear = PNew;
    }

    void PrintQueue( LQueue Q )
    {
        if(Q == NULL) {
            Error("PrintQueue: incorrect queue!");
            return;
        }
        if(IsEmptyQueue(Q)) printf("Empty queue");
        else{
            PNode PTmp = Q->Front;
            while(PTmp != NULL){
                printf("%d ", PTmp->Elem);
                PTmp = PTmp->Next;
            }
        }
    }

    TElem Front(LQueue Q) {
        if (Q == NULL || IsEmptyQueue(Q)) {
            Error("Front: Queue is empty or incorrect!");
            return -1;
        }
        return Q->Front->Elem;
    }

    void Dequeue(LQueue Q) {
        if (Q == NULL || IsEmptyQueue(Q)) {
            Error("Dequeue: Queue is empty or incorrect!");
            return;
        }
        PNode temp = Q->Front;
        Q->Front = Q->Front->Next;
        if (Q->Front == NULL) {
            Q->Rear = NULL;
        }
        free(temp);
    }

    TElem FrontAndDequeue(LQueue Q) {
        if (Q == NULL || IsEmptyQueue(Q)) {
            Error("FrontAndDequeue: Queue is NULL or empty!");
            return -1;
        }
        TElem frontElem = Front(Q);
        Dequeue(Q);
        return frontElem;
    }