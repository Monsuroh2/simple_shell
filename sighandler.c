#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"
#include <string.h>
#include <signal.h>
/**
 * sigHandler - allows for user to user Ctrl C with out exiting the shell.
 * @sig_num: signal number return for activating the action in the function.
 *
 **/

void sigHandler(int sig_num __attribute__((unused)))
{
	signal(SIGINT, sigHandler);
	fflush(stdout);
}
