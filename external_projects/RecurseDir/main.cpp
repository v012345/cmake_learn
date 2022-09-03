#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <set>
namespace fs = std::filesystem;

std::set<std::string> files;
std::set<std::string> ext;

void getFilesInDir(fs::path path)
{
    for (auto &v : fs::directory_iterator(path))
    {
        //
        if (v.is_directory())
        {
            getFilesInDir(v);
            /* code */
        }
        else
        {
            // ext.insert(v.path().extension().string());
            // if (v.path().extension().string() == ".json" || v.path().extension().string() == ".png")
            if (v.path().extension().string() == ".png" or v.path().extension().string() == ".jpg")
            {

                std::string fileName = v.path().filename().string();
                std::cout << fileName << std::endl;
                files.insert(fileName);
                // std::string extensionName = v.path().extension().string();
                // std::cout << "extensionName= " << extensionName << std::endl;
            }
        }
    }
}

int main()
{
    getFilesInDir(fs::current_path());
    std::ofstream myfile;
    myfile.open("allFiles.txt", std::ios::out);
    for (auto &file : files)
    {
        myfile << file << std::endl;
    }
    // for (auto &e : ext)
    // {
    //     myfile << e << std::endl;
    // }
    myfile.close();
    return 0;
    // fs::path path_1(fs::current_path());
    // if (fs::is_directory(path_1))
    // {
    //     for (const auto &a : path_1)
    //     {
    //         std::cout << a << std::endl;
    //     };
    // }
    // std::cout << "Current path is " << fs::current_path() << '\n'; // (1)
    // fs::current_path(fs::temp_directory_path());                   // (3)
    // std::cout << "Current path is " << fs::current_path() << '\n';
    // std::cout << "Current path is " << fs::is_regular_file(fs::current_path()) << '\n';
    // std::cout << "Current path is " << fs::is_directory(fs::current_path()) << '\n';

    // // Path 的属性
    // std::cout << path_1.filename() << std::endl; // 包含后缀, CMakeLists.txt
    // std::cout << path_1.root_directory() << std::endl;
    // std::cout << path_1.parent_path() << std::endl;
    // std::cout << path_1.extension() << std::endl;
    // std::cout << path_1.is_absolute() << std::endl;
    // std::cout << path_1.is_relative() << std::endl;
    // std::cout << path_1.stem() << std::endl; // 不包含后缀的文件名, CMakeLists
    // fs::create_directories("sandbox/a/b");
    // std::ofstream("sandbox/file1.txt");
    // fs::create_symlink("a", "sandbox/syma");

    // // Iterate over the `std::filesystem::directory_entry` elements explicitly
    // for (const fs::directory_entry &dir_entry :
    //      fs::recursive_directory_iterator("sandbox"))
    // {
    //     std::cout << dir_entry << '\n';
    // }
    // std::cout << "-----------------------------\n";
    // // Iterate over the `std::filesystem::directory_entry` elements using `auto`
    // for (auto const &dir_entry : fs::recursive_directory_iterator("sandbox"))
    // {
    //     std::cout << dir_entry << '\n';
    // }

    // fs::remove_all("sandbox");
}