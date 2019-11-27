#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** args = parse_args( char * line ){
  char * input = line;
  int length = sizeof(input);
	char ** result = malloc(5 * length);
  int i = 0;

  for (i = 0; line != NULL; i++){
    result = strsep(&line, " ");
  }
  return result;
}

int main() {
	char test[100] = "ls -a -l";
	printf("Line: %s\n", test);
	char ** separated = parse_args(test);
	printf("Parsed, Command executed");
	execvp(separated[0], separated);
	return 0;
}
