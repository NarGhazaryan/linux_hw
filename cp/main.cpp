#include <unistd.h>
#include <sys/fcntl.h>
#include <vector>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        perror("Give me my paths, bales");
    }

    char *inputPath = argv[1];
    char *outputPath = argv[2];

    int inputFD = open(inputPath, O_RDONLY);
    int outputFD = open(outputPath, O_WRONLY);

    if (inputFD < 0 || outputFD < 0)
    {
        perror("Something went wrong, try again with normal filerov");
    }

    std::vector<char> buff(1024, '\0');
    while (int rCount = read(inputFD, buff.data(), buff.size()))
    {
        if(!rCount) break;
        write(outputFD, buff.data(), rCount);
    }

    close(inputFD);
    close(outputFD);

    return 0;
}
