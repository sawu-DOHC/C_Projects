#include "../Header Files/Site.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void Site::buildRawHTML() {
    rawHTML = R"(<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>)" + name + R"(</title>

  <link rel="stylesheet" href="CSS/Base/A_body.css">
  <link rel="stylesheet" href="CSS/Base/B_header.css">
  <link rel="stylesheet" href="CSS/Base/C_nav.css">
  <link rel="stylesheet" href="CSS/Base/D_main.css">
  <link rel="stylesheet" href="CSS/Base/E_footer.css">

  <script src="JS/main.js" defer></script>
  <script src="JS/Utilities/showArticle.js" defer></script>
  <script src="JS/Utilities/showSection.js" defer></script>
  <script src="JS/Utilities/toggleMenu.js" defer></script>
</head>
<body>

  <header>
    <button id="menu-toggle" aria-label="Toggle navigation">☰</button>
  </header>

  <nav>
  </nav>

  <main>
  </main>

  <footer>
  </footer>

</body>
</html>
)";
}

void Site::insertNav() {
    string nav;
    nav += "  <nav>\n";
    nav += "    <ul>\n";

    for (int i = 0; i < sections.size(); i++) {
        string section = sections[i];
        string label = section;

        if (label.size() > 0) {
            char first = label[0];
            char upper = toupper(first);
            label[0] = upper;
        }

        nav += "      <li><a href=\"#";
        nav += section;
        nav += "\" onclick=\"showSection('";
        nav += section;
        nav += "')\">";
        nav += label;
        nav += "</a></li>\n";
    }

    nav += "    </ul>\n";
    nav += "  </nav>\n";

    size_t navStart = rawHTML.find("<nav");
    size_t navTagClose = rawHTML.find(">", navStart);
    size_t navEnd = rawHTML.find("</nav>", navTagClose);

    if (navStart != string::npos && navEnd != string::npos && navEnd > navStart) {
        rawHTML.replace(navStart, navEnd - navStart + 6, nav);
        cout << "🧭 Navigation inserted into rawHTML.\n";
    }
    else {
        cerr << "❌ <nav> block not found in rawHTML.\n";
    }
}
void Site::insertSections() {
    string allSections;
    allSections += "  <main>\n";

    for (int i = 0; i < sections.size(); i++) {
        string section = sections[i];
        string label = section;

        if (label.size() > 0) {
            char first = label[0];
            char upper = toupper(first);
            label[0] = upper;
        }

        allSections += "    <section id=\"";
        allSections += section;
        allSections += "\">\n";

        allSections += "      <h2>";
        allSections += label;
        allSections += "</h2>\n";

        allSections += "    </section>\n\n";
    }

    allSections += "  </main>\n";

    size_t mainStart = rawHTML.find("<main");
    size_t mainTagClose = rawHTML.find(">", mainStart);
    size_t mainEnd = rawHTML.find("</main>", mainTagClose);

    if (mainStart != string::npos && mainEnd != string::npos && mainEnd > mainStart) {
        rawHTML.replace(mainStart, mainEnd - mainStart + 7, allSections); // +7 for "</main>"
        cout << "📌 Sections inserted into rawHTML.\n";
    } else {
        cerr << "❌ <main> block not found in rawHTML.\n";
    }
}
void Site::createDirectories() {
    string root = fullPath;
    string cssBase = fullPath + "\\CSS\\Base";
    string cssComponents = fullPath + "\\CSS\\Components";
    string jsRoot = fullPath + "\\JS";
    string jsUtils = fullPath + "\\JS\\Utilities";
    string assets = fullPath + "\\Assets";

    system(("mkdir \"" + root + "\"").c_str());
    system(("mkdir \"" + cssBase + "\"").c_str());
    system(("mkdir \"" + cssComponents + "\"").c_str());
    system(("mkdir \"" + jsRoot + "\"").c_str());
    system(("mkdir \"" + jsUtils + "\"").c_str());
    system(("mkdir \"" + assets + "\"").c_str());

    cout << "📁 Created directories for " << name << "\n";
}

