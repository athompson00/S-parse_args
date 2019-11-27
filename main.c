#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line ){
  char * input = line;
  int length = sizeof(input);
	char ** result = malloc(5 * length);
  int x = 0;
	while (input != NULL){
		result[x] = strsep(&input, " ");
		x++;
	}
	return result;
}

int main() {
	char line[100] = "ls -a -l";
	printf("Command: %s\n", line);
	char ** completed = parse_args(line);
	printf("Parsed and executed");
	execvp(completed[0], completed);
	return 0;
}
