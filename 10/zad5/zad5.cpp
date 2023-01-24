#include <iostream>
#include <fstream>
#include <cstdint>
#include <experimental/filesystem>
#include <vector>
#include <bits/stdc++.h>

namespace fs = std::experimental::filesystem;

void print_entries(std::vector<fs::directory_entry> v) {
    for(auto e : v) {
        std::cout << "    * " << e << std::endl;
    }
}


int main() {
    std::string name = "";
    getline(std::cin, name);

    const fs::path p(name);

    bool ex = fs::exists(p);
    fs::file_status s = fs::status(p);

    if (ex) {
        if (fs::is_directory(s)) {
            std::cout << "File: \"" << name << "\" is directory" << std::endl;
            std::cout << "  - canonical path: " << fs::canonical(p) << std::endl;

            auto size = 0;

            for (const fs::directory_entry& entry : fs::recursive_directory_iterator(p)) {
                if (fs::is_regular_file(fs::status(entry))) {
                    size += fs::file_size(entry);
                }
            }

            std::cout << "  - size of files: " << size << std::endl;
        } else {
            std::cerr << "File: \"" << name << "\" is not a directory." << std::endl;
        }
    } else {
        std::cerr << "File: \"" << name << "\" does not exists." << std::endl;
    }

  	return 0;
}