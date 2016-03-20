#ifndef __BONDSAFE_H__
#define __BONDSAFE_H__

#include <stdio.h>
#include <stdlib.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <unistd.h>
#include "util.h"

#define OK_ERROR 0 
#define BAD_ARGS_ERROR 1



// Returns the default device for now
int get_device();

// checks the arguments we get from the user
bool validate_args(int argc, char** argv);


int main(int argc, char** argv);

#endif
