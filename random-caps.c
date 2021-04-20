#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define CAPS_PROBABILITY 50

char randomCaps(char c) {
	if (isalpha(c)) {
		return rand() % 100 >= CAPS_PROBABILITY ? toupper(c) : c;
	} else {
		return c;
	}
}

int main() {
	char buffer[BUFFER_SIZE];
	while (read(STDIN_FILENO, buffer, BUFFER_SIZE)) {
		for (size_t i = 0; i < BUFFER_SIZE; ++i) {
			buffer[i] = randomCaps(buffer[i]);
		}

		printf("%s", buffer);
	}
}
