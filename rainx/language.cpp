/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> variables;

void executeLine(const string &line);

bool evaluateCondition(const string &condition)
{
    // Aquí puedes agregar la lógica para evaluar condiciones
    // Por simplicidad, asumimos que las condiciones son variables booleanas
    return variables[condition] == "true";
}

void executeBlock(istringstream &stream)
{
    string line;
    while (getline(stream, line))
    {
        if (line.find("}") != string::npos)
            break;
        executeLine(line);
    }
}

void executeLine(const string &line)
{
    try
    {
        if (line.find("Console.Write") != string::npos)
        {
            size_t start = line.find("('") + 1;
            size_t end = line.find("')");
            string message = line.substr(start, end - start);
            cout << message << endl;
        }
        else if (line.find("Console.Prompt") != string::npos)
        {
             //cout << "> ";

             //string input;
             //getline(cin, input);

            size_t start = line.find("('") + 1;
            size_t end = line.find("')");
            string message = line.substr(start, end - start);
            cin >> message;
        }
        else if (line.find("var") != string::npos)
        {
            size_t start = line.find("var") + 4;
            size_t end = line.find("=");
            string varName = line.substr(start, end - start - 1);
            string varValue = line.substr(end + 2);
            variables[varName] = varValue;
        }
        else if (line.find("if") != string::npos)
        {
            size_t start = line.find("(") + 1;
            size_t end = line.find(")");
            string condition = line.substr(start, end - start);
            if (evaluateCondition(condition))
            {
                istringstream stream(line.substr(end + 2));
                executeBlock(stream);
            }
        }
        else if (line.find("else if") != string::npos)
        {
            size_t start = line.find("(") + 1;
            size_t end = line.find(")");
            string condition = line.substr(start, end - start);
            if (evaluateCondition(condition))
            {
                istringstream stream(line.substr(end + 2));
                executeBlock(stream);
            }
        }
        else if (line.find("else") != string::npos)
        {
            istringstream stream(line.substr(line.find("{") + 1));
            executeBlock(stream);
        }
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void interpretFile(const string &filename)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        executeLine(line);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Uso: " << argv[0] << " <archivo.nieto>" << endl;
        return 1;
    }
    interpretFile(argv[1]);
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>

std::map<std::string, std::string> variables;

void print(const std::string &text)
{
    std::cout << text << std::endl;
}

std::string prompt(const std::string &text)
{
    std::string input;
    std::cout << text;
    std::getline(std::cin, input);
    return input;
}

void execute_line(const std::string &line)
{
    // Aquí iría la lógica para interpretar y ejecutar cada línea del archivo .nieto
    // Por simplicidad, solo manejamos print y asignaciones básicas
    if (line.find("print(") == 0)
    {
        std::string to_print = line.substr(6, line.size() - 7);
        print(to_print);
    }
    else if (line.find("=") != std::string::npos)
    {
        size_t pos = line.find("=");
        std::string var_name = line.substr(0, pos);
        std::string var_value = line.substr(pos + 1);
        variables[var_name] = var_value;
    }
}

/*

void run_script(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("No se pudo abrir el archivo.");
    }

    std::string line;
    while (std::getline(file, line))
    {
        execute_line(line);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <archivo.nieto>" << std::endl;
        return 1;
    }

    try
    {
        run_script(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
*/
/*
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>

std::map<std::string, std::string> variables;

void print(const std::string &text)
{
    std::cout << text << std::endl;
}

std::string prompt(const std::string &text)
{
    std::string input;
    std::cout << text;
    std::getline(std::cin, input);
    return input;
}

void execute_line(const std::string &line)
{
    if (line.find("print(") == 0)
    {
        std::string to_print = line.substr(6, line.size() - 7);
        print(to_print);
    }
    else if (line.find("=") != std::string::npos)
    {
        size_t pos = line.find("=");
        std::string var_name = line.substr(0, pos);
        std::string var_value = line.substr(pos + 1);
        variables[var_name] = var_value;
    }
}

void run_script(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("No se pudo abrir el archivo.");
    }

    std::string line;
    while (std::getline(file, line))
    {
        execute_line(line);
    }
}

bool has_correct_extension(const std::string &filename)
{
    return filename.size() >= 6 && filename.substr(filename.size() - 6) == ".nieto";
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <archivo.nieto>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    if (!has_correct_extension(filename))
    {
        std::cerr << "Error: El archivo debe tener la extensión .nieto" << std::endl;
        return 1;
    }

    try
    {
        run_script(filename);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>

std::map<std::string, std::string> variables;

void print(const std::string &text)
{
    std::cout << text << std::endl;
}

std::string prompt(const std::string &text)
{
    std::string input;
    std::cout << text;
    std::getline(std::cin, input);
    return input;
}

std::string replace_variables(const std::string &text)
{
    std::string result = text;
    for (const auto &var : variables)
    {
        size_t pos;
        while ((pos = result.find(var.first)) != std::string::npos)
        {
            result.replace(pos, var.first.length(), var.second);
        }
    }
    return result;
}

void execute_line(const std::string &line)
{
    if (line.find("print(") == 0)
    {
        std::string to_print = line.substr(6, line.size() - 7);
        to_print = replace_variables(to_print);
        print(to_print);
    }
    else if (line.find("=") != std::string::npos)
    {
        size_t pos = line.find("=");
        std::string var_name = line.substr(0, pos);
        std::string var_value = line.substr(pos + 1);
        variables[var_name] = var_value;
    }
}

void run_script(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("No se pudo abrir el archivo.");
    }

    std::string line;
    while (std::getline(file, line))
    {
        execute_line(line);
    }
}

bool has_correct_extension(const std::string &filename)
{
    return filename.size() >= 6 && filename.substr(filename.size() - 6) == ".nieto";
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <archivo.nieto>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    if (!has_correct_extension(filename))
    {
        std::cerr << "Error: El archivo debe tener la extensión .nieto" << std::endl;
        return 1;
    }

    try
    {
        run_script(filename);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
