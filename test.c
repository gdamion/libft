#include "includes/gnl.h"
#include "includes/printf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
/* Not technically required, but needed on some UNIX distributions */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
	char *line;

	int fd = open("../test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	return(0);
}