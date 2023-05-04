#include<stdio.h>
#include<stdlib.h>

void createList(int size);
void traverseList();
void insertAtEnding(int data);

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head, *newnode,*temp;

int main()
{
    int n,x;
    printf("How many numbers do you want to input?  ");
    scanf("%d",&n);

    createList(n);
    traverseList();
    printf("Enter a number to input at the Ending:  ");
    scanf("%d",&x);
    insertAtEnding(x);
    traverseList();


return 0;
}

void createList(int size)
{
     head=NULL;
     int i,num;

    for(i=0;i<size;i++){
        printf("Input data: ");
        scanf("%d",&num);

            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=num;
            newnode->next=NULL;
            newnode->prev=NULL;

        if(head==NULL){ //empty list
            head=temp=newnode;
            }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
    }

}

void traverseList()
{
    temp=head;
    printf("\nThe linked list is:   ");
    while(temp!=NULL){
        //printf("\nprev: %8d    Data: %d     address:%8d   next:%8d",temp->prev,temp->data,temp,temp->next);
        printf("%d   ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insertAtEnding(int data)
{

            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            newnode->next=NULL;
            newnode->prev=NULL;

            temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;

}




