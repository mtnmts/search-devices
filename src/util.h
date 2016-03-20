#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAC_ADDR_LEN 17
#define PREFIX_COUNT 3 
#define PREFIX_LENGTH 4 


bool isMAC(char *s);
bool valid_arg_command(char* strn);
