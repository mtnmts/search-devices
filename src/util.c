#include "util.h"
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
