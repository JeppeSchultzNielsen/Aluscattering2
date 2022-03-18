//
// Created by jeppe on 3/10/22.
//
#include "include/runner.h"
#include "include/runner2.h"
#include <filesystem>
#include <string>
#include <iostream>
#include "dirent.h"

int main(int argc, char *argv[]){
    //det her stykke kode er copy pastet herfra
    //https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
    //det finder navnene på alle filer i match mappen.
    string adresses[100];
    int i = 0;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("match")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            string name = ent -> d_name;
            if(!(name == ".") && !(name == "..")){
                adresses[i] = name;
                i++;
            }
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }

    for(int k = 0; k < i; k++){
        //kan kommenteres ud hvis analyzen er kørt før
        //createFile("match/" + adresses[k]);

        //createTxt(adresses[k], 10, 0.5);

        thickness(adresses[k]);
    }
}
