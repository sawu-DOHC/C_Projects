#import <iostream>


int main() {
    std::string root = "C:\\Users\\Sam\\OneDrive\\Desktop Cloud\\HTML_Projects\\expservicecenter.com";

    std::cout << "🔧 Building site scaffold at: " << root << "\n";

    system(("mkdir \"" + root + "\"").c_str());


    std::cout << "\n✅ Site structure complete.\n";
    return 0;
}
