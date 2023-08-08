#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    } else
    {
        std::cout << "Nao foi possivel abrir arquivo";
    }
    return text;
}
std::string encodeBase64(std::string s)
{
    std::string text;
    int val = 0;
    int valb = -6;
    for (char c : s)
    {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0)
        {
            text.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3f]);
            valb -= 6;
        }
    }
    if (valb > -6)
        text.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
    while (text.size() % 4)
        text.push_back('=');
    return text;
}
void writeTextEncodeFile(std::string t)
{
    std::fstream arq;
    std::string text = t;
        arq.open("encode.txt", std::ios::out);
        if (arq.is_open())
        {
            arq << text;
        }
        arq.close();
}

std::string readTextFileEncode()
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
            std::cout << line << std::endl;
        }
        arq.close();
    }
    else
    {
        std::cout << "Nao foi possivel abrir arquivo";
    }
    return text;
}
std::string decodeBase64(std::string s)
{
    std::string text;
    int val = 0, valb = -8;
    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++)
    {
        T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
    }
    for (char c : s)
    {
        if (T[c] == -1)
            break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0)
        {
            text.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return text;
}
void writeTextDecodeFile(std::string t)
{
    std::fstream arq;
    std::string text = t;
        arq.open("decode.txt", std::ios::out);
        if (arq.is_open())
        {
            arq << text;
        }
        arq.close();
}

int main(int argc, char const *argv[])
{
    std::string text = readTextFile();
    std::string textEncode = encodeBase64(text);
    std::string textCodi = readTextFileEncode();
    std::string textDecode = decodeBase64(textCodi);
    int choise;

    std::cout << "*-*-*-*-*-*-* Selecione uma opcao *-*-*-*-*-*\n";
    std::cout << "1 - Codificar\n2 - Decodificar\n";
    std::cout <<"Selecione: ";
    std::cin >> choise;

    switch (choise)
    {
    case 1:
        writeTextEncodeFile(textEncode);
        break;
    case 2:
       writeTextDecodeFile(textDecode);
    default:
        break;
    }
    return 0;
}
