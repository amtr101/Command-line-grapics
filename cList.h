/*********************************************
 * Amy Trevaskis: 15128275
 * cList.h 
 * The headerfile containing the type definition 
 * for ListNode and LinkedList
 * ******************************************/  
#ifndef LIST_H
#define LIST_H

/* ListNode: contains next pointer*/ 

 typedef struct ListNode 
 {
     void* data; 
     struct ListNode* next; 
   

 } ListNode; 

/* LinkedList contains ListNode struct head */ 

 typedef struct 
 {
     ListNode* head; 
     ListNode* tail; 

 } LinkedList;   

/*************************************
 * Forward declarations for LinkedList 
 * functions 
 * ***********************************/ 

 LinkedList* createList(void); 

 void freeList(LinkedList* inList); 

 void insertFirst(LinkedList* inList, void* inData); 

 void insertLast(LinkedList* inList, void* inData); 

 ListNode* getNext(ListNode* inNode); 

 void printList(LinkedList* inList); 

 void* removeFirst(LinkedList* inList);  

#endif 
