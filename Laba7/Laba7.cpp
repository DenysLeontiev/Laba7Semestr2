#include <iostream>
#include <fstream>
#include <iterator>
#include <stack>
#include <string>

using namespace std;

// Stack class to store strings and perform basic operations
class StackOfString {
private:
    stack<string> s;
public:
    void push(string str) {
        s.push(str);
    }
    string pop() {
        string str = s.top();
        s.pop();
        return str;
    }
    bool isEmpty() {
        return s.empty();
    }
    void reverse() {
        stack<string> temp;
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        s = temp;
    }
};

// Class to read and write strings to files using iterators
class FileIO {
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

        while (!lines.isEmpty()) {
            string line = lines.pop();
            *outputIt++ = line;
        }

        outputFile.close();
    }
};


int main() {
    /*StackOfString s;
    s.push("hello");
    s.push("world");
    s.push("!");
    s.reverse();

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;*/

    FileIO f;
    f.readAndWriteToFile("firstFile.txt", "output.txt");


    return 0;
}
