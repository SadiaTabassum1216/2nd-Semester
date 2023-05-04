
#include<stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
void insertAnywhere(int data,int position);

struct node
{
    int data;
    struct node* next;
};
struct node *head, *newnode,*temp;

int main()
{
    int x,pos;

    createList();
    traverseList();
    printf("Enter a number to input:  ");
    scanf("%d",&x);
    printf("Enter the position: ");
    scanf("%d",&pos);
    insertAnywhere(x,pos);
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

void insertAnywhere(int data,int position)
{

            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            newnode->next=NULL;

            temp=head;
            int i=2;

            if(position==1)
            {
                temp=newnode;
                newnode->next=head;
                head=temp;
            }
            else{
            while(i!=position){
                temp=temp->next;
                i++;
                }
            newnode->next=temp->next;
            temp->next=newnode;
            }

}

