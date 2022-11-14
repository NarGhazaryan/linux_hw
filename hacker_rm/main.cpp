#include <iostream>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <vector>
#include <unistd.h>

using std::cout;
using std::cin;
using std::perror;
using std::vector;

off_t getFileSize(char *path) {
    struct stat stat_struct;
    if (stat(path, &stat_struct) == 0) {
        return stat_struct.st_size;
    }
    return -1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "\033[31m\n\n\n\n\t\t\t\tArguments shortage! Are you sure, you are a hacker?";
        return 0;
    }

    char *path = argv[1];
    int rFD = open(path, O_WRONLY);

    if (rFD < 0) {
        cout
                << "\033[31m\n\n\n\n\t\t\t\tCouldn't open the file! Open your eyes and check the filename, you have passed!";
        return 0;
    }

    int fileSize = getFileSize(path);
    int chunksCount = fileSize / 2048;
    vector<char> chunk(2048, '\0');
    do {
        cout << "\033[32m" << "\n\n\n\n\t\t\t\t" << "LOADING\n";
        write(rFD, chunk.data(), chunk.size());
        sleep(2);
        system("clear");
        chunksCount--;
    } while (chunksCount > 0);

    cout << "\033[32m" << "\n\n\n\n\t\t\t\t" << "The file was successfully exterminated!"
         << "\n\t\t\t\tNo one will know your secrets now!";
    sleep(2);

    system("clear");

    cout << "\033[32m" << "\n\n\n\n\t\t\t\t" << "Deleting the file, for maximal security...\n";
    sleep(2);

    system("clear");

    close(rFD);

    int unlinkResult = unlink(path);

    if (unlinkResult == -1) {
        cout << "\033[31m\n\n\n\n\t\t\t\tThey are too strong! The file is not deleted, we lose this fight!";
        return 0;
    }

    cout << "\033[33m" << "\n\n\n\n\t\t\t\t You are hero! You just ran this app, and deleted your own file!!!!! LOL";

    return 0;
}
