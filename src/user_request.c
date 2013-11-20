#include <stdio.h>
#include <string.h>

struct u_req
{
	char req[256];
	char uname[32];
	char upass[32];
};

void print_tickets(FILE * f)
{
	struct u_req req;
	int i;

	printf("%-15s %-15s\n", "username", "request");
	for (i = 0; i < 31; i++)
		printf("-");
	printf("\n");
	while (fread(&req, sizeof(struct u_req), 1, f) > 0)
	{
		printf("%-15s %-15s\n", req.uname, req.req);
	}
}

int main(int argc, char * * argv)
{
	FILE *f = fopen("/requests/t.txt", "a+");
	struct u_req req;
	int i;

	if (argc < 3)
	{
		if (argc == 1)
		{
			print_tickets(f);
			return 0;
		}
		printf("Error, you forgot something..\n");
		return -1;
	}

	strcpy(req.uname, argv[1]);
	strcpy(req.upass, argv[2]);
	strcpy(req.req, "");
	for (i = 3; i < argc; i++)
	{
		sprintf(req.req + strlen(req.req), "%s ", argv[i]);
	}

	fwrite(&req, sizeof(struct u_req), 1, f);
	fclose(f);

	printf("Your request was submitted. Feel free to close this window\n");

	return 0;
}
