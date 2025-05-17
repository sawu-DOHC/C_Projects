#ifndef CPROJECTS_SITE_H
#define CPROJECTS_SITE_H

#include <string>
#include <vector>

using namespace std;

class Site {

private:
    string name;
    vector<string> sections;
    string rootBase;
    string fullPath;
    string rawHTML;

public:
    // Constructor
    Site(const string& siteName, const vector<string>& sectionList) {

        name = siteName;
        sections = sectionList;
        rootBase = "C:\\Users\\Sam\\OneDrive\\Desktop Cloud\\HTML_Projects";
        fullPath = rootBase + "\\" + name;

        buildRawHTML();
        insertNav();

        insertSections();
        createDirectories();
        createIndex();
        createCSS();
        createJS();
    }

    // HTML generation
    void buildRawHTML();
    void insertNav();
    void insertSections();
    void createIndex();

    // Directory creation
    void createDirectories();

    // CSS generation
    void createCSS();
    void createBodyCSS();
    void createHeaderCSS();
    void createNavCSS();
    void createMainCSS();
    void createFooterCSS();

    // JS generation
    void createJS();
    void createMainJS();
    void createUtilityJS();

    // Utility
    void createFile(const string& path);
    void createFileWithContent(const string& path, const string& content);
};

#endif //CPROJECTS_SITE_H
