//
//  main.cpp
//  StableMatching
//
//  Created by Jeffrey Lima on 7/14/16.
//  Copyright © 2016 Jeffrey Lima. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "BruteForceSM/BruteForceSM.hpp"

void load(std::ifstream & inputFile, std::vector< std::vector<unsigned> > & maleRanks, std::vector< std::vector<unsigned> > & femaleRanks);

int main(int argc, const char * argv[]){
    std::cout << "Brute Force Stable Matching Algorithm\n";
    
    std::ifstream inputFile("resources/Problem4.txt");
    if(inputFile.is_open()){
        unsigned N;
        inputFile >> N;
        std::vector< std::vector<unsigned> > maleRanks(N, std::vector<unsigned>(N));
        std::vector< std::vector<unsigned> > femaleRanks(N, std::vector<unsigned>(N));
        load(inputFile, maleRanks, femaleRanks);
        
        // Time to Output stable matching set(s)
        clock_t t;
        t = clock();
        BruteForceSM bf( maleRanks, femaleRanks);
        t = clock() - t;
        bf.printStableMatchSet();
        std::cout << N << "! took " << (((float)t) / CLOCKS_PER_SEC)*1000 << "msec.\n";
    } else {
        std::cout << "File did not open...\n";
    }
    inputFile.close();
    
    return 0;
}

void load(std::ifstream & inputFile, std::vector< std::vector<unsigned> > & maleRanks, std::vector< std::vector<unsigned> > & femaleRanks) {
    while (!inputFile.eof()){
        for (unsigned i = 0; i < maleRanks.size(); i++){
            for (unsigned j = 0; j < maleRanks[0].size(); j++){
                inputFile >> maleRanks[i][j];
            }
        }
        for (unsigned i = 0; i < femaleRanks.size(); i++){
            for (unsigned j = 0; j < femaleRanks[0].size(); j++){
                inputFile >> femaleRanks[i][j];
            }
        }
    }
}