#include "commands.h"
#include <ctype.h>

bool parse_command(char *command)
{
	char *name = strtok(command, " ");
	if (!strcmp(name, "CREATE")) {

	} else if (!strcmp(name, "PUT")) {

	} else if (!strcmp(name, "DELETE")) {

	} else {
		return false;
	}
}

static void trim(char *string)
{

}

static bool check_name(const char* name)
{
	for (;*name != 0; name++)
		if (*name != '_' || !isalnum(*name))
			return false;
	return true;
}