void Site::createIndex() {
    string path = fullPath + "\\index.html";

    ofstream file(path);
    file << rawHTML;
    file.close();

    cout << "📝 index.html written to: " << path << '\n';
}
void Site::createCSS() {
    createBodyCSS();
    createHeaderCSS();
    createNavCSS();
    createMainCSS();
    createFooterCSS();

    cout << "🎨 CSS files created\n";
}

void Site::createBodyCSS() {
    string path = fullPath + "\\CSS\\Base\\A_body.css";
    string css = R"(body {
  font-family: Arial, Helvetica, sans-serif;
  max-width: 1900px;
  margin: 0 auto;
  padding: 1rem;
  line-height: 1.6;
}

h1 {
  font-size: 5rem;
  color: rgba(0, 0, 0, 0.6);
  margin: 0;
}

h2 {
  font-size: 2rem;
  color: #000;
  margin: 0;
}

h3 {
  font-size: 1.25rem;
  font-weight: bold;
  margin: 0.5rem 0;
  text-align: center;
}

h4 {
  font-size: 1.1rem;
  font-weight: normal;
  margin: 0.5rem 0;
}

p {
  font-size: 1.25rem;
  margin: 0.5rem 0;
}

a {
  font-size: 1.25rem;
  color: #1134f3;
  text-decoration: underline;
}

a:hover {
  color: #000;
  text-decoration: none;
}

label {
  font-size: 1.25rem;
  font-weight: bold;
  display: inline-block;
  margin-bottom: 0.25rem;
}

ul {
  font-size: 1.25rem;
  padding-left: 1.25rem;
  margin: 0.5rem 0;
}

li {
  font-size: 1.25rem;
  margin-bottom: 0.25rem;
}

@media (max-width: 800px) {
  body {
    padding: .125rem;
    overflow-x: hidden;
    scrollbar-width: none;
  }

  h1 {
    font-size: 2.5rem;
    text-align: center;
  }

  h2 {
    font-size: 1.5rem;
    padding-left: 1rem;
  }

  h3 {
    font-size: 1.1rem;
  }

  h4 {
    font-size: 1rem;
  }

  p {
    font-size: 1rem;
  }
}
)";
    createFileWithContent(path, css);
}
void Site::createHeaderCSS() {
    string path = fullPath + "\\CSS\\Base\\B_header.css";

    string css = R"(header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  height: 6rem;
  padding: 0 1rem;
}

#menu-toggle {
  display: none;
}

@media (max-width: 800px) {
  header {
    padding: 0.5rem 1rem;
  }

  #menu-toggle {
    display: block;
    font-size: 2rem;
    background: none;
    border: none;
    cursor: pointer;
    padding: 0.5rem;
  }
}
)";

    createFileWithContent(path, css);
}
void Site::createMainCSS() {
    string path = fullPath + "\\CSS\\Base\\D_main.css";

    string css = R"(main {
  margin: 0 auto;
  max-width: 1200px;
  position: relative;
  overflow: hidden;
}

article {
  border: 3px dashed #888;
  padding: 1rem;
  margin-bottom: 2rem;
}

main > section {
  display: none;
}

main > section.visible {
  display: block;
}

article.blink {
  animation: blink-highlight 1s ease-in-out 2;
}

@keyframes blink-highlight {
  0% {
    background-color: transparent;
    color: inherit;
  }
  50% {
    background-color: rgb(61, 145, 30);
    color: white;
  }
  100% {
    background-color: transparent;
    color: inherit;
  }
}
)";

    createFileWithContent(path, css);
}
void Site::createFooterCSS() {
    string path = fullPath + "\\CSS\\Base\\E_footer.css";

    string css = R"(footer {
  max-width: 1200px;
  margin: 0 auto;
  display: flex;
  justify-content: space-between;
  flex-wrap: wrap;
}

