#include "../inc/libmx.h"

static bool isupper(int c) {
    if (c >= 65 && c <= 90) {
        return true;
    }
    else {
        return false;
    }
}

static bool islower(int c) {
    if (c >= 97 && c <= 122) {
        return true;
    }
    else {
        return false;
    }
}

static bool isdigit(int c) {
    if (c >= 48 && c <= 57) {
        return true;
    }
    else {
        return false;
    }
}

static bool isalpha(int c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return true;
    }
    else {
        return false;
    }
}
 
unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long decimal = 0;
    int val = 0;
    
    for (int i = 0; hex[i] != '\0'; i++) {
        if (isdigit(hex[i]))
            val = hex[i] - 48;
        else if (isalpha(hex[i])) {
            if (isupper(hex[i]))
                val = hex[i] - 65 + 10;
            if (islower(hex[i]))
                val = hex[i] - 97 + 10;
        }
        decimal = val + decimal * 16;
    }
    return decimal;
}

