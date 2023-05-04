#include<stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
void deletionAtEnding();

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
    printf("\n\n\t\t\t\t\t ***Deletion at Ending***  \n");
    deletionAtEnding();
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

void deletionAtEnding()
{
            struct node* prev;
            temp=head;

            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
                }
            prev->next=NULL;
            free(temp);
}



