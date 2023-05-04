#include<stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
void insertAtBeginning(int data);

struct node
{
    int data;
    struct node* next;
};
struct node *head, *newnode,*temp;

int main()
{
    int x;

    createList();
    traverseList();
    printf("Enter a number to input at the beginning:  ");
    scanf("%d",&x);
    insertAtBeginning(x);
    traverseList();



return 0;
}

void createList()
{
     int i,num,n;
        printf("How many numbers do you want to input?  ");
        scanf("%d",&n);
     head=NULL;

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
    printf("The linked list is:   ");
    while(temp!=NULL){
        printf("%d    ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

void insertAtBeginning(int data)
{

            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            newnode->next=head;

            temp=newnode;
            temp->next=head;
            head=temp;
}

