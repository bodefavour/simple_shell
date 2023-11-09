#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

void s_h_prompt(void);
void fav_print(const char *sh_in_message);
void read_favour_command(char *sh_in_command, size_t size_s);
void execute_sh_command(const char *sh_in_command);

#endif /* _SHELL_H */