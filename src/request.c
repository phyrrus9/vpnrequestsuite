#include <stdio.h>
#include <string.h>

typedef char bool;
#define true 1
#define false 0

int main(int argc, char * * argv)
{
	FILE *f = fopen("/requests/r.txt", "a+");
	FILE *g = fopen("/requests/a.txt", "r" );
	char lname[32];
	char fname[32];
	char uname[32];
	char passw[32];
	char conta[32];
	char added[64];

	char lname2[32];
	char fname2[32];
	char uname2[32];
	char passw2[32];
	char conta2[32];
	char added2[64];

	bool inuse = false;
	bool inque = false;
	int i;

	strcpy(lname, argv[1]);
	strcpy(fname, argv[2]);
	strcpy(uname, argv[3]);
	strcpy(passw, argv[4]);
	strcpy(conta, argv[5]);
	strcpy(added, argv[6]);

	//check to see if it isnt accepted or in use
	while (fscanf(g, "%s\t%s\t%s\t%s\t%s\t%s", lname2, fname2, uname2, passw2, conta2, added2) != EOF)
	{
		if (strcmp(lname, lname2) == 0)
		{
			if (strcmp(fname, fname2) == 0)
			{
				inuse = true;
			}
		}
		if (strcmp(uname, uname2) == 0) inuse = true;
		if (strcmp(conta, conta2) == 0) inuse = true;
	}

	//check the queue
	while (fscanf(f, "%s %s %s %s %s %s", lname2, fname2, uname2, passw2, conta2, added2) != EOF)
	{
		if (strcmp(lname, lname2) == 0)
		{
			if (strcmp(fname, fname2) == 0)
			{
				inque = true;
			}
		}
		if (strcmp(uname, uname2) == 0) inque = true;
		if (strcmp(conta, conta2) == 0) inque = true;
	}

	if (inuse)
	{
		printf("Sorry, that series of credentials are already in use.<br />Possible multiple accounts<br />:(<br />");
		return 1;
	}
	if (inque)
	{
		printf("Sorry, that series of credentials is already in the queue.<br />Possible causes are:<br />"
			"1. You have not paid<br />"
			"2. You gave in incorrect contact field<br />"
			"3. Something went wrong with formatting (contact your seller)<br />"
			"4. You havn't waited long enough<br />:(");
		return 2;
	}

	fprintf(f, "%s %s %s %s %s %s\n", lname, fname, uname, passw, conta, added);

	printf("Congratulations! You were added to the queue!<br />"
		"Now, take the following steps:<br />"
		"1. Pay (see footnote)*<br />"
		"2. If paid in cash, you should recieve an email very soon<br />"
		"3. Wait for an email/text message (whatever was in the contact field<br /><br />"
		"*PAYMENT: There are multiple forms of payment, here are two suggested ways<br />"
		" 1. Cash (probably best). The rate is $5 per month of use. <sub>We will not disable it right away, but eventually we will</sub><br />"
		" 2. Paypal (works). Send $5 to Jerrick.davis.97@gmail.com as long as you put down the same email as your paypal uses. NO EXCEPTIONS<br />"
		);

	fclose(f);

	return 0;
}
