#include <stdio.h>
#include <stdlib.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <unistd.h>
#include "util.h"

#define PREFIX_COUNT 3
#define PREFIX_LENGTH 4
#define OK_ERROR 0 
#define BAD_ARGS_ERROR 1

