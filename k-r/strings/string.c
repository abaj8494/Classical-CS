int strlen(char *a)
{
	for (i = 0; a[i] != 0; i++) ; return i;
}

void strcpy(char *a, char *b)
{
	for (i = 0; (a[i] = b[i]) != 0; i++) ;
}

int strcmp(char *a, char *b)
{
	for (i = 0; a[i] == b[i]; i++)
		if (a[i] == 0) return 0;
	return a[i] - b[i];
}
