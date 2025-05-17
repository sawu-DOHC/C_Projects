#include "Header Files/BruteForce.h"
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path exePath = fs::current_path();
    fs::path wordlistPath = "C:/Users/Sam/OneDrive/Desktop Cloud/C   Projects/11 Networking/passwords.txt";


    runBruteForce("http://localhost:8000/login.php", "admin", wordlistPath.string());
    return 0;
}
