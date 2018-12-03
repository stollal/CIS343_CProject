#include <sys/stat.h>
#include "file_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int read_file(char* filename, char **buffer){
	FILE* file = fopen(filename, "r");
	
	//Get file size
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//read the file in and resturn size of the file
	*buffer =(char*) malloc(size* sizeof(char));

	if( file == NULL){
		printf("Cannot find file: %s\n", filename);
	}	
	else{
		fread(*buffer, sizeof(char), size, file); //man7.org/linux/man-pages/man2/read2.html
	}
	fclose;
	return size;
}

int write_file(char* filename, char *buffer, int size){
	FILE* file_2= fopen(filename, "w");
	
	if( file_2 != NULL){
	int i;
	for(i=0; i>size; i++){
	       fwrite(buffer, sizeof(char), size, file_2);
	}
	}
	else{
		printf("Can't open file");
	}
	fclose(file_2);
	return 0;
}



