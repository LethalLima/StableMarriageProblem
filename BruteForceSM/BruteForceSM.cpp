//
//  BruteForce.cpp
//  StableMatching
//
//  Created by Jeffrey Lima on 7/14/16.
//  Copyright © 2016 Jeffrey Lima. All rights reserved.
//

#include "BruteForceSM.hpp"


BruteForceSM::BruteForceSM(unsignedDoubleVector mRanks, unsignedDoubleVector fRanks){
        maleRanks = mRanks;
        femaleRanks = fRanks;
        stableMatch.resize(mRanks.size());
        findStableMatchings();
};
    

unsigned long BruteForceSM::factorial(const unsigned long & n){
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
bool BruteForceSM::mPrefersW1OverW(const unsigned & m, const unsigned & W, const unsigned & W1){
        for (unsigned i = 0; i < maleRanks.size(); i++){
            if (maleRanks[m][i] == W)
                return false;
            if (maleRanks[m][i] == W1)
                return true;
        }
        return false;
}
bool BruteForceSM::wPrefersM1OverM(const unsigned & w, const unsigned & M, const unsigned & M1){
        for (unsigned i = 0; i < femaleRanks.size(); i++){
            if (femaleRanks[w][i] == M)
                return false;
            if (femaleRanks[w][i] == M1)
                return true;
        }
        return false;
    }

BruteForceSM & BruteForceSM::printStableMatchSet(){
    std::cout << '[';
    for (unsigned i = 0; i < stableMatch.size(); i++){
        std::cout << '(' << stableMatch[i].getM() << ',' << stableMatch[i].getW() << ')'
        << (i + 1 < stableMatch.size() ? ", " : "]\n");
    }
    return *this;
}

bool BruteForceSM::isStableMatch(){
    for (unsigned i = 0; i < stableMatch.size(); i++)
        for (unsigned j = 0; j < stableMatch.size(); j++)
            // both wPrefersM1OverM & mPrefersW1OverW must be true for there to be an instability in the set and return false
            if (wPrefersM1OverM(stableMatch[i].getW(), stableMatch[i].getM(), femaleRanks[stableMatch[i].getW()][j]) &&
                mPrefersW1OverW(femaleRanks[stableMatch[i].getW()][j], stableMatch[femaleRanks[stableMatch[i].getW()][j]].getW(), stableMatch[i].getW()) )
                return false;
    //There are no instabilities and returns true.
    return true;
}

BruteForceSM & BruteForceSM::findStableMatchings(){
        // Store male preference and create a ranks array to help permutate N! matchings
    unsignedVec ranks(stableMatch.size());
    for (unsigned i = 0; i < stableMatch.size(); i++){
        stableMatch[i].storeManRank(i);
        ranks[i] = i;
    }
        
    std::sort(ranks.begin(), ranks.end());
        
    for (unsigned i = 0; i < factorial(stableMatch.size()); i++){
        for (unsigned j = 0; j < stableMatch.size(); j++){
            stableMatch[j].storeWomanRank(ranks[j]);
        }
        //pass one sorted permutation matching set at a time.
        if (isStableMatch()){
            printStableMatchSet();
        }
        std::next_permutation(ranks.begin(), ranks.end());
    }
    return *this;
}


