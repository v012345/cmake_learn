#include <iostream>
#include <sub.h>
int main(int argc, char const *argv[])
{

#if defined(_WIN64) || defined(_WIN32) || defined(__CYGWIN__)
    system("chcp 65001");
#endif

    if (!system(".\\GetAllFilesInProject.exe"))
    {

        std::cout << "完成" << std::endl;
    }
    else
    {
        exit(1);
    }
    if (!system(".\\CompressLogFile.exe"))
    {

        std::cout << "完成" << std::endl;
    }
    else
    {
        exit(1);
    }
    if (!system(".\\GenUsingImages.exe"))
    {

        std::cout << "完成" << std::endl;
    }
    else
    {
        exit(1);
    }
    if (!system(".\\FilterUnusedImages.exe"))
    {

        std::cout << "完成" << std::endl;
    }
    else
    {
        exit(1);
    }

    system("git add ..\\config");
    system("git commit -m save_config");

    std::cout << "完成" << std::endl;
    std::cout << "请手动点击 ReplaceAnimation.exe" << std::endl;
    system("pause");
    return 0;
}
