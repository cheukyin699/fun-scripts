#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>

const std::array<std::string, 6> faces{
    {"(・`ω´・)",
        ";;w;;",
        "owo",
        "UwU",
        ">w<",
        "^w^"}
};

const std::regex smallR("(?:r|l)");
const std::regex bigR("(?:R|L)");
const std::regex ny("(n|N)([aeiou]|[AEIOU])");
const std::regex ove("ove");
const std::regex punctuations("\\!+");

std::string randomFace() {
    return faces[rand() % faces.size()];
}

std::string process(std::string line) {
    auto tmp0 = std::regex_replace(line, smallR, "w");
    auto tmp1 = std::regex_replace(tmp0, bigR, "W");
    auto tmp2 = std::regex_replace(tmp1, ny, "\1y\2");
    auto tmp3 = std::regex_replace(tmp2, ove, "uv");
    return std::regex_replace(tmp3, punctuations, randomFace());
}

int main() {
    for (std::string line; std::getline(std::cin, line);) {
        std::cout << process(line);
    }
    return 0;
}
