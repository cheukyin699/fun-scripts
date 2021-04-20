#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
	char buffer[BUFFER_SIZE];
    ssize_t bs;
	while ((bs = read(STDIN_FILENO, buffer, BUFFER_SIZE / 2 - 1))) {
        memset(buffer + bs, ' ', bs);
		for (size_t i = bs - 1; i > 0; --i) {
            buffer[2 * i] = buffer[i];
            buffer[i] = ' ';
		}

        printf("%s", buffer);
	}
}

