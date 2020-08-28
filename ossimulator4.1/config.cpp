#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void loadFile(std::string path, std::ifstream &config) {
    config.open(path);
}

void closeFile(std::ifstream &stream) {
    stream.close();
}

std::vector<std::string> parseConfig(std::ifstream &config) {
    std::vector<std::string> values;

    if (config.is_open()) {
        std::string line;
        while (getline(config, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            std::stringstream linestream(line);
            while (linestream.good()) {
                std::string substring;
                getline(linestream, substring, ':');
                values.push_back(substring);
            }
        }
    }

    return values;
}

int getVariable(std::string label, std::ifstream &config, std::vector<std::string> &list) {
    auto element = std::find(list.begin(), list.end(), label);
    int variable;
    if (element != list.end()) {
        int index = std::distance(list.begin(), element);
        std::string nextelement = list[index + 1];
        variable = std::stoi(nextelement);
    }

    return variable;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << "args: " << argv[i] << i << " ";
    }
    std::cout << std::endl;

    if (argc > 1) {
        std::ifstream config;
        loadFile(argv[1], config); //path, config stream
        std::vector<std::string> parsedList = parseConfig(config);
        std::cout << "parsed size: " << parsedList.size() << std::endl;
        for (int i = 0; i < parsedList.size(); i++) {
            std::cout << parsedList[i] << std::endl;
        }

        int value = getVariable("value", config, parsedList);
        std::cout << "value: " << value << std::endl;
        int another = getVariable("another", config, parsedList);
        std::cout << "another: " << another << std::endl;

        closeFile(config);
    }
    return 0;
}