#include "cList.h" 
#include "read.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_LINE 25

/***********************************
 * Amy Trevaskis 15129275
 * readIn: a function for reading in 
 * the file and inserting into the 
 * Linked List. Uses fgets 
 * ********************************/ 


/*MAX_LINE is defined as the resonable maximum length of
 * each command line */ 

void readIn(FILE* inFile, LinkedList* cmdList)  
{
	 
    char  str[MAX_LINE]; 
    char* data;         

    while(fgets(str, MAX_LINE, inFile) != NULL)
    { 

      data = (char*)malloc(MAX_LINE *  sizeof(char)); 
      caseA(str); 
      strcpy(data + 1 , str);   

      insertLast(cmdList, data);      
    	
    }   
      fclose(inFile); 
      
} 

/**************************
 * caseA: converts a char
 * array into uppercase. used 
 * in prac 4
 * ***********************/  


void caseA(char* word)
{
    
    int i, temp,  len = strlen(word); 
 
    for(i = 0; i< len; i++)
    {
       if(word[i] >= 97)
      {
      word[i] = word[i] -32; 
      }
    }
}
 



