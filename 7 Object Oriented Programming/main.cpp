#include "Header Files/Site.h"
#include <vector>
#include <string>


int main() {

    std::vector< std::string > sections = {

            "Home",
            "About",
            "Gallery",
            "Contact"
    };

    Site mySite("newSite.com", sections);

    return 0;
}
