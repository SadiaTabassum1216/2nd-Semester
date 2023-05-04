#include<stdio.h>
#include<string.h>
#include <stdlib.h>


struct MinHeapNode { //this one is for each node of the huffman tree
	char data;
	int freq;
	struct MinHeapNode *left, *right;
};
struct MinHeap {
  int size;
  struct MinHeapNode **node;
};

struct MinHeapNode *root;


struct MinHeapNode *newNode(char item,int freq);
void heapSort(struct MinHeap *minHeap);
void BuildMinHeap(struct MinHeap *minHeap);
void MinHeapify(struct MinHeap *minHeap,int i);
struct MinHeapNode *extract(struct MinHeap *minHeap);
void buildHuffmanTree(struct MinHeap *minHeap);
void printHCodes(struct MinHeapNode *root, int arr[], int top);
void printArray(int arr[], int n);

void Preorder(struct MinHeapNode *root);

int main()
{
    char string[1000],str[100];//string=total text from file; str=unique letters
    int len,i,dataNum;
    FILE *fp;

   fp = fopen("text.txt","r");

    if(fp == NULL){
      printf("Error!");
      return 0;
   }

   fgets(string,sizeof(string),fp);
   len=strlen(string);

    printf("%s",string);

   fclose(fp);

//frequency counting
   int j=0;
   int frequency[100]={0};

     for(i=0; i<len; i++){
        frequency[string[i] - 32]++;
   }

  printf("\nFrequency of all characters in string: \n");
   for(i=0; i<100; i++)
      if(frequency[i] !=0){
            str[j]=32+i;
            printf("'%c' = %d\n", str[j], frequency[i]);
            frequency[j++]=frequency[i];
      }
    str[j]='\0';

    dataNum=strlen(str);

    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size=dataNum;
    minHeap->node= (struct MinHeapNode **)malloc(dataNum*sizeof(struct MinHeapNode *));

    for(i=0;i<dataNum;i++){ //storing in a array of struct pointers
        minHeap->node[i]=newNode(str[i],frequency[i]);
   }

        printf("\n%s\t\t","Data: ");
    for(i=0;i<dataNum;i++){
    printf("%2c",minHeap->node[i]->data);
    }
        printf("\n%s\t","Frequency: ");
    for(i=0;i<dataNum;i++){
    printf("%2d",minHeap->node[i]->freq);
    }

    BuildMinHeap(minHeap);

    printf("\n%s\t","Frequency: ");
    for(i=0;i<dataNum;i++){
    printf("%2d",minHeap->node[i]->freq);
    }
    printf("\ndatanum= %d\n",dataNum);//okay

    buildHuffmanTree(minHeap);
     int arr[20], top = 0;

    //printHCodes(root, arr, top);
  //Preorder(root);
return 0;
}

struct MinHeapNode *newNode(char item,int freq)
{
  struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

  temp->left = temp->right = NULL;
  temp->data = item;
  temp->freq = freq;

  return temp;
}
void heapSort(struct MinHeap *minHeap)
{
    int n=minHeap->size;

    BuildMinHeap(minHeap);
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    // One by one extract an element from heap
    for (int i=n-1;i>0;i--) {
        temp=minHeap->node[0];
        minHeap->node[0]=minHeap->node[i];
        minHeap->node[i]=temp;

        MinHeapify(minHeap,0);
    }
}
void HeapIncrease(struct MinHeap *minHeap,struct MinHeapNode *key)
{
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    int i=minHeap->size-1;
    if(key->freq>minHeap->node[i]->freq);//New key is larger than current key
    minHeap->node[i]=key;

     while(minHeap->node[i]->freq<minHeap->node[(i-1)/2]->freq && i>1){
        temp=minHeap->node[(i-1)/2];
        minHeap->node[(i-1)/2]=minHeap->node[i];
        minHeap->node[i]=temp;
        i=(i-1)/2;
       }

}

void MinHeapify(struct MinHeap *minHeap,int i)
{
    struct MinHeapNode *temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    int l,r,smallest,n;
    smallest=i;
    l=2*i+1;
    r=2*i+2;
    n=minHeap->size;

    while(l<n && minHeap->node[l]->freq <minHeap->node[smallest]->freq){
        smallest=l;
    }

    while(r<n && minHeap->node[r]->freq <minHeap->node[smallest]->freq){
        smallest=r;
    }

    if(smallest!=i){
        temp=minHeap->node[smallest];
        minHeap->node[smallest]=minHeap->node[i];
        minHeap->node[i]=temp;
        MinHeapify(minHeap,smallest);
    }
}

void BuildMinHeap(struct MinHeap *minHeap)//n is size
{
    int i,n;
    n=minHeap->size;

    for(i=n/2-1;i>=0;i--){
        MinHeapify(minHeap,i);
    }
}

void buildHuffmanTree(struct MinHeap *minHeap)
{
    struct MinHeapNode *left, *right,*temp;

    //heapSort(minHeap);

    for (;minHeap->size!=1;){
    left=extract(minHeap);
    right=extract(minHeap);
    temp->data = '*';
    temp->freq = left->freq+right->freq;
    temp->left=left;
    temp->right=right;
    minHeap->size++;
    HeapIncrease(minHeap,temp);

    printf("\nfreq=%d",minHeap->node[0]->freq);
    printf("   left=%d",minHeap->node[0]->left);//here is the problem
    printf("   right=%d",minHeap->node[0]->right);
    printf("\n******Tree size: %d",minHeap->size);
    }

    //printf("\n***Tree size: %d     Node Number:%d***",size,nodenum);

    printf("\nRoot : %d",minHeap->node[0]);

    root=minHeap->node[0];//there is some problem
    printf("\nRoot : %d",root);
    printf("\nLeft : %d",root->left->freq);
    printf("\nRight : %d",root->right->freq);
}

struct MinHeapNode *extract(struct MinHeap *minHeap)
{

    struct MinHeapNode *temp = minHeap->node[0];
    minHeap->node[0]=minHeap->node[minHeap->size-1];
    minHeap->size--;
    MinHeapify(minHeap,0);
    return temp;
}

void printHCodes(struct MinHeapNode *root, int arr[], int top)
{
  if (root->left) {
    arr[top]= 0;//printf("%d    ",top);
    printHCodes(root->left, arr, top+1);

  }
  if (root->right) {
    arr[top] = 1;//printf("%d    ",top);
    printHCodes(root->right, arr, top + 1);

  }
  if ((root->left)==NULL && (root->right)==NULL) {
    printf("\n  %c   : ", root->data);//need to store them too
    printArray(arr, top);
    return;
  }
}
// Print the array
void printArray(int arr[], int n)
{
  int i;
  for (i=0;i<n;i++)
    printf("%d", arr[i]);

  printf("\n");
}

void Preorder(struct MinHeapNode *root)
{   if(root==NULL)
        return;
    else{
    printf("Data:%c  Freq: %d",root->data,root->freq);
    Preorder(root->left);
    Preorder(root->right);
    }
}
