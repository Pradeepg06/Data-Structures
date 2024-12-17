#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10
int h[TABLE_SIZE]={NULL};
void insert()
{ 
    int key,index,i,hkey; 
    printf("\nEnter a value to insert into hash table: \n"); 
    scanf("%d",&key); 
    hkey=key%TABLE_SIZE; 
    for(i=0;i<TABLE_SIZE;i++)   
    {      
     index=(hkey+i)%TABLE_SIZE;     
        if(h[index] == NULL)   
        {        
        h[index]=key;         
         break;     
        }    
     
    }    
    printf("No. of probes for %d is %d", key,i+1);
    if(i == TABLE_SIZE)    
    printf("\nElement cannot be inserted\n");
    
}
void search()
{ 
   int key,index,i,hkey;
   printf("\nEnter element to search :\n"); 
   scanf("%d",&key); 
   hkey=key%TABLE_SIZE; 
   for(i=0;i<TABLE_SIZE; i++)
    {    
     index=(hkey+i)%TABLE_SIZE; 
     if(h[index]==key)   
       {      
         printf("Value is found at index %d",index);    
         break;   
       }  
    }  
    if(i == TABLE_SIZE)   
    printf("%d Value is not found\n",key);
}

void display()
{  
    int i;  
    printf("\nElements in the hash table are: \n"); 
    for(i=0;i< TABLE_SIZE; i++) 
    printf("\nAt index %d \t value =  %d",i,h[i]);
}
int main()
{    int opt,i;
     while(1)   
     {
        printf("\n\nMenu \n1. Insert \n2. Display  \n3. Search \n4. Exit \n \nEnter your choice:");  
        scanf("%d",&opt);    
    switch(opt)       
    {           
     case 1:insert();
            break;          
     case 2:display();               
            break;           
     case 3:search();                
            break;            
     case 4:exit(0);
            printf ("Exiting..");
     default: printf("Invalid choice!");      
    }    
 }
}

    