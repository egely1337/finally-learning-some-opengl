#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <ostream>

#include <Definitions.h>

class Filesystem {
public:
    static std::string ReadFile(std::string&& Path);
    static bool IsExists(std::string&& Path);
protected:
};

#endif