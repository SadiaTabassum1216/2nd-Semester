#include<stdio.h>
#include<stdlib.h>

void createList(int size);
void traverseList();
void insertAtBeginning(int data);

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
    printf("Enter a number to input at the beginning:  ");
    scanf("%d",&x);
    insertAtBeginning(x);
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

void insertAtBeginning(int data)
{

            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            newnode->next=head;
            newnode->prev=NULL;

            temp=newnode;
            temp->next=head;
            head=temp;
            temp=temp->next;
            temp->prev=newnode;
}



