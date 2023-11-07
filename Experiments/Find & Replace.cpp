//Morgan Precanico
//This is to run through a bunch of files, replacing text with other text based on another file
//Hopefully, this'll make life easier

#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
#include <vector>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <algorithm>
#include <cstdio>
#include <dirent.h>
#include "..\MWP.cpp"

using namespace std;

string getfile(ifstream& is);
void find_and_replace(string& file_contents, const string& find, const string& replace);
void replace_in_file(string pathOne, string pathTwo);
void replace_in_folder(string path, string replaceWith);

int main(){

    cout << "Enter which operation you'd like to commence:\n1) Single File\n2) Directory\n> ";

    string choice;

    getline(cin,choice);

    if(choice == "1"){
        string pathOne;
        cout << "Enter file to replace text in: ";
        getline(cin, pathOne);
        string pathTwo;
        cout << "Enter file to get replacement text from (Format: Phrase to Find = Phrase to Replace With): ";
        getline(cin, pathTwo);
        replace_in_file(pathOne,pathTwo);
        cout << "Complete.";
    }else if(choice == "2"){
        string dirPath;
        cout << "Enter directory path: ";
        getline(cin, dirPath);
        string replaceFile;
        cout << "Enter file to get replacement text from (Format: Phrase to Find = Phrase to Replace With): ";
        getline(cin, replaceFile);
        replace_in_folder(dirPath,replaceFile);
        cout << "Complete.";
    }

    
    
}

string getfile(ifstream& is) {
    string contents;
    // Here is one way to read the whole file
    for (char ch; is.get(ch); contents.push_back(ch)) {}
    return contents;
}

void find_and_replace(string& file_contents, const string& find, const string& replace) {
    auto pos = file_contents.find(find);
    while (pos != string::npos) {
        file_contents.replace(pos, find.length(), replace);
        // Continue searching from here.
        pos = file_contents.find(find, pos);
  }
}

void replace_in_file(string pathOne, string pathTwo){
    ifstream fileOne(pathOne);
    ifstream fileTwo(pathTwo);
    ofstream fileout;

    if(fileOne && fileTwo){
        string contents = getfile(fileOne);
    
        //Make two vectors, one for what to look for, and one for what to replace it with
        vector <string> find;
        vector <string> replace;

        //Go through the file, line by line
        string line;    
        while(getline(fileTwo,line)){
            //If the string contains an equal sign, split it, otherwise skip
            if(line.find('=') != string::npos){
                vector <string> temp = mwp::splitString(line,'=');
                find.push_back(temp[0]);
                replace.push_back(temp[1]);
            }  
        }
        
        //I couldn't get how you're supposed to remove whitespace from strings to work, so I ended up just copying and pasting this from online
        for(vector<string>::iterator it=find.begin();it!=find.end();it++){
            string& item = *it;
            size_t pos;
            while( (pos = item.find_first_of(" \t\r\n")) != string::npos){
                if(pos > 1){
                    item = item.substr(0,pos) + item.substr(pos+1);   
                }else{
                    item = item.substr(pos+1);   
                }
            }
        }
        for(vector<string>::iterator it=replace.begin();it!=replace.end();it++){
            string& item = *it;
            size_t pos;
            while( (pos = item.find_first_of(" \t\r\n")) != string::npos){
                if(pos > 1){
                    item = item.substr(0,pos) + item.substr(pos+1);   
                }else{
                    item = item.substr(pos+1);   
                }
            }
        }

        //Replace the contents with the file accordingly
        for(int i{0}; i < find.size(); i++){
            find_and_replace(contents, find[i], replace[i]);  
        }

        //Close both files
        fileOne.close();
        fileTwo.close();

        //Re-Open file one
        fileout.open(pathOne);
        //Save to file one
        fileout << contents;
        //Close again
        fileout.close();
    }
    else{
        cout << "File Not Found!";
    }
    
}

void replace_in_folder(string path, string replaceWith){

    vector <string> files;
    //Convert path to char*, so it can be used
    const char *filePath = path.c_str();

    DIR* dirFile = opendir(filePath);
    //If the directory exists, grab every json file and add to an array
    if (dirFile) {
        struct dirent* hFile;
        errno = 0;
        while ((hFile = readdir(dirFile)) != NULL ){
            if (!strcmp(hFile->d_name, ".")) continue;
            if (!strcmp(hFile->d_name, "..")) continue;
            // dirFile.name is the name of the file. Do whatever string comparison 
            // you want here. Something like:
            if (strstr(hFile->d_name, ".json"))
                files.push_back(hFile->d_name);
                
        } 
        closedir(dirFile);
    }

    //Replace the stuff in every file in the directory according to the replaceWith file
    for(size_t i{0}; i < files.size(); i++){
        //If the path doesn't end in a \, add one
        string::iterator it = path.end();
        if(*(it-1) == '\\'){
            replace_in_file(path + files[i],replaceWith);
        }else{
            replace_in_file(path + "\\" + files[i],replaceWith);
        }
        
    }

}