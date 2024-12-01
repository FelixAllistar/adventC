#include <stdio.h>
#include <stdint.h>
/* copy input to output; 1st version */
void main()
{
  int input, blanks, tabs, newlines;
  blanks = tabs = newlines = 0;
  while ((input = getchar()) != EOF){
    if(input== ' ')
      blanks++;
 
    if(input== '\t')
      tabs++;

    if(input == '\n')
      newlines++;


  }


  printf("blanks: %d  tabs: %d  Newlines: %d", blanks, tabs, newlines);
}
