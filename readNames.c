#include <fcntl.h>  // for open
#include <unistd.h> // for write, read and close
#include <string.h> // for strcpy
#include <stdlib.h> // for malloc
#include "ss.h"

int readNames(char ***names)
{
	char **currentLine;
	*names = malloc(sizeof(char *) * NAMES_BLOCK_MULTIPLE);
	currentLine = *names;

	char line[MAX_NAME_LENGTH];
	int count = 0;
	
	while(scanf("%s\n",line)> 0)
	{
		//create storage for the line, + 1 is needed for the EOL charracter.
		*currentLine = malloc(sizeof(char) * (strlen(line) + 1 ));

		// copy the read string
		strcpy(*currentLine, line);
		
		/*printf("line: %s\n\n", *currentLine);
		char *t = *currentLine;
		for(int i = strlen(currentLine);*t;t++)
			printf("%d, %c > ", *t, *t);

		printf("\n\n");*/

		// increment count
		currentLine++;
		if(++count % NAMES_BLOCK_MULTIPLE == 0){
			*names = realloc(*names,sizeof(char *) *(count +
			NAMES_BLOCK_MULTIPLE));
			currentLine = (*names) + count;
		}
	}
	
	return count;
}

