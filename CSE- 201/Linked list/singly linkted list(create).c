#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node *newnode,*temp;
int head;

int main()
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

    temp=head;
    printf("The linked list is:   ");
    while(temp!=NULL){
        printf("%d    ",temp->data);
        temp=temp->next;
    }
    printf("\n");

return 0;
}
