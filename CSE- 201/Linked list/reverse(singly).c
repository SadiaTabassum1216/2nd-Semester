#include<stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
void reverseList();

struct node
{
    int data;
    struct node* next;
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

        if(head==NULL){ //empty list
            head=temp=newnode;
            }
        else{
            temp->next=newnode;
            temp=temp->next;
        }
    }
}

void traverseList()
{
    temp=head;
    printf("\nThe linked list is:   ");
    while(temp!=NULL){
        printf("%d    ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverseList()
{
   struct node *prevNode, *nextNode;

    prevNode=NULL;
    temp=nextNode=head;

    while(nextNode!=NULL){
        nextNode=nextNode->next;
        temp->next=prevNode;
        prevNode=temp;
        temp=nextNode;
    }
    head=prevNode;
}
