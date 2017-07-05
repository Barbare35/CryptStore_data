#include <stdio.h>	//for printf
#include <stdlib.h> //for exit
#include <unistd.h> //for STDERR_FILENO
#include <getopt.h>	//for getopt_long and struct option
#include <errno.h>
#include <string.h>

int usage(char *av, struct option options[])
{
	int i = 0;

	dprintf(STDERR_FILENO, "Usage: %s [", av);
	while (options[i].name != NULL)
	{
		dprintf(STDERR_FILENO, "%s", options[i++].name);
		if (options[i].name != NULL)
			dprintf(STDERR_FILENO, "|");
	}
	dprintf(STDERR_FILENO, "] addfile safe");
	return (-1);
}

int main(int ac, char **av)
{
	FILE *safe; //safe that contain all file
	FILE *file;
	int opt;
	struct option options[] = {
		{"debug",		no_argument,       	0, 'd'},
		{"list-file",	no_argument,		0, 'l'},
		{"verbose",		no_argument,		0, 'v'},
		{"out",			required_argument,	0, 'o'},
		{0, 0, 0, 0}
	};

	if (ac < 2)
		return(usage(av[0], options));
	if ((file = fopen(av[ac - 2], "r")) < 0)
	{
		dprintf(STDERR_FILENO, "addfile %s", strerror(errno));
		return (-1);
	}
	else if ((safe = fopen(av[ac - 1], "rw")) < 0)
	{
		dprintf(STDERR_FILENO, "safe %s", strerror(errno));
		return (-2);
	}
	else if ((opt = getopt_long(ac, av, "o:d:l:v:c:", options, NULL)) < 0)
	{
		dprintf(STDERR_FILENO, "options %s", strerror(errno));
		return (-3);
	}
	return (0);
}
