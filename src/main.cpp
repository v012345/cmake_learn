#include <iostream>
#include <sub.h>
int main(int argc, char const *argv[])
{

    // std::cout << system("cd .\\bin") << std::endl;
    std::cout << system(".\\GetAllFilesInProject.exe") << std::endl;
    std::cout << system(".\\CompressLogFile.exe") << std::endl;
    return 0;
}
