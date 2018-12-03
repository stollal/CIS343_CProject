#include "file_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv){
	char* buff;
	int fileSize;
	char **buffer = &buff;
	fileSize = read_file(argv[1], buffer);

	if(argc !=3){
		fprintf(stderr, "Wrong number of arguements!");
		return 1;
	}
	else{
		fileSize = read_file(argv[1], buffer);

		char *reverseB;
		reverseB = (char *)malloc(fileSize * sizeof(char));

		int j = 0;
		for(int i = strlen(buff)-1; i >= 0; i--){
			reverseB[i] = buff[j];
			j++;
		}
		write_file(argv[2], reverseB, fileSize);
		free(reverseB);
		free(buff);
	}
	return 0;
}
