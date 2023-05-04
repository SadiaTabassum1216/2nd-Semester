#include<stdio.h>
#include<stdlib.h>

void createList(int size);
void traverseList();

struct node
{
    int data;
    struct node* next;
};
struct node *head, *newnode,*temp;

int main()
{
    int n;
    printf("How many numbers do you want to input?  ");
    scanf("%d",&n);

    createList(n);
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

        if(head==NULL){ //empty list
            head=temp=newnode;
            }
        else{
            temp->next=newnode;
            temp=temp->next;
        }
        temp->next=head;
    }

}

void traverseList()
{
    temp=head;
    printf("The linked list is:   ");
    while(temp->next!=head){
        printf("\nData:%4d    Address:%8d   Next:%8d    ",temp->data,temp,temp->next);
        temp=temp->next;
    }

    printf("\nData:%4d    Address:%8d   Next:%8d    ",temp->data,temp,temp->next);
    printf("\n");
}


