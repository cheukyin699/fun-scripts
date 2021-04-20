#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>

const std::array<std::string, 6> faces{
    {" (・`ω´・) $1",
        " ;;w;; $1",
        " owo $1",
        " UwU $1",
        " >w< $1",
        " ^w^ $1"}
};

const std::regex smallR("(?:r|l)");
const std::regex bigR("(?:R|L)");
const std::regex ny("(n|N)([aeiouAEIOU])");
const std::regex ove("[oO][vV][eE]");
const std::regex punctuations("([\\!.;?]+)");

std::string randomFace() {
    return faces[rand() % faces.size()];
}

std::string process(std::string line) {
    auto tmp0 = std::regex_replace(line, smallR, "w");
    auto tmp1 = std::regex_replace(tmp0, bigR, "W");
    auto tmp2 = std::regex_replace(tmp1, ny, "$1y$2");
    auto tmp3 = std::regex_replace(tmp2, ove, "uv");
    return std::regex_replace(tmp3, punctuations, randomFace());
}

int main() {
    for (std::string line; std::getline(std::cin, line);) {
        std::cout << process(line);
    }
    return 0;
}
