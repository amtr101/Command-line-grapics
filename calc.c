#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include "calc.h" 

#define PI 3.14159265359

/**********************************************************
 * AMy Trevaksis 15129275
 * Calc.c 
 * contains calculation fuctions for coordinates (x, y) using 
 * geometry functions in the math libary
 ***********************************************************/ 


/* angles must be converted from degrees to radians */ 

double calcX(double rotate, double dist)
{
    double calcx, ang;
 
    ang = rotate *  (PI / 180);  

    calcx = dist * cos(ang); 
       


    return calcx;  

} 


double calcY(double rotate, double dist)
{
  
    double calcy, ang;  
    ang = rotate * (PI / 180);    
   
    calcy = dist * sin(ang); 
    


    return calcy;  

}  

/** function passed to PlotFunc, priintd a char */ 


void printC(void* inC)
{
   
    printf("%c",*((char*)inC));     

} 


/*keeps the angle posative and not over 360 */ 

double getAngle(double inAng, double inRot)
{
  if(inRot < 0)
  {
    inAng = 360 - abs(inRot); 
  } 
  
      inAng = inAng + inRot; 


   if (inAng > 360) 
  {

     inAng = 0 + inRot;  
  }
  
  
 

 return inAng; 

}
