#include <stdio.h>
#include <stdlib.h>

int upper(int character, int shift) {
	character += shift;
	if (character > 90) {
		character = (character-90)%26 + 64;
	}
	else if (character < 65) {
		character = (65-character)%26;
		if (character == 0) return 65;
		character = 91 - character;
	}
	return character;
}

int lower(int character, int shift) {
	character += shift;
	if (character > 122) {
		character = (character-122)%26 + 96;
	}
	else if (character < 97) {
		character = (97-character)%26;
		if (character == 0) return 97;
		character = 123 - character;
	}
	return character;
}


int main(int argc, char* argv[]) {
	int shift = atoi(argv[1]);
	int character = getchar();
	while (character != EOF) {
		if (character >= 'A' && character <= 'Z') {
			putchar(upper(character, shift));
		}
		else if (character >= 'a' && character <= 'z') {
			putchar(lower(character, shift));
		}
		else putchar(character);
		character = getchar();
	}
}
