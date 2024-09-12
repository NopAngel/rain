#include <iostream>
#include <fstream>
#include <string>

void setColor(int textColor)
{
    std::cout << "\033[" << textColor << "m";
}

void resetColor()
{
    std::cout << "\033[0m";
}

void readFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (file)
    {
        std::string line;
        std::cout << "File content:\n";
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "File '" << filePath << "' does not exist." << std::endl;
    }
}

void writeFile(const std::string &filePath)
{
    std::ofstream file(filePath, std::ios::app);
    if (file)
    {
        std::string input;
        std::cout << "Enter text to write to the file (type 'exit' to stop):\n";
        while (true)
        {
            std::getline(std::cin, input);
            if (input == "exit")
            {
                std::cout << "\n\nGoodbye :D!";
                break;
            }
            file << input << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file '" << filePath << "' for writing." << std::endl;
    }
}

int main()
{
    std::string res;

    do
    {
        setColor(31);
        std::cout << "===================================================================\n";
        resetColor();
        std::cout << "                             Rain Editor                          \n";
        std::cout << "\n\n";
        std::cout << "                 !code - You could write code.                    \n";
        std::cout << "          :github - You can see our GitHub repository             \n";
        std::cout << "          rainn:@v - Show the Rain CLI version (Coming soon)      \n";
        setColor(31);
        std::cout << "===================================================================\n";
        resetColor();
        std::cin >> res;
        if (res == ":github")
        {
            std::cout << "https://github.com/NopAngel/rain - Follow me and give it a Star :D!\n\n";
        }

    } while (res != "!code");

    if (res == "!code")
    {
        std::string filePath;
        std::cout << "Enter the file path: ";
        std::cin >> filePath;

        readFile(filePath);
        writeFile(filePath);
    }

    return 0;
}
