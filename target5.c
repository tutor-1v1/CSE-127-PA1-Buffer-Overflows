https://tutorcs.com
WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
// Compiled with DEP enabled.
// It's OK if your program crashes after the user exits the shell.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void greetings(void)
{
	system("echo Hello World");
}

void vulnerable(char *arg)
{
	char buf[10];
	strcpy(buf, arg);
}

int _main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Error: Need a command-line argument\n");
		return 1;
	}
	setuid(0);
	vulnerable(argv[1]);
	greetings();
	return 0;
}
