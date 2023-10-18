#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <input_file_name> <output_file_name>" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2], std::ios::binary | std::ios::trunc);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "[Error] Failed to open the file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<float> values;
        std::istringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            try {
                float value = std::stof(cell);
                values.push_back(value);
            } catch (const std::invalid_argument& e) {
                std::cerr << "[Error] Invalid floating-point number found: " << cell << std::endl;
                return 1;
            }
        }

        if (!values.empty()) {
            outputFile.write(reinterpret_cast<char*>(values.data()), values.size() * sizeof(float));
        }
    }

    inputFile.close();
    outputFile.close();

    std::cerr << "Finished" << std::endl;
    return 0;
}
