#ifndef GENERIC_LIST_EG

#define GENERIC_LIST_EG
#include <stdlib.h>
#include <time.h>

typedef struct genericListNode{
    struct genericListNode* prev;
    struct genericListNode* next;
    void *data;
}genericListNode_t;


genericListNode_t * genList_createNode(void * data){
    genericListNode_t * nodeTmp = malloc(sizeof(genericListNode_t));
    nodeTmp->data = data;
    nodeTmp->next = NULL;
    nodeTmp->prev = NULL;
    return nodeTmp;
}
void genList_DestroyNode(genericListNode_t *listNode){
    free(listNode);
}
void genList_AddAfter(genericListNode_t *listEntryPoint, genericListNode_t *listNode){

    if(listEntryPoint->next != NULL){
        listEntryPoint->next->prev = listNode;
    }
    listNode->next = listEntryPoint->next;
    listNode->prev = listEntryPoint;
    listEntryPoint->next = listNode;
}
void genList_AddEnd(genericListNode_t **listHead, genericListNode_t *listNode){
    if(*listHead == NULL){
        *listHead = listNode;
    }else{
        genericListNode_t *entryPoint = *listHead;
        while (entryPoint->next != NULL){
            entryPoint = entryPoint->next;
        }

        entryPoint->next = listNode;
        listNode->prev = *listHead;
    }
}
void genList_AddStart(genericListNode_t **listHead, genericListNode_t *listNode){
    listNode->next = *listHead;
    if(*listHead != NULL){
        (*listHead)->prev = listNode;
    }
    *listHead = listNode;
}
void genList_AddAt(genericListNode_t **listHead, genericListNode_t *listNode,int index){
    if(index == 0 || *listHead == NULL){
        genList_AddStart(listHead,listNode);
    }else{
        genericListNode_t *entryPoint = *listHead;
        while (index > 1 && entryPoint->next != NULL){
            entryPoint = entryPoint->next;
            index--;
        }
        genList_AddAfter(entryPoint,listNode);
        
    }
}

genericListNode_t * genList_getNode(genericListNode_t *listHead, int index){
    while (listHead != NULL && index > 0)
    {
        listHead = listHead->next;
        index--;
    }

    return listHead;
}
int genList_getNodeIndex(genericListNode_t *listHead, genericListNode_t *listResNode){
    if(listHead == NULL){
        return -1;
    }else{
        int pos = 0;
        while (listHead != listResNode && listHead->next != NULL)
        {
            listHead = listHead->next;
            pos++;
        }

        return listHead == listResNode ? pos : -1;
    }
}
genericListNode_t * genList_getLastNode(genericListNode_t *listHead){
    if(listHead == NULL){
        return NULL;
    }else{
        while (listHead->next != NULL)
        {
            listHead = listHead->next;
        }
        return listHead;
        
    }
}

int genList_contains(genericListNode_t *listHead, genericListNode_t *listResNode){
    return genList_getNodeIndex(listHead, listResNode) != -1;
    
}

void genList_removeNode(genericListNode_t **listHead, genericListNode_t *listResNode){
    if(listResNode != NULL){
        if(*listHead != NULL){
            if(*listHead == listResNode){
                *listHead = (*listHead)->next;
                if(*listHead != NULL){
                    (*listHead)->prev = NULL;
                }
            }else{
                if(listResNode->next != NULL){
                    listResNode->next->prev = listResNode->prev;
                }
                if(listResNode->prev != NULL){
                    listResNode->prev->next = listResNode->next;
                }
                
            }
        }

        listResNode->prev = NULL;
        listResNode->next = NULL;
    }
}
genericListNode_t * genList_removeNodeAt(genericListNode_t **listHead, int index){

    genericListNode_t *nodeTmp = genList_getNode(*listHead, index);
    if(nodeTmp != NULL){
        genList_removeNode(listHead, nodeTmp);
    }
    return nodeTmp;
}
void genList_DestroyAll(genericListNode_t **listHead){
    while(*listHead != NULL){
        //free(genList_removeNodeAt(listHead,0));
        genList_DestroyNode(genList_removeNodeAt(listHead,0));

    }

}

int genList_getLength(genericListNode_t *listHead){
    int length = 0;
    while (listHead != NULL)
    {
        listHead = listHead->next;
        length++;
    }
    return length;
    

}

void genList_shouffle(genericListNode_t **listHeadPrt){
    int length = genList_getLength(*listHeadPrt);
    if(length > 0){
        int rand = 0;
        genericListNode_t * newHead = NULL;

        while (length > 0){
            length--;
            rand = 2*rand+time(NULL);
            rand = rand >= 0 ? rand : -rand;
            genList_AddStart(&newHead, genList_removeNodeAt(listHeadPrt,length == 0 ? 0 :rand%length));
        }
        *listHeadPrt = newHead;
    }
}

typedef void (*ActionFunction)(void *);
void genList_Iterate(genericListNode_t *listHead, ActionFunction func){
    while (listHead != NULL)
    {
        func(listHead->data);
        listHead = listHead->next;
    }
    
}

//int genList_sort(genericListNode_t **listHead, int orderFunc(genericListNode_t *listNodeA, genericListNode_t *listNodeB)){}

//int genList_sorted_add(genericListNode_t **listHead,genericListNode_t *listNode, int orderFunc(genericListNode_t *listNodeA, genericListNode_t *listNodeB)){}



#endif





