#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct HashNode {
  int key;
  int count;
  struct HashNode* next;
} HashNode;

typedef struct HashTable {
  HashNode* table[MAX];
} HashTable;

unsigned int hashFunction(int key)
{
  return key % MAX;
}

void initHashTable(HashTable* tableToInit)
{
  int i = 0;
  for (i=0; i <MAX; i++)
  {
    tableToInit->table[i]=NULL;
  }
}

void insertNode(HashTable* ht, int key)
{
    int index = hashFunction(key);
    HashNode* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            current->count++; // Key exists, increment count
            return;
        }
        current = current->next;// this is for collisions
    }

  //didnt find it so we makin a new one. 
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
 }


int retrieveNode(HashTable* hashTable, int key)
{
  int index = hashFunction(key);
  HashNode* current = hashTable->table[index];
  while(current != NULL)
  {
    if (current->key == key)
    {
      return current->count;
    }
    else{
      current = current->next;
    }

  }
  return 0;

}

int numLines(FILE *_inputTextToCountNumLines)
{
  int c;
  int counter=0;
  while((c=getc(_inputTextToCountNumLines))!= EOF)
    if(c=='\n')
    {
      counter++;
    }
  return counter;
}

void split(FILE *__inputToSplit, int *left, int *right, int rows)
{
  int line1;
  int line2;
  int counter =0;
  while(fscanf(__inputToSplit, "%d %d", &line1, &line2) ==2)
  {
   left[counter]= line1;
   right[counter] = line2;
  counter ++;
  }

}
// uh i think const void cuz qsort wants that. then i cast type it a pointer int??? pointer, of an int? idk wat man. book says it should work tho
int compareInts(const void *a, const void *b) 
{
  return(*(int *)a-*(int *)b);
}



void createDiff(int *diff, int *left, int *right, int rows)
{
for (int i =0; i < rows; i++)
  {
    diff[i]= abs(left[i]-right[i]);
  }
}

int sum(int *diff, int rows)
{
  int summ=0;
  int i=0;
  for (i=0;i< rows;i++) {
    summ+= diff[i];

  }
  return summ;
}
void printArray(int *arr, int len)
{
  int i =0;
  for (i=0;i<len;i++) {
    printf("%d\n", arr[i]);
  }
}

int similarityScore(int *left, int *right, int rows)
{
  int i = 0;
  int j = 0;
  int score=0;
  for (i=0;i<rows;i++) {
    int count=0;
    for (j=0;j<rows;j++)
    {
      if(left[i]==right[j])
      {
        count++;
      }
    }
    score+=count*left[i];
  }
  return score;

}

void main(){
  int nl = MAX;
  FILE *inputs=fopen("./input.txt", "r");
  int left[nl];
  int right[nl];
  int diff[nl];
  split(inputs, left, right, nl);
  HashTable ht;
  initHashTable(&ht);
  int i =0;
  for (i=0;i<nl;i++) {
    insertNode(&ht, right[i]);
  }
  int similarityScore = 0;
  for (i = 0; i < nl; i++)
  {
    int count = retrieveNode(&ht, left[i]); 
    similarityScore+= left[i]*count;
  }
  printf("%d",similarityScore);

  
}

void main2() {
  FILE *inputs=fopen("./input.txt", "r");

  int nl = numLines(inputs);
  rewind(inputs);
  
  int left[nl];
  int right[nl];
  int diff[nl];
  split(inputs, left, right, nl);
  qsort(left, nl, sizeof(int), compareInts);
  qsort(right, nl, sizeof(int), compareInts);
//  printf("%d %d", right[0], right[nl-1]);
  createDiff(diff, left, right, nl);
//  printArray(diff, nl);
 // int size = sizeof(diff) / sizeof(diff[0]);
//  printf("%d\n",size);

  //printf("%d\n", sum(diff, nl));
//  saveDiff(diff, left, right, nl);
 printf("%d\n", similarityScore(left, right, nl) ); 
}

