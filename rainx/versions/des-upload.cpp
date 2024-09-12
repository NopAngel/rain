/*#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> variables;

void executeLine(const string& line) {
    if (line.find("Console.Write") != string::npos) {
        size_t start = line.find("(") + 1;
        size_t end = line.find(")");
        string message = line.substr(start, end - start);
        cout << message << endl;
    } else if (line.find("Console.Prompt") != string::npos) {
        cout << "> ";
        string input;
        getline(cin, input);
    } else if (line.find("var") != string::npos) {
        size_t start = line.find("var") + 4;
        size_t end = line.find("=");
        string varName = line.substr(start, end - start - 1);
        string varValue = line.substr(end + 2);
        variables[varName] = varValue;
    } else if (line.find("if") != string::npos) {
        // Aquí puedes agregar la lógica para manejar if, else if, y else
    }
}

void interpretFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        executeLine(line);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <archivo.nieto>" << endl;
        return 1;
    }
    interpretFile(argv[1]);
    return 0;
}
*/