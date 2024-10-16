#include <stdio.h>
#include <stdlib.h>

#define Max 6

int queue[Max];
int r=-1;  //r-rear
int f=-1;  //f-front
void display();
void enqueue(); //insertion
void dequeue(); //deletion

int main()
{
    int choice;
    while(1)
    {
        printf("\n\nPerform operation on queue:");
        printf("\n1.Insert the element's \n2.Delete the element \n3.Display \n4.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 01:
            enqueue();
            break;
        case 02:
            dequeue();
            break;
        case 03:
            display();
            break;
        case 04:
            exit(0);
        default:
            printf("\n Invalid Choice!!");
        }
    }
}

void enqueue()
{
    int x;
    if (r==Max-1)
    {
        printf("\nQueue is full (or) Overflow!!");
        return;
    }
    else
    {
     if(f==-1)
     {
         f=0;
     }
     printf("Enter the elements to be inserted: ");
     for(int i=0;i<Max;i++)
     {
         scanf("%d",&x);
         r=r+1;
         queue[r]=x;
     }
    }
}

void dequeue()
{
    if(f==-1 || f>r)
    {
        printf("\nQueue is empty (or) Underflow!!");
        return;
    }
    else
    {
        printf("\n Deleted element is: %d",queue[f]);
        f=f+1;
    }
}

void display()
{
    if(f==-1 || f>r)
    {
        printf("\nQueue is empty (or) Underflow!!");
        return;
    }
    else
    {
        printf("\nQueue elements: \n");
        for(int i=f;i<=r;i++)
            printf("%d  ",queue[i]);
    }
}
