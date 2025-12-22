#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./econ <number | numberpy>\n";
        return 1;
    }

    std::string arg = argv[1];

    // Python-Fall: endet auf "py"
    if (arg.size() > 2 && arg.substr(arg.size() - 2) == "py") {
        std::string num = arg.substr(0, arg.size() - 2);
        std::string cmd = "python3 econ" + num + ".py";
        return system(cmd.c_str());
    }

    // C++-Binary-Fall
    std::string cmd = "./econ" + arg;
    return system(cmd.c_str());
}
