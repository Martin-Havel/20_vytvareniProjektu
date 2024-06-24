#include "windows.h"
#include "iostream"
#include "fstream"
using namespace std;
 
int main(int argc, char *argv[]){
    // cout << "Pocet argumentu je: " << argc << endl;
    // for(int i = 0; i < argc; i++){
    //     cout << i <<". argument je "<< argv[i] << endl;
    // }
    if(argc==2){
        const char *cesta = argv[1];
        CreateDirectory(cesta, NULL); //vytvoreni adrasare projektu
        ofstream sourceFile;
        string filePath = cesta;
        string filePathH = cesta;
        filePath += "\\main.cpp";
        filePathH += "\\color.h";
        LPCSTR lpMyString = filePath.c_str();
        LPCSTR lpMyString2 = filePathH.c_str();
 
        cout << filePath << '\n';
        sourceFile.open(filePath);
        sourceFile << "#include <iostream>" << '\n' <<"#include \"color.h\""<< "\nusing namespace std;"  << "\nint main(int argc, char *argv[]) {" << "\n\t" << "return 0;" << '\n' <<'}';
        sourceFile.close();
 
        cout << filePathH << '\n';
        sourceFile.open(filePathH);
        sourceFile << "#define RESET\"\033[0m;\"\n#define BLACK\"\033[30m\";/* Black */\n#define RED\"\033[31m\";/* Red */";
        sourceFile.close();
 
    } else cout << "zadal jsi nespravny pocet parametru!\n";
 
    return 0;
}