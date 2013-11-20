#include <stdio.h>
#include <string.h>

int main(int argc, char * * argv)
{
	FILE *f = fopen("/etc/ppp/chap-secrets", "r");
	FILE *g = fopen("/tmp/chap-secrets", "w");
	char uname[32];
	char ast[32];
	char passw[32];
	char ip[32];
	int i;

	for (i = 1; i < argc; i++)
	{
		rewind(f);
		while (fscanf(f, "%s\t%s\t%s\t%s", uname, ast, passw, ip) != EOF)
		{
			if (strcmp(uname, argv[i]) == 0)
			{
				printf("-->unexpiring %s\n", uname);
				fprintf(g, "%s\t*\t%s\t*\n", uname, passw);
			}
			else
			{
				fprintf(g, "%s\t*\t%s\t%s\n", uname, passw, ip);
			}
		}
	}

	fclose(f);
	fclose(g);

	int a = rename("/tmp/chap-secrets", "/etc/ppp/chap-secrets");

	return a;
}
