/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:30:56 by yousef            #+#    #+#             */
/*   Updated: 2025/04/30 02:00:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string my_replace(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = line.find(s1, start)) != std::string::npos)
    {
        result += line.substr(start, pos - start); // copy unchanged part
        result += s2; // insert replacement
        start = pos + s1.length(); // move past the replaced part
    }
    result += line.substr(start); // append remaining part
    return result;
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return 1;
    }

    std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return 1;
    }

    std::string s1(argv[2]);
    std::string s2(argv[3]);
    std::string line;

    while (std::getline(inputFile, line))
    {
        outputFile << my_replace(line, s1, s2);
        if (inputFile.peek() != EOF)
            outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
