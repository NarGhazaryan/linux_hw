#include <iostream>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <vector>
#include <unistd.h>

off_t getFileSize(char *path)
{
    struct stat stat_struct;
    if (stat(path, &stat_struct) == 0)
    {
        return stat_struct.st_size;
    }
    return -1;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        perror("Arguments shortage! Are you sure, you are a hacker?");
    }

    char *path = argv[1];
    int rFD = open(path, O_WRONLY);

    if (rFD < 0)
    {
        perror("Couldn't open the file! Open your eyes and check the filename, you have passed!");
    }

    int fileSize = getFileSize(path);
    int chunksCount = fileSize / 2048;
    std::vector<char> chunk(2048, '\0');
    do
    {
        write(rFD, chunk.data(), chunk.size());
        chunksCount--;
    } while (chunksCount > 0);

    std::cout << "\033[32m"
              << "\n\n\n\n\t\t\t\t"
              << "The file was successfully exterminated!"
              << "\n\t\t\t\tNo one will know your secrets now!";

    std::cout << "\033[32m"
              << "\n\n\n\n\t\t\t\t"
              << "Deleting the file, for maximal security...\n";

    close(rFD);

    int unlinkResult = unlink(path);

    if (unlinkResult == -1)
    {
        perror("They are too strong! The file is not deleted, we lose this fight!");
    }

    std::cout << "\033[33m"
              << "\n\n\n\n\t\t\t\t You are a hero! You just ran this app, and deleted your own file!!!!! LOL";

    return 0;
}
