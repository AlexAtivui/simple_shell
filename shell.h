#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#include "alx.h" /* macros */
/**
 * struct program_data - struct for the program's data
 * @name: executable name
 * @input: pointer to the input read for get_line
 * @cmd: pointer to the command
 * @exe: number of executed commands
 * @fd: file descriptor
 * @tokens: pointer to input tokenization
 * @env: environment copy
 * @alias_list: array of pointers with aliases.
 */
typedef struct program_data
{
	char *name;
	char *input;
	char *cmd;
	int exe;
	int fd;
	char **tokens;
	char **env;
	char **alias_list;
} program_data;

/**
 * struct inbuilt - struct for the inbuilt
 * @inbuilt: the inbuilt name
 * @function: function to be called for each inbuilt
 */
typedef struct inbuilt
{
	char *inbuilt;
	int (*function)(program_data *data);
} inbuilt;

void initialize_environment(program_data *data, char **env);
void initialize_alias_list(program_data *data);
void initialize_data(program_data *data, char *argv[], int argc);
void benedict(char *prompt, program_data *data);
void ctrl_c(int opr UNUSED);
int get_line(program_data *data);
int chc_op(char *array_cmd[], int i, char array_optr[]);
void icr_var(program_data *data);
void icr_alias(program_data *data);
int buffer_sum(char *buffer, char *str_to_add);
void tok(program_data *data);
char *str_tok(char *line, char *del);
int exc(program_data *data);
void increase_pid_var(char *line, program_data *data);
void increase_errno_var(char *line, program_data *data);

int inbuilt_l(program_data *data);
char **tok_path(program_data *data);
int f_p(program_data *data);
int file_checker(char *whole_path);

void free_ar_pt(char **dir);
void free_rec(program_data *data);
void free_dt(program_data *data);

int e_xit(program_data *data);
int _cd(program_data *data);
int pwd(program_data *data, char *new_dir);
int _help(program_data *data);
int _alias(program_data *data);

int _env(program_data *data);
int set_env(program_data *data);
int unset_env(program_data *data);

char *env_key(char *name, program_data *data);
int env_set(char *key, char *value, program_data *data);
int env_rm(char *key, program_data *data);
void _environmt(program_data *data);

int print_f(char *string);
int print(char *string);
int print_err(int err, program_data *data);

int str_l(char *string);
char *str_d(char *string);
int str_c(char *string1, char *string2, int number);
char *str_ccat(char *string1, char *string2);
void str_rev(char *string);

void l_str(long cocte, char *string, int base);
int a_toi(char *s);
int c_xtr(char *string, char *xtr);

int p_alias(program_data *data, char *alias);
char *g_alias(program_data *data, char *alias);
int s_alias(char *alias_string, program_data *data);

#endif /* SHELL_H */
