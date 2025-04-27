#include "../Header Files/Site.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void Site::createDirectories() {
    system(("mkdir \"" + fullPath + "\"").c_str());
    system(("mkdir \"" + fullPath + "\\Assets\"").c_str());
    system(("mkdir \"" + fullPath + "\\CSS\"").c_str());
    system(("mkdir \"" + fullPath + "\\JS\"").c_str());
    system(("mkdir \"" + fullPath + "\\sections\"").c_str());

    std::cout << "📁 Directories created for: " << name << "\n";
}

void Site::createCSS() {
    std::string cssBase = fullPath + "\\CSS\\Base";
    system(("mkdir \"" + cssBase + "\"").c_str());

    const std::string bodyCSS = R"(
        body {

        }

        /* Headings */
        h1 {

        }

        h2 {

        }

        h3 {

        }

        h4 {

        }

        /* Paragraphs */
        p {

        }

        /* Links */
        a {

        }

        a:hover {

        }

        /* Labels */
        label {

        }

        /* Lists */
        ul {

        }

        li {

        }


        @media (max-width: 800px) {

          body {

          }

          h1 {

          }

          h2 {

          }

          h3 {

          }

          h4 {

          }

          p {

          }

          a {

          }

        }
    )";


    createFile(cssBase + "\\A_body.css", bodyCSS);
    createFile(cssBase + "\\B_header.css");
    createFile(cssBase + "\\C_nav.css");
    createFile(cssBase + "\\D_main.css");
    createFile(cssBase + "\\E_footer.css");

    std::cout << "🧾 CSS files created in " << cssBase << '\n';
}

void Site::createFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (file) {
        file << content;
        file.close();
        std::cout << "Created: " << path << '\n';
    }
    else {
        std::cerr << "❌ Failed to create: " << path << '\n';
    }
}
