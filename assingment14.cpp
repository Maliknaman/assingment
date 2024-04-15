#include <iostream>
#include <string>
class StringProcessor {
private:
    std::string* strPtr;
public:
    StringProcessor(const std::string& str) {
        strPtr = new std::string(str);
    }
    ~StringProcessor() {
        delete strPtr;
    }
    int calculateTotalWords() const {
        int totalWords = 0;
        bool inWord = false;
        for (char c : *strPtr) {
            if (std::isspace(c)) {
                inWord = false;
            } else if (!inWord) {
                totalWords++;
                inWord = true;
            }
        }
        return totalWords;
    }
};
int main() {
    StringProcessor processor("Hello, this is a test string.");
    std::cout << "Total words in the string: " << processor.calculateTotalWords() << std::endl;
    return 0;
}
