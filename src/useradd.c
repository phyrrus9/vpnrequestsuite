#include <stdio.h>
#include <string.h>

int main(int argc, char * * argv)
{
	FILE *f = fopen("/requests/r.txt", "r");
	FILE *g = fopen("/tmp/r.txt", "w");
	FILE *h = fopen("/requests/a.txt", "a+");
	FILE *j = fopen("/etc/ppp/chap-secrets", "a+");
	char lname[32];
	char fname[32];
	char uname[32];
	char passw[32];
	char conta[32];
	char added[64];
	int i;

	for (i = 1; i < argc; i++)
	{
		rewind(f);
		while (fscanf(f, "%s %s %s %s %s %s", lname, fname, uname, passw, conta, added) != EOF)
		{
			if (strcmp(uname, argv[i]) == 0)
			{
				printf("-->Adding user %s (%s %s)\n", uname, fname, lname);
				fprintf(h, "%s\t%s\t%s\t%s\t%s\t%s\n", lname, fname, uname, passw, conta, added);
				fprintf(j, "%s\t*\t%s\t*\n", uname, passw);
			}
			else
			{
				fprintf(g, "%s %s %s %s %s %s\n", lname, fname, uname, passw, conta, added);
			}
		}
	}

	fclose(f);
	fclose(g);
	fclose(h);
	fclose(j);

	int a = rename("/tmp/r.txt", "/requests/r.txt");

	return a;
}
