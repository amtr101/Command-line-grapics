#include <stdio.h> 
#include <stdlib.h> 
#include "cList.h" 
#include "read.h" 

/***************************************************************
 * Amy Trevaskis: 15129275
 * cList.c 
 * a generic linked list used in Practical 7 and in UCP  Assignment
 * The list uses a ListNode struct and a LinkedList struct 
 * containing the "head" of the list
 * **************************************************************/ 



LinkedList* createList(void) 
{
     LinkedList* theList;  
     theList = (LinkedList*)malloc(sizeof(LinkedList));  
  
     theList->head = NULL; 
    
     return theList; 

} 


/*Removed first node of the list freeing the 
 * node while returning the data*/ 

void* removeFirst(LinkedList* inList)
{
    void* data; 
    ListNode* temp = inList->head; 
    inList->head = inList->head->next; 
  
    data = temp->data; 
    free(temp); 

    return data; 

}

/* inserts items at the "end" of the list so that they 
 * can be accessed in order*/ 

void insertLast(LinkedList* inList, void* inData)
{

    ListNode* newNode = NULL;  
    newNode = (ListNode*)malloc(sizeof(ListNode)); 
    newNode->data = inData; 

    if(inList->head == NULL)
    {
	inList->head = newNode; 
	inList->tail = newNode; 

    }
    else
    {
	 inList->tail->next = newNode; 
         inList->tail = newNode; 	 
    }


}

/*inserts items at the "front" of the list */ 

void insertFirst(LinkedList* inList, void* inData) 
{
    ListNode* newNode = NULL; 
 
    newNode = (ListNode*)malloc(sizeof(ListNode)); 
    newNode->data = inData;  
    
    if(inList->head  == NULL)
    {
     	inList->head = newNode;  
    } 
    else
    {
     	newNode->next = inList->head; 
     	inList->head = newNode; 
    }    

}


/* iterates through list freeing both the Listnode
 * structs and the data inside*/ 


void freeList(LinkedList* inList)
{
    ListNode* node = NULL; 
    ListNode* nextNode = NULL; 

    node = inList->head; 
    
    while(node  != NULL)
    {
	nextNode = node->next; 
	free(node->data); 
	free(node); 
	node = nextNode; 

    }
   free(inList); 

}


/*print list: used for debugging purposes*/ 

void printList(LinkedList* inList)
{

    ListNode* currNode;   

    if(inList->head != NULL)
    {
     	currNode = inList->head; 
     
     while(currNode != NULL)
     {  
     
     	printf("%s", (char*)currNode->data);  
    
       	currNode = currNode->next;   
     }   

    } 

}    



   
