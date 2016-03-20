#include "util.h"

char *valid_prefixes[PREFIX_COUNT] = {"cmd:", "umt:","del:"};


bool isMAC(char *s) {
    int i = 0;
    for(i = 0; i < 17; i++) {
        if(i % 3 != 2 && !isxdigit(s[i]))
            return false;
        if(i % 3 == 2 && s[i] != ':')
            return false;
    }
    if(s[17] != '\0')
        return false;
    return true;
}


bool valid_arg_command(char* strn) {
        int i = 0;
        if (strnlen(strn,4) < 4)
                return false;
        for(i = 0;i < PREFIX_COUNT;i++) {
                if(0 == strncmp(strn,valid_prefixes[i], PREFIX_LENGTH))
                        return true;
        }
        return false;
}


