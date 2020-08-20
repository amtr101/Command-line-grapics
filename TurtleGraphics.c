#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <math.h> 
#include "cList.h" 
#include "read.h" 
#include "calc.h"
#include "effects.h" 


/*************************************
 * Amy Trevaskis 15129275
 * TurtleGraphics 
 * the main fuction for the turtle 
 * graphics program
 * ************************************/ 
 

/*forward declaratiom for processCmd*/ 

void processCmd(LinkedList* cmdList); 
  

int main(int argc[], char* argv[]) 
{ 
    
    char* fileName = argv[1];  
    FILE* fi = NULL;   
    LinkedList* cmdList = NULL;   
    cmdList = createList();    
     
    fi = fopen(fileName, "r"); 
   
    if(fi == NULL)
    {
	perror("Error opening file:"); 
    }
    else 
    {

    	readIn(fi,cmdList);  
        processCmd(cmdList);  
   
    } 

      return 0; 
} 
 
/***************************
 * processCmd: takes in a linked List of
 * strings and processes each string using 
 * sscanf to feed data into the line()
 * function
 * **********************************/  


void processCmd(LinkedList* cmdList) 
{

    FILE* outLog; 

    char* tempStr = NULL;  
    char tag[10];   /*tag is defined as 10: the max size for the commands from the file*/ 
    char* label = NULL; 

    ListNode* tempNd = NULL; 
    PlotFunc plotter = &printC;   
    
    int x1, x2, y1, y2;  
    int	 fg,  bg; 
    double ang = 0; 
    double rot, dist, calcx, calcy, calcx0, calcy0;      
    char pat ='+' ;  
    void* plotData = NULL; 
 
    rot = 0; 
    dist = 0; 
    calcx = 0; 
    calcy = 0; 
    calcx0 = 0; 
    calcy0 = 0;   

    x1 = 0; 
    x2 = 0; 
    y1 = 0; 
    y2 = 0; 
    fg = 7; 
    bg = 0; 

    tempNd = cmdList->head; 

    outLog = fopen("graphics.log", "a"); 

    clearScreen(); 


 while(tempNd != NULL)
 {
 
     tempStr = (char*)tempNd->data + 1;    
     sscanf(tempStr, "%s", tag); 
            
     if(tag[0] == 'D') 
     {
      sscanf(tempStr, "%s %lf", tag, &dist); 
  
      x1--; 
      y1--; 
      x2--; 
      y2--;      
    
      label = "DRAW"; 

      }  
      else if(tag[0] == 'M') 
      {
       	sscanf(tempStr, "%s %lf", tag, &dist);
      	pat = ' '; 
        label = "MOVE"; 

      } 
      else if(tag[0] == 'R')
      {
      	sscanf(tempStr, "%s %lf", tag, &rot);
        ang = getAngle(ang, rot); 
  
       } 
      else if(tag[0] == 'F') 
       { 
	sscanf(tempStr, "%s %d", tag, &fg);

       } 
       else if(tag[0] == 'B')
       {
         sscanf(tempStr, "%s %d", tag, &bg);
	
       } 
       else if(tag[0] == 'P')
        {
          sscanf(tempStr, "%s %c", tag , &pat); 
        }  
             
  	plotData = &pat;
 
 	calcx += calcX(ang, dist); 
        x2 = floor(calcx); 
        calcy -= calcY(ang, dist); 
 	y2 = floor(calcy);     
        

     #ifndef SIMPLE

        setFgColour(fg); 
	setBgColour(bg); 

      #endif

     
       fprintf(outLog, " %s  ( %lf,  %lf) - ( %lf, %lf)\n", label, calcx0, calcy0, calcx, calcy );  
      
      #ifdef DEBUG    
     
       fprintf(stdout, " %s  ( %lf,  %lf) - ( %lf, %lf)\n", label, calcx0, calcy0, calcx, calcy );
    
       #endif 

       
       line(x1,y1,x2, y2, plotter, plotData);      
        
	
	x1 = x2; 
        y1 = y2;
        calcx0 = calcx; 
        calcy0 = calcy;  	

        dist = 0; 
	
	tempNd = tempNd->next; 
       
      }       
      
       fprintf(outLog, "----------\n" ); 

       penDown(); 
       fclose(outLog); 
       freeList(cmdList); 
       


} 

 