@media (max-width: 800px) {
  footer {
    flex-direction: column;
    align-items: center;
  }
}
)";

    createFileWithContent(path, css);
}
void Site::createNavCSS() {
    string path = fullPath + "\\CSS\\Base\\C_nav.css";
    string css = R"(nav ul {
  display: flex;
  justify-content: center;
  margin: 0;
  padding: 0;
  list-style: none;
  background: #fff;
  z-index: 2;
}
nav ul li {
  position: relative;
}
nav a {
  display: block;
  padding: 1rem;
  font-size: 1.25rem;
  font-weight: bold;
  color: #000;
  text-decoration: none;
}
nav a:hover {
  color: #ff6600;
}
nav li ul {
  display: none;
  position: absolute;
  top: 100%;
  left: 0;
  background: #fff;
  margin: 0;
  padding: 0;
  list-style: none;
  border: 1px solid #ccc;
}
@media (hover: hover) {
  nav li:hover ul {
    display: block;
  }
  nav li ul {
    min-width: 300px;
  }
}
nav li ul li a {
  padding: 0.75rem 1rem;
  font-weight: normal;
  color: #000;
}
nav li ul li a:hover {
  background: #f9f9f9;
  color: #ff6600;
}
@media (max-width: 800px) {
  nav ul {
    display: flex;
    flex-direction: column;
    max-height: 0;
    overflow: hidden;
    transition: max-height 0.5s ease-out;
    width: 100%;
  }
  nav ul.active {
    max-height: 500px;
  }
  nav ul li {
    border-bottom: 1px solid #eee;
  }
  nav a {
    text-align: center;
    font-size: 1.1rem;
  }
  nav li ul {
    position: static;
    border: none;
    display: none;
  }
  nav li.show-submenu ul {
    display: flex;
    flex-direction: column;
  }
  nav li ul li a {
    padding-left: 2rem;
  }
}
)";
    createFileWithContent(path, css);
}

void Site::createJS() {
    createMainJS();
    createUtilityJS();
    cout << "⚙️ JavaScript files created\n";
}

void Site::createMainJS() {
    string path = fullPath + "\\JS\\main.js";

    string js = R"(// main.js
document.addEventListener("DOMContentLoaded", () => {
  console.log("Site loaded.");
});
)";

    createFileWithContent(path, js);
}

void Site::createUtilityJS() {
    string base = fullPath + "\\JS\\Utilities";

    string showSectionJS = R"(function showSection(id) {
  const sections = document.querySelectorAll("main > section");

  for (let i = 0; i < sections.length; i++) {
    sections[i].classList.remove("visible");
  }

  const target = document.getElementById(id);
  target.classList.add("visible");

  requestAnimationFrame(() => {
    window.scrollTo({ top: 0, behavior: 'instant' });
  });

  toggleMenu();
}
)";

    string showArticleJS = R"(function showArticle(sectionId, articleId) {
  const sections = document.querySelectorAll("main > section");

  for (let i = 0; i < sections.length; i++) {
    sections[i].classList.remove("visible");
  }

  const section = document.getElementById(sectionId);
  const article = document.getElementById(articleId);

  section.classList.add("visible");
  article.classList.add("blink");

  article.addEventListener("animationend", () => {
    article.classList.remove("blink");
  }, { once: true });

  requestAnimationFrame(() => {
    requestAnimationFrame(() => {
      window.scrollTo(0, article.offsetTop);
    });
  });
}
)";

    string toggleMenuJS = R"(function toggleMenu() {
  const menu = document.querySelector("nav > ul");
  if (menu) {
    menu.classList.toggle("active");
  }
}

document.addEventListener("DOMContentLoaded", () => {
  const toggle = document.getElementById("menu-toggle");
  if (toggle) {
    toggle.addEventListener("click", toggleMenu);
  }
});
)";

    createFileWithContent(base + "\\showSection.js", showSectionJS);
    createFileWithContent(base + "\\showArticle.js", showArticleJS);
    createFileWithContent(base + "\\toggleMenu.js", toggleMenuJS);
}




void Site::createFile(const string& path) {
    ofstream file(path);
    file.close();
    cout << "Created: " << path << '\n';
}

void Site::createFileWithContent(const string& path, const string& content) {
    ofstream file(path);
    file << content;
    file.close();
    cout << "Created: " << path << '\n';
}
