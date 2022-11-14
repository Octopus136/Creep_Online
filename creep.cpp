#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32

void sleepcp(int milliseconds)
{
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000); 
    #endif // _WIN32
}

void creep(int ground_length, std::string name, int delay_ms){
    int dir = 1;
    int pos = 0;
    std::reverse(name.begin(), name.end());
    while(true){
        system("clear");
        for(int i = 0; i < pos; i++){
            std::cout << " ";
        }
        std::cout << name << std::endl;
        if(pos == ground_length - name.length()){
            dir = -1;
            std::reverse(name.begin(), name.end());
        }
        if(pos == 0){
            dir = 1;
            std::reverse(name.begin(), name.end());
        }
        for(int i = 0; i < ground_length; i++){
            std::cout << "-";
        }
        std::cout << std::endl;
        sleepcp(delay_ms);
        pos += dir;
    }
}
int main(int argc, char* argv[]){
    try {
        if(argc != 3 && argc != 1) {
            throw "Invalid number of arguments";
        }
    }
    catch(const char* msg) {
        std::cerr << msg << std::endl;
        return 1;
    }
    int ground_length, delay_ms;
    if(argc == 3) {
        std::string ground_length_str = argv[1];
        std::string delay_ms_str = argv[2];
        try {
            for(int i = 0; i < ground_length_str.length(); i++){
                if(!isdigit(ground_length_str[i])){
                    throw "Invalid ground length";
                }
            }
            for(int i = 0; i < delay_ms_str.length(); i++){
                if(!isdigit(delay_ms_str[i])){
                    throw "Invalid delay";
                }
            }
        }
        catch(const char* msg) {
            std::cerr << msg << std::endl;
            return 1;
        }
        ground_length = std::stoi(ground_length_str);
        delay_ms = std::stoi(delay_ms_str);
    }
    else {
        ground_length = 20;
        delay_ms = 100;
    }
    std::string name;
    std::cout << "Who will creep : ";
    std::cin >> name;
    try {
        if(ground_length <= name.length()){
            throw "Ground length is too small!";
        }
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
        return 1;
    } 
    creep(ground_length, name, delay_ms);
    return 0;
}
