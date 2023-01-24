#include <iostream>
#include <fstream>
#include <cstdint>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;


int main(int argc, char** argv) {


    for (int i = 1; i < argc; i++) {
        const fs::path p(argv[i]);

        bool ex = fs::exists(p);

        if (ex) {
            std::cout << "File: \"" << argv[i] << "\" info:" << std::endl;

            std::cout << "    - canonical path: " << fs::canonical(p) << std::endl;

            auto ftime = fs::last_write_time(p);
 
            std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
            std::cout << "    - last mod time: " << std::asctime(std::localtime(&cftime));

            fs::file_status s = fs::status(p);
            if (fs::is_regular_file(s)) {
                std::cout << "    - regular file, size: " << fs::file_size(p) << std::endl;
            } else if (fs::is_directory(s)) {
                std::cout << "    - file is directory" << std::endl;
            }
        } else {
            std::cout << "File: \"" << argv[i] << "\" does not exists." << std::endl;
        }
    }

  	return 0;
}