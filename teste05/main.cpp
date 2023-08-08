#include <iostream>
#include <fstream>
#include <string>

const int cipher = 3;

std::string  readTextFile()
{
    std::fstream arq,arq2;
    std::string line,text, text2,resul;
    arq.open("text1.txt",std::ios::in);

    if(arq.is_open())
    {
        while(getline(arq,line))
        {
            text += line;
            text.push_back('\n');
        }
        arq.close();
    } else {
        std::cout << "Não foi possivel abrir o 1° arquivo.";
    }

arq.open("text2.txt",std::ios::in);

    if(arq.is_open())
    {
        while(getline(arq,line))
        {
            text2 += line;
            text2.push_back('\n');
        }
        arq.close();
    } else {
        std::cout << "Não foi possivel abrir o 2° arquivo.";
    }

    resul = text + text2;
    return resul;
}

void writeTextFile()
{
    std::fstream arq;
    arq.open("resultado.txt",std::ios::out);
    if(arq.is_open())
    {
        arq << readTextFile();
    } else {
        std::cout << "Não foi possível escrever novo arquivo";
    }
}

int main(int argc, char const *argv[])
{
    writeTextFile();
    return 0;
}
