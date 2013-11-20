#include <stdio.h>
#include <string.h>

typedef char bool;
#define true 1
#define false 0

struct useract
{
	char uname[32];
	char fname[32];
	char lname[32];
	char contact[64];
	bool expired;
};

int finduser(char * uname, int up, struct useract userdb[])
{
	int i;
	for (i = 0; i < up; i++)
	{
		if (strcmp(userdb[i].uname, uname) == 0)
		{
			return i;
		}
	}
}

int main()
{
	FILE *f = fopen("/requests/a.txt", "r");
	FILE *g = fopen("/etc/ppp/chap-secrets", "r");
	struct useract userdb[64];
	int up = 0;
	char tmp[64]; //unused fields
	char uname[32];
	char ip[32];
	int i;

	//populate the array
	while (fscanf(f, "%s %s %s %s %s %s",
		userdb[up].lname, userdb[up].fname, userdb[up].uname, tmp, userdb[up].contact, tmp) != EOF)
	{
		userdb[up].expired = false;
		up++;
	}
	fclose(f);

	while (fscanf(g, "%s\t%s\t%s\t%s", uname, tmp, tmp, ip) != EOF)
	{
		if (strcmp(ip, "0.0.0.0") == 0)
		{
			userdb[finduser(uname, up, userdb)].expired = true;
		}
	}
	fclose(g);


	printf("%-20s %-15s %-15s %-30s %-8s\n", "username", "first name", "last name", "contact", "expired");
	for (i = 0; i < 92; i++) printf("-");
	printf("\n");
	for (i = 0; i < up; i++)
	{
		if (userdb[i].expired)
			strcpy(tmp, "yes");
		else
			strcpy(tmp, "no");
		printf("%-20s %-15s %-15s %-30s %-8s\n", userdb[i].uname, userdb[i].fname, userdb[i].lname, userdb[i].contact, tmp);
	}

}
