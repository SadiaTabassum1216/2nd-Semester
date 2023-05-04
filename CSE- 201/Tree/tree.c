#include<stdio.h>
#include<math.h>

int main()
{
int i,j=1,size,n,l;

printf("Level of the tree: ");
scanf("%d",&l);

printf("How many elements do you want as input?");
scanf("%d",&n);

size=pow(2,l+1)-1;
int tree[size];

for(i=1;i<size;i++){
    tree[i]=-1;
    }

printf("Enter the root:");
scanf("%d",&tree[0]);
for(i=1;j<n;i++){

    printf("Left child: ");
    scanf("%d",&tree[2*i+1]);
        if(tree[2*i+1]!=0)
        j++;
    printf("Right child: ");
    scanf("%d",&tree[2*i+2]);
        if(tree[2*i+2]!=0)
        j++;
}

for(i=0;i<size;i++){
    if(tree[i]==-1)
        printf(" ");
    else if(tree[i]==0)
        printf("_ ");
    else
        printf("%d ",tree[i]);
    }
return 0;
}
