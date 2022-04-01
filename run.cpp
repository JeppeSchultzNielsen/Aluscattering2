//
// Created by jeppe on 3/10/22.
//
#include "include/runner.h"
#include "include/runner2.h"
#include <filesystem>
#include <string>
#include <iostream>
#include "dirent.h"
#include <tuple>
#include <regex>
#include <vector>
#include <fstream>
using namespace std;

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

    string saveto = "rates.txt";
    ofstream mytxt (saveto);
    mytxt << "Counts\tSolid angle\tNew Solid\tEnergy\tDeltaClock\tDeltaCharge\tAngle\n";

    string saveto2 = "accFit.txt";
    ofstream mytxt2 (saveto2);
    mytxt2 << "Energy\tExpectedE\tMeasuredE\n";


    for(int k = 0; k < i; k++){
        //kan kommenteres ud hvis analyzen er kørt før
        createFile("match/" + adresses[k]);

        vector<double> energies = cmEfitter(adresses[k]);
        mytxt2 << to_string(energies[0]) + "\t" + to_string(energies[1]) + "\t" + to_string(energies[2])+"\n";
        /*
        createTxt(adresses[k], 10, 0.5);

        std::vector<int> angles = {100,105,110,115,120,125,140,145,150,155};

        std::vector<double> current = findCurrent(adresses[k]);
        double deltaClock = current[0];
        double deltaCharge = current[1];

        for(int j = 0; j < angles.size(); j++){
            std::vector<double> countsAtAngle = thickness(adresses[k], angles[j]);
            double countsat110 = countsAtAngle[0];
            double solidangle = countsAtAngle[1];
            double solidangle2 = countsAtAngle[2];
            double energy = countsAtAngle[3];

            mytxt << to_string(countsat110) + "\t" + to_string(solidangle) + "\t" + to_string(solidangle2)
                     + "\t" + to_string(energy) + "\t" + to_string(deltaClock) + "\t" +
                     to_string(deltaCharge) +"\t"+ to_string(angles[j])+"\n";
        }*/
    }
    mytxt.close();
}
