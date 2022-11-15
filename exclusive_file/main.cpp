#include <iostream>
#include <sys/fcntl.h>
#include <unistd.h>

int main() {
    int logFD = open("./exclusive_file.log", O_WRONLY);

    if(logFD < 0) {
        perror("Chbacvav baxtd");
        return 0;
    }

    char* l1 = "First line\n";
    int res = write(logFD, l1, strlen(l1));

    if(res < 0){
        perror("Chgrvav baxtd");
        return 0;
    }

    int logFDDup = dup(logFD);

    if(logFDDup < 0){
        perror("Chdupvav, bayc baxtd tut neprichom");
        return 0;
    }

    char* l2 = "Second line\n";
    res = write(logFDDup, l2, strlen(l2));

    if(res < 0){
        perror("Sax ereler, write ynchi cherav?");
        return 0;
    }

    close(logFD);
    close(logFDDup);

    return 0;
}
