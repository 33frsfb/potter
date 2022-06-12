#include<stdio.h>
#define MIN(X,Y) (X>Y)?Y:X

int main(){

  int count=0,drop=0,i=0,x,cap,inp[10]={0},nsec,ch,rate;
  
    printf("entre the bucket size: \n");
    scanf("%d",&cap);
    
    printf("enter the output rate \n");
    scanf("%d",&rate);
    
    do{
    
      printf("enter the incoming packets %d\n",i+1);
      
      scanf("%d",&inp[i]);
      
      if(inp[i]>cap){
      
        printf("bucket overflow ,packets discraded\n");
        
        exit(0);
        }
        
        i++;
        
        printf(" enter 1 or 0 to quit or continue\n");
        scanf("%d",&ch);
        
 }while(ch);
    
    
   nsec=i;
   printf("\t second \t received \t sent \t drop \t remained \n");
   
   for(i=0;count||i<nsec;i++){
   
      printf("%d",i+1);
      printf("\t\t%d\t",inp[i]);
      printf("\t%d\t",MIN((inp[i]+count),rate));
      if((x=inp[i]+count-rate)>0)
      {
             if(x>cap)
             {
               count=cap;
               drop=x-cap;
             }
             else
             {
             
               count=x;
               drop=0;
             }
             
       }
       else
       {
           drop=0;
           count=0;
       }
       
       printf("\t %d\t %d \n",drop,count);
    
     
    }
     
     return 0;
 }         
             
        
        
          
