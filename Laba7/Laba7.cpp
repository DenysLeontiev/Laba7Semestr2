#include <iostream>
#include <fstream>
#include <iterator>
#include <stack>
#include <string>

using namespace std;

class AbstractFileIO {
public:
    virtual void readAndWriteToFile(string inputFileName, string outputFileName) = 0;
};

// Stack class to store strings and perform basic operations
class StackOfString : public stack<string> {
public:
    void reverse() {
        stack<string> temp;
        while (!this->empty()) {
            temp.push(this->top());
            this->pop();
        }
        stack<string>::operator=(temp);
    }
};

// Class to read and write strings to files using iterators
class FileIO : AbstractFileIO {
public:
    void readAndWriteToFile(string inputFileName, string outputFileName) {
        ifstream inputFile(inputFileName);
        if (!inputFile) {
            cout << "Error opening input file.\n";
            return;
        }

        istream_iterator<string> inputIt(inputFile), inputEnd;
        StackOfString lines;

        int lineNum = 1;
        for (; inputIt != inputEnd; ++inputIt) {
            string new_str = to_string(lineNum++) + ": " + *inputIt;
            lines.push(new_str);
            cout << new_str << endl;  // Write to console
        }

        inputFile.close();

        ofstream outputFile(outputFileName);
        ostream_iterator<string> outputIt(outputFile, "\n");

        lines.reverse();

        while (!lines.empty()) {
            string line = lines.top();
            *outputIt++ = line;
            lines.pop();
        }

        outputFile.close();
    }
};


int main() {
    FileIO f;
    f.readAndWriteToFile("firstFile.txt", "output.txt");

    return 0;
}
