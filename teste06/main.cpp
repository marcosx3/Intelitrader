#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string a, std::string b)
{
    std::vector<int> n1(a.size()); // first number

    for (int i = 0; i < a.size(); i++)
    {
        n1[i] = a[a.size() - i - 1] - '0';
    }
    std::vector<int> n2(b.size()); // second number
    for (int i = 0; i < b.size(); i++)
    {
        n2[i] = b[b.size() - i - 1] - '0';
    }

    // Initialize the result vector with zeros
    std::vector<int> result(a.size() + b.size());
    // Multiply each digit in vec2 with vec1 and add the result to the appropriate position in the result vector
    for (int i = 0; i < n2.size(); i++)
    {
        int carry = 0;
        for (int j = 0; j < n1.size(); j++)
        {
            int product = n1[j] * n2[i] + carry + result[i + j];
            carry = product / 10;
            result[i + j] = product % 10;
        }
        result[i + n1.size()] = carry;
    }

    // Remove leading zeros from the result vector and convert it back to a string
    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }
    std::string str(result.size(), '0');
    for (int i = 0; i < result.size(); i++)
    {
        str[result.size() - i - 1] = result[i] + '0';
    }
    return str;
}

int main(int argc, char const *argv[])
{
    std::string num1 = "654154154151454545415415454";
    std::string num2 = "63516561563156316545145146514654";
    std::cout << multiply(num1, num2) << std::endl;
    return 0;
}
