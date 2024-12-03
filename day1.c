#include <stdio.h>
#include <stdlib.h>

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



void main() {
  FILE *inputs;
  inputs = fopen("./input.txt", "r");
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

