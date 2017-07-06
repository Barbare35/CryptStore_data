#include <stdio.h>	//for printf
#include <stdlib.h> //for exit
#include <unistd.h> //for STDERR_FILENO
#include <getopt.h>	//for getopt_long and struct option
#include <errno.h>
#include <string.h>

#include "cryptStore_data.h"

void process(struct valoption val[], char *addfile, char *safe)
{
	(void)val, (void)addfile, (void)safe;
	return ;
}

int usage(char *av, struct option options[])
{
	int i = 0;

	dprintf(STDERR_FILENO, "Usage: %s [", av);
	while (options[i].name != NULL)
	{
		dprintf(STDERR_FILENO, "%s%s", options[i].name, \
				options[i].has_arg == required_argument ? " <file>" : "");
		++i;
		if (options[i].name != NULL)
			dprintf(STDERR_FILENO, "|");
	}
	dprintf(STDERR_FILENO, "] addfile safe\n");
	return (-1);
}

int main(int ac, char **av)
{
	FILE *file;
	int opt;
	struct valoption valopt[] = {
		{'h', false, NULL},
		{'d', false, NULL},
		{'l', false, NULL},
		{'v', false, NULL},
		{'o', false, NULL},
		{0, 0, 0},
	};
	struct option options[] = {
		{"help",		no_argument,       	0, 'h'},
		{"debug",		no_argument,       	0, 'd'},
		{"list-file",	no_argument,		0, 'l'},
		{"verbose",		no_argument,		0, 'v'},
		{"out",			required_argument,	0, 'o'},
		{0, 0, 0, 0}
	};

	if (ac < 3) //minima addfile and safefilename
		return(usage(av[0], options));
	while (1)
	{
		opt = getopt_long(ac, av, "o:d:l:v:c:", options, NULL);
		if (opt == -1)
			break;
		switch (opt)
		{
			case 'd':
				valopt[1].val = true;
				break;
			case 'h':
				return (usage(av[0], options));
			case 'l':
				// TODO Add list-file function
				return (0);
			case 'v':
				valopt[3].val = true;
				break;
			case 'o':
				if ((ac - 2) <= 2)
					return (usage(av[0], options));
				valopt[4].val = true;
				valopt[4].arg = optarg;
				break;
			default:
				return (usage(av[0], options));
		}
	}
	if ((file = fopen(av[ac - 2], "r")) == NULL)
	{
		dprintf(STDERR_FILENO, "%s %s", av[ac - 2], strerror(errno));
		return (-2);
	}
	process(valopt, av[ac - 2], av[ac - 1]);
	return (0);
}
