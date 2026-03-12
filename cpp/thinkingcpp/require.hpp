#ifndef CPP_THINKINGCPP_REQUIRE_HPP_
#define CPP_THINKINGCPP_REQUIRE_HPP_
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>

inline void require(bool requirements,
    const std::string& msg = "Requirement failed") {
    if (!requirements) {
        std::fputs(msg.c_str(), stderr);
        std::fputs("\n", stderr);
        std::exit(1);
    }
}

inline void requireMinArgs(int argc, int minArgs,
    const std::string& msg = "Must use at least %d arguments") {
    using namespace std;
    if (argc < minArgs + 1) {
        fprintf(stderr, msg.c_str(), minArgs);
        fputs()
    }
}

#endif
