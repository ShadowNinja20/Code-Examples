#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include "frequencies.h"

bool calc_frequencies(Frequencies freq, const char* path, const char** a_error) {
	FILE* stream = fopen(path, "r");
	bool is_true = true;
	if(stream == NULL) {
		is_true = false;
		*a_error = strerror(errno);
	}
	else {
		for(char ch = fgetc(stream); ! feof(stream); ch = fgetc(stream)) {
			freq[(int)ch] = freq[(int)ch] + 1;
		}
	}
	fclose(stream);
	return is_true;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
