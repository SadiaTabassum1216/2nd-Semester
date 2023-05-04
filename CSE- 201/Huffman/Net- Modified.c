#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct MinHeapNode {
  char item;
  unsigned freq;
  struct MinHeapNode *left, *right;
};

struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

struct encrypt{
char a;
int codeSize;
int *code;
};

struct encrypt *table;

int x=0;

// Create nodes
struct MinHeapNode *newNode(char item, unsigned freq) {
  struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

  temp->left = temp->right = NULL;
  temp->item = item;
  temp->freq = freq;

  return temp;
}

// Create min heap
struct MinHeap *createMinH(unsigned capacity) {
  struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));

  minHeap->size = 0;

  minHeap->capacity = capacity;

  minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
  return minHeap;
}

// Function to swap
void swapMinHNode(struct MinHeapNode **a, struct MinHeapNode **b) {
  struct MinHeapNode *t = *a;
  *a = *b;
  *b = t;
}

// Heapify
void minHeapify(struct MinHeap *minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

// Extract min
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
  struct MinHeapNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}

// Insertion function
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap *minHeap) {
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

struct MinHeap *createAndBuildMinHeap(char item[], int freq[], int size) {
  struct MinHeap *minHeap = createMinH(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

struct MinHeapNode *buildHuffmanTree(char item[], int freq[], int size) {
  struct MinHeapNode *left, *right, *top;
  struct MinHeap *minHeap = createAndBuildMinHeap(item, freq, size);

  while (!(minHeap->size == 1)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('*', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

//to create a table
struct encrypt * createTabledata(char item,int data[],int size)
{

    struct encrypt *temp=(struct encrypt*)malloc(sizeof(struct encrypt));
    temp->code=(int*)malloc(size*sizeof(int));
    temp->codeSize=size;
    temp->a=item;
    for(int i=0;i<size;i++)
       temp->code[i]=data[i];

    *(table+x)=*temp;

    return temp;

}


// Print the array
void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", arr[i]);

  printf("\n");
}

void printHCodes(struct MinHeapNode *root, int arr[], int top) {
    int i=0;
  if (root->left) {
    arr[top] = 0;
    printHCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printHCodes(root->right, arr, top + 1);
  }
  if (!(root->left) && !(root->right)) {
    struct encrypt *temp=(struct encrypt*)malloc(sizeof(struct encrypt));
    temp=createTabledata(root->item,arr,top);

    printf("  %c   | ", temp->a);
    printArray(temp->code, top);
    x++;
  }
}


void HuffmanCodes(char item[], int freq[], int size) {
  struct MinHeapNode *root = buildHuffmanTree(item, freq, size);

  int arr[50], top = 0;

  printHCodes(root, arr, top);
}

int encodeData(char str[], struct encrypt *table,int encryptedData[1000])
{
    int i,j,k,x=0;
    for(i=0;i<strlen(str);i++)
    {
        for(j=0;;j++)
        {
            if(str[i]==table[j].a){
               for(k=0;k<table[j].codeSize;k++,x++)
                    encryptedData[x]=table[j].code[k];
                break;
                }
        }
    }
    for(int i=0;i<x;i++)
        printf("%d",encryptedData[i]);

    return x;
}

int compareArrays(int a[], int b[], int n)
{
  for (int i=0; i<n; ++i)
  {
      if (a[i] != b[i])
      {
          return -1;
      }
  }
  return 0;
}

void decodedData(int encryptedData[],int size,struct encrypt *table,int datanum)
{
    int i,j=0,l,k;
    int decode[100];
    for(i=0;i<size;i++,j++)//traversing the whole encrypted data
    {
        decode[j]=encryptedData[i];
        for(k=0;k<datanum;k++)//datanum is basically the number of data in table
        {
            if(compareArrays(decode,table[k].code,table[k].codeSize)==0){//this is the one
                printf("%c",table[k].a);
                for(l=0;l<table[k].codeSize;l++)
                    decode[l]=-1;
                j=-1;
                break;
            }
        }
    }
}

int main() {

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

    printf("Given string: ");
    printf("%s",string);

   fclose(fp);

//frequency counting
   int j=0;
   int frequency[100]={0};

     for(i=0; i<len; i++){
        frequency[string[i] - 32]++;
   }

  printf("\n\nFrequency of all characters in string: \n");
   for(i=0; i<100; i++)
      if(frequency[i] !=0){
            str[j]=32+i;
            printf("'%c' = %d\n", str[j], frequency[i]);
            frequency[j++]=frequency[i];
      }
    str[j]='\0';

    dataNum=strlen(str);
    int size=dataNum;

    table= (struct encrypt *)malloc(dataNum * sizeof(struct encrypt ));


    printf(" Char | Huffman code \n");
    HuffmanCodes(str,frequency,size);

    int encryptedData[1000];
    printf("\nEncoded data: ");
    int l=encodeData(string,table,encryptedData);
    //printf("\nsize=%d",l);

    printf("\n\nDecoded data: ");
    decodedData(encryptedData,l,table,dataNum);
    printf("\n");
}
