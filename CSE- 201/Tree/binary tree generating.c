#include<stdio.h>
#include<math.h>

void in_Pre_Tree(int flag,int start,int end);

int tree[100],pre[100],in[100],size,n;

int main()
{
int len,i;

printf("Level of the tree: ");
scanf("%d",&len);
size=pow(2,len+1)-1;

printf("\nInput number: ");
scanf("%d",&n);

printf("\nEnter the inorder traversal: ");
for(i=0;i<n;i++){
    scanf("%d",&in[i]);
}
printf("\nEnter the preorder traversal: ");
for(i=0;i<n;i++){
    scanf("%d",&pre[i]);
}

for(i=0;i<size;i++){
    tree[i]=0;
    }

    in_Pre_Tree(0,0,n-1);

printf("\nThe array representation of the binary tree is: ");
for(i=0;i<size;i++){
    if(tree[i]==0)
        printf("_ ");
    else
        printf("%d ",tree[i]);
    }
    printf("\n");

return 0;
}


//generating tree from inorder and preorder traversel
int count=0,flag;//count=0 nile condition count>=n
void in_Pre_Tree(int flag,int start,int end){
    int i;
    if(start>end || count>n || flag>=size)
        return;
        tree[flag]=pre[count];

    for(i=start;i<=end;i++){
        if(pre[count]==in[i]){
            count++;
            in_Pre_Tree(2*flag+1,0,i-1);
            in_Pre_Tree(2*flag+2,i+1,end-1);
            }
        }

}
