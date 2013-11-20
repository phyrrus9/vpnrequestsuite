#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("/requests/r.txt", "r");
	char lname[32];
	char fname[32];
	char uname[32];
	char passw[32];
	char conta[32];
	char added[64];
	int count = 0;

	printf( "<pre>"
		"-----------Active Queue-----------\n"
		"-These are accounts not yet added-\n"
		"----------------------------------\n"
		);
	while (fscanf(f, "%s %s %s %s %s %s", lname, fname, uname, passw, conta, added) != EOF)
	{
		printf("First Name: %-20s Username: %-20s Added on: %-30s\n", fname, uname, added);
		count++;
	}

	if (count < 1)
		printf("No users in the queue\n");

	fclose(f);

	return 0;
}
