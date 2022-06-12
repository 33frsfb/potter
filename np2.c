#include<stdio.h>

void bitstuff(int n,int arr[]);

int main(){

    int n,inparr[50];
    
    printf("enter the no of bits\n");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
    
     scanf("%d",&inparr[i]);
     
    }
    
    bitstuff(n,inparr);
    
    return 0;
   }
   
   
void bitstuff(int n,int arr[]){

    int stuffed[50];
    int oncount=1;
    int i=0,j=0,k=0;
    
    while(i<n)
    {
    
      if(arr[i]==1){
      
        stuffed[j]=arr[i];
        
        for(k=i+1;arr[k]==1&&k<n&&oncount<5;k++){
        
          j++;
          stuffed[j]=arr[k];
          oncount++;
          
	  if(oncount==5){
	     j++;
	   stuffed[j]=0;
	   }
	   
	   i=k;
        
      }
    }
      
      else{
        
        oncount=1;
        stuffed[j]=arr[i];
        }
        
        i++;
        j++;
   }
   
    
    printf("01111110");
    
    for(i=0;i<j;i++)
    {
       printf("%d",stuffed[i]);
    }
    
     printf("01111110");
     
     printf("/n");
     
     
     
     int temp[50];
     int  t=0;
     int count=0;
     
     
     for(int i=0;i<j;i++)
     {
        if(stuffed[i]==1)
        {
          count++;
          temp[t++]=1;
        }
        
        if(stuffed[i]==0)
        {
           count=0;
           temp[t++]=0;
        }
        
        if(count==5 && stuffed[i+1]==0)
        {
          i++;
          count=0;
        }
        
      }
      
      
      printf("received frame\n");
      
      for(i=0;i<t;i++)
      {
         printf(" %d ",temp[i]);
      }
      
    }
          
    
    
    
      
        
        
