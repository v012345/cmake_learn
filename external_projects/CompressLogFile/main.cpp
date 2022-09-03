#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <set>
#include <regex>
std::set<std::string> files;

void getFilesInDir(std::filesystem::path path)
{
    std::ifstream LogFile;
    for (auto &v : std::filesystem::directory_iterator(path))
    {
        //

        if (v.is_directory())
        {
            std::string fileName = v.path().filename().string();

            if (fileName == "log")
            {
                for (auto &log : std::filesystem::directory_iterator(v))
                {
                    if (log.is_regular_file() && log.path().extension().string() == ".txt")
                    {
                        // std::cout << log.path() << std::endl;
                        LogFile.open(log.path());
                        std::string line;
                        // std::smatch matches;
                        // std::regex rgx("/([a-zA-Z0-9_\\.]+\\.(?:png|jpg)).*");
                        // std::regex json("/([a-zA-Z0-9_\\.]+\\.(?:json))$");
                        // std::regex replaceJson("(.*)json$");
                        if (LogFile.is_open())
                        {
                            while (getline(LogFile, line))
                            {
                                files.insert(line);

                                //     if (std::regex_search(line, matches, json))
                                // {
                                //     line = regex_replace(line, replaceJson, "$1png");
                                // }

                                // if (std::regex_search(line, matches, rgx))
                                // {
                                //     for (size_t i = 1; i < matches.size(); ++i)
                                //     {
                                //         // std::cout << matches[i].str() << std::endl;
                                //         files.insert(matches[i].str());
                                //     }
                                // }
                            }
                            LogFile.close();
                        }
                    }
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    getFilesInDir(std::filesystem::current_path());
    std::ofstream myfile;
    myfile.open("CompressedLogFile.txt", std::ios::out);
    for (auto &file : files)
    {
        myfile << file << std::endl;
    }
    myfile.close();
    return 0;
}
