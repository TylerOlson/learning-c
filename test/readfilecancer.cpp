#include <fstream>
#include <iostream>

void readFile() {
    std::ifstream file("filename.txt");

    std::string word = "";
    std::string words[1] = {};

    int count = 0;

    while (getline(file, word)) {
        words[count] = word;
        std::string newWords[sizeof(words)] = {};
        for (int i = 0; i < sizeof(words); i++) {
            std::string newWords[i] = words[i];
        }
        words = newWords;
        count++;
    }

    file.close();
}