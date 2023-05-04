#include<stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
int length();

struct node
{
    int data;
    struct node* next;
};
struct node *head, *newnode,*temp;

int main()
{   int len;

    createList();
    traverseList();
    len=length();
    printf("\nThe length of the list is: %d\n",len);


return 0;
}

void createList()
{
     int i,num;
     head=NULL;

    for(i=0;;i++){
        printf("Input data: ");
        if(scanf("%d",&num)==EOF)//press Ctrl+z
            break;
        else{
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

int length()
{
        int i=0;
        temp=head;

        while(temp!=NULL){
            temp=temp->next;
            i++;
            }
return i;
}



