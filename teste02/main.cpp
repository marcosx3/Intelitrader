#include <iostream>
#include <fstream>
#include <string>

const int cipher = 3;
std::string readTextFile()
{
    std::fstream arq;
    std::string text;
    arq.open("app.txt", std::ios::in);
    if (arq.is_open())
    {
        std::string line;
        while (std::getline(arq, line))
        {
            text += line;
            text.push_back('\n');
        }
        arq.close();
    }
    else
    {
        std::cout << "Nao foi possivel abrir arquivo";
    }
    return text;
}

std::string encodeTextFile(std::string t)
{
    std::string text = t;
    char letter;
    for (int i = 0; text[i] != '\0'; ++i)
    {
        letter = text[i];
        if (letter >= 'a' && letter <= 'z')
        {
            letter = letter + cipher;
            if (letter > 'z')
            {
                letter = letter - 'z' + 'a' - 1;
            }
            text[i] = letter;
        }
        else if (letter >= 'A' && letter <= 'Z')
        {
            letter = letter + cipher;
            if (letter > 'Z')
            {
                letter = letter - 'Z' + 'A' - 1;
            }
            text[i] = letter;
        }
    }
    return text;
}

void writeTextEncodeFile()
{
    std::fstream arq;
    std::string t = readTextFile();
    arq.open("decode.txt", std::ios::out);
    if (arq.is_open())
    {
        arq << encodeTextFile(t);
    }
    else
    {
        std::cout << "Não foi possível criar novo arquivo";
    }
}

std::string readTextEncodeFile()
{
    std::fstream arq;
    std::string text;
    arq.open("encode.txt", std::ios::in);
    if (arq.is_open())
    {
        std::string line;
        while (std::getline(arq, line))
        {
            text += line;
            text.push_back('\n');
        }
        arq.close();
    }
    else
    {
        std::cout << "Nao foi possivel abrir arquivo";
    }
    return text;
}

std::string decodeTextFile(std::string t)
{
    std::string text = t;
    char letter;
    for (int i = 0; text[i] != '\0'; ++i)
    {
        letter = text[i];
        if (letter >= 'a' && letter <= 'z')
        {
            letter = letter - cipher;
            if (letter < 'a')
            {
                letter = letter + 'z' - 'a' + 1;
            }
            text[i] = letter;
        }
        else if (letter >= 'A' && letter <= 'Z')
        {
            letter = letter - cipher;
            if (letter > 'a')
            {
                letter = letter + 'Z' - 'A' + 1;
            }
            text[i] = letter;
        }
    }
    return text;
}

void writeTextDecodeFile()
{
    std::fstream arq;
    std::string t = readTextEncodeFile();
    arq.open("decode.txt", std::ios::out);
    if (arq.is_open())
    {
        arq << decodeTextFile(t);
    }
    else
    {
        std::cout << "Não foi possível criar novo arquivo";
    }
}

int main(int argc, char const *argv[])
{
    int choise;
    std::cout << "1 - CRIPTOGRAFAR\n2 - DESCRIPTOGRAFAR\n";
    std::cout << "Selecione: ";
    std::cin >> choise;
    switch (choise)
    {
    case 1:
        writeTextEncodeFile();
        break;
    case 2:
        writeTextDecodeFile();
        break;
    default:
        break;
    }
    return 0;
}
