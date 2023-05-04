#include<stdio.h>
#include<stdlib.h>

void createList(int size);
void traverseList();
void deletionAnywhere(int position);

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head, *newnode,*temp;

int main()
{
    int n,pos;
    printf("How many numbers do you want to input?  ");
    scanf("%d",&n);

    createList(n);
    traverseList();
    printf("Enter the position: ");
    scanf("%d",&pos);
    printf("\n\n\t\t\t ***Deletion***  \n");
    deletionAnywhere(pos);
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
    printf("The linked list is:   ");
    while(temp!=NULL){
        printf("\nprev: %8d    Data: %d     address:%8d   next:%8d",temp->prev,temp->data,temp,temp->next);
        //printf("%d   ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void deletionAnywhere(int position)
{
    int i=1;
            temp=head;
            while(i!=position){
                temp=temp->next;
                i++;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            printf("\nDeleted value: %d\n",temp->data);
            free(temp);
}

