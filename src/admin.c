#include <stdio.h>

int main(int argc, char * * argv)
{
	FILE *f = fopen("/requests/admin.txt", "r");
	char uname[32];
	char passw[32];
	if (argc < 3 || f == NULL)
	{
		printf("Uh oh...\n");
		return -1;
	}

	while (fscanf(f, "%s %s", uname, passw) != EOF)
	{
		if (strcmp(uname, argv[1]) == 0)
		{
			if (strcmp(passw, argv[2]) == 0)
			{
				return 1;
			}
		}
	}

	fclose(f);

	return 0;
}
