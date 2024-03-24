#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "xor.cpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <bat_file_path>\n";
        return 1;
    }

    std::string filePath = argv[1];
    std::ifstream batFile(filePath);
    if (!batFile.is_open()) {
        std::cerr << "Failed to open " << filePath << '\n';
        return 1;
    }

    std::ofstream headerFile("data.h", std::ofstream::out);
    if (!headerFile.is_open()) {
        std::cerr << "Failed to create data.h\n";
        return 1;
    }

    char key = 'X'; // Simple XOR key
    headerFile << "#include <vector>\n#include <string>\n\n";
    headerFile << "std::vector<std::string> encryptedCommands = {\n";

    std::string line;
    while (std::getline(batFile, line)) {
        std::string encryptedLine = xorEncryptDecrypt(line, key);
        headerFile << "    \"";
        for (char c : encryptedLine) {
            headerFile << "\\x" << std::hex << (0xFF & static_cast<int>(c));
        }
        headerFile << "\",\n";
    }

    headerFile << "};\n";
    batFile.close();
    headerFile.close();

    return 0;
}