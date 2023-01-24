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


int main(int argc, char** argv) {


    for (int i = 1; i < argc; i++) {
        const fs::path p(argv[i]);

        bool ex = fs::exists(p);
        fs::file_status s = fs::status(p);

        if (ex) {
            if (fs::is_directory(s)) {
                std::cout << "File: \"" << argv[i] << "\" is directory" << std::endl;
                std::cout << "  - canonical path: " << fs::canonical(p) << std::endl;
                std::cout << "  - content: " << std::endl;

                std::vector<fs::directory_entry> dirs;
                std::vector<fs::directory_entry> files;

                for(const fs::directory_entry& entry : fs::directory_iterator(p)) {
                    fs::file_status entry_status = fs::status(entry);

                    if (fs::is_directory(entry_status)) {
                        dirs.push_back(entry);
                    } else if (fs::is_regular_file(entry_status)) {
                        files.push_back(entry);
                    }
                }
                
                std::sort(dirs.begin(), dirs.end());
                std::sort(files.begin(), files.end());

                print_entries(dirs);
                print_entries(files);
            } else {
                std::cerr << "File: \"" << argv[i] << "\" is not a directory." << std::endl;
            }
        } else {
            std::cerr << "File: \"" << argv[i] << "\" does not exists." << std::endl;
        }
    }

  	return 0;
}