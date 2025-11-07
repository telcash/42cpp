/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+      */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:10:15 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/11/06 21:28:07 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


static std::string replaceAll(const std::string &input,
                              const std::string &search,
                              const std::string &replacement) {
    std::string result;
    std::string::size_type pos = 0;
    std::string::size_type found;

    if (search.empty())
        return input;
    while ((found = input.find(search, pos)) != std::string::npos) {
        result.append(input, pos, found - pos);
        result.append(replacement);
        pos = found + search.length();
    }
    result.append(input, pos, std::string::npos);
    return result;
}

int main(int argc, char **argv) {
    std::string filename;
    std::string s1;
    std::string s2;

    if (argc != 4) {
        std::cout << "Wrong number of arguments." << std::endl;
        return 1;
    }

    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];

    if (filename.empty()) {
        std::cerr << "Error: filename cannot be empty." << std::endl;
        return 1;
    }
    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: could not open '" << filename << "' for reading." << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << inputFile.rdbuf();
    if (inputFile.bad()) {
        std::cerr << "Error: failed while reading '" << filename << "'." << std::endl;
        return 1;
    }
    const std::string content = buffer.str();

    const std::string replaced = replaceAll(content, s1, s2);
    const std::string outputFilename = filename + ".replace";

    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: could not open '" << outputFilename << "' for writing." << std::endl;
        return 1;
    }
    outputFile << replaced;
    if (!outputFile) {
        std::cerr << "Error: failed while writing '" << outputFilename << "'." << std::endl;
        return 1;
    }

    std::cout << "Replaced occurrences of '" << s1 << "' with '" << s2
              << "' in '" << filename << "'. Output written to '"
              << outputFilename << "'." << std::endl;
    return 0;
}
