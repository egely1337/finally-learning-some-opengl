#include <Filesystem.h>

std::string Filesystem::ReadFile(std::string &&Path)
{
    /* Stack */
    std::string output;
    std::string temp;
    std::ifstream stream;

    if(!std::filesystem::exists(Path)) {
        std::cout << "File does not exists: " << Path << std::endl;
        abort();
    }

    stream.open(Path);
    while(std::getline(stream, temp)) {
        output = output + temp + '\n';
    }
    stream.close();

    temp.clear();
    return output;
}

bool Filesystem::IsExists(std::string &&Path)
{
    return std::filesystem::exists(Path);
}
