#include<stdio.h>
#include<math.h>

int main()
{

int tree[100],pre[100],in[100],subtree[100];
int size,len,pre_index=0,x,n,i,j,k,end,flag=0,sub_size,left_count=0,right_count=0,temp;

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

for(i=0;i<size;i++){    //initializing tree
    tree[i]=0;
    }

for(i=0;i<n;i++){       //initializing subtree
    subtree[i]=in[i];
    }
    tree[0]=pre[0];

for(k=1;k<n;k++){
    for(x=0;x<n;x++){  //searching in inorder(subtree) traversal
            temp=0;
        if(pre[pre_index]!=subtree[x])
            temp++;
        else{
            end=x;
            if(temp>=0){
                for(i=0,j=0;i<x;i++,j++)
                        subtree[j]=in[i];
                    flag=2*left_count+1;
                    left_count=flag;
                    tree[flag]=pre[pre_index];
                    pre_index++;
                }
            else{
                for(i=x+1,j=0;i<n;i++,j++)
                        subtree[j]=in[i];
                    flag=2*right_count+2;
                    right_count=flag;
                    tree[flag]=pre[pre_index];
                    pre_index++;
                }
            x=-1;
            }
        }
    }

printf("\nThe array representation of the binary tree is: ");
for(i=0;i<size;i++){
    if(tree[i]==0)
        printf("_ ");
    else
        printf("%d ",tree[i]);
    }

return 0;
}

