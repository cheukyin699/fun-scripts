#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

char rot13(char c) {
    if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm')) {
        return c + 13;
    } else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z')) {
        return c - 13;
    } else {
        return c;
    }
}

int main() {
	char buffer[BUFFER_SIZE];
	while (read(STDIN_FILENO, buffer, BUFFER_SIZE)) {
		for (size_t i = 0; i < BUFFER_SIZE; ++i) {
			buffer[i] = rot13(buffer[i]);
		}

		printf("%s", buffer);
	}
}

