#include <unistd.h>
#include <sys/fcntl.h>
#include <vector>
#include <sys/stat.h>

off_t getFileSize(char *path) {
    struct stat stat_struct;
    if (stat(path, &stat_struct) == 0) {
        return stat_struct.st_size;
    }
    return -1;
}

int main(int argc, char** argv) {
    if(argc < 3) {
        perror("Give me my paths, bales");
        return 0;
    }

    char* inputPath = argv[1];
    char* outputPath = argv[2];

    int inputFD = open(inputPath, O_RDONLY);
    int outputFD = open(outputPath, O_WRONLY);

    if(inputFD < 0 || outputFD < 0) {
        perror("Something went wrong, try again with normal filerov");
        return 0;
    }



    std::vector<char> buff(getFileSize(inputPath), ' ');
    while(read(inputFD, buff.data(), buff.size())){
        write(outputFD, buff.data(), buff.size());
    }

    return 0;
}
