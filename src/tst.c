#include "so_long.h"
#include <string.h>
#include <unistd.h>

void	prnt(char *str)
{
	write(STDERR_FILENO, str, strlen(str));
}