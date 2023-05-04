//incompleteeeeee

#include<stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
void reverseList();

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head, *newnode,*temp;

int main()
{
    createList();
    traverseList();
    reverseList();
    printf("\n\t\t------------Reverse-------------\n");
    traverseList();


return 0;
}

void createList()
{
     head=NULL;
     int i,num,n;

    printf("How many numbers do you want to input?  ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
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
        printf("\nprev: %8d    Data: %d     address:%8d   next:%8d",temp->prev,temp->data,temp,temp->next);
        //printf("%d    ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverseList()
{
   struct node *nextNode;

    temp=head;

    while(temp!=NULL){
        temp->next=temp->prev;
        temp->prev=newnode;
        temp=nextNode;
        //nextNode=nextNode->next;
    }
    temp=head;// need to use tail

}
