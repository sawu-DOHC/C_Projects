#ifndef CPROJECTS_SITE_H
#define CPROJECTS_SITE_H

#include <string>
#include <vector>

class Site {

private:
    std::string rootBase;
    std::string name;
    std::string fullPath;
    std::vector<std::string> sections;

public:
    // Constructor
    Site(const std::string& siteName, const std::vector<std::string>& sectionList);

    // Build steps
    void createDirectories();
    void createCSS();
    void createJS();
    void createHTML();

    // Utility
    void createFile(const std::string& path);
};

#endif //CPROJECTS_SITE_H
