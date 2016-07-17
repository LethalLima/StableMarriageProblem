//
//  BruteForce.hpp
//  StableMatching
//
//  Created by Jeffrey Lima on 7/14/16.
//  Copyright © 2016 Jeffrey Lima. All rights reserved.
//

#ifndef BruteForceSM_hpp
#define BruteForceSM_hpp

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<unsigned> unsignedVec;
typedef std::vector< unsignedVec > unsignedDoubleVector;

class BruteForceSM{
public:
    BruteForceSM(unsignedDoubleVector mRanks, unsignedDoubleVector fRanks);
    BruteForceSM & printStableMatchSet();
    
private:
    unsignedDoubleVector maleRanks;
    unsignedDoubleVector femaleRanks;
    unsigned long factorial(const unsigned long & n);
    
    bool mPrefersW1OverW(const unsigned & m, const unsigned & W, const unsigned & W1);
    bool wPrefersM1OverM(const unsigned & w, const unsigned & M, const unsigned & M1);
    bool isStableMatch();
    BruteForceSM & findStableMatchings();
    // A pertumation of N! temporary stored to be checked for stability, and
    // then printed if a stable matching set.
    struct MatchSet{
    public:
        unsigned getM() const {
            return man;
        }
        unsigned getW() const {
            return woman;
        }
        MatchSet & storeManRank(unsigned rank){
            man = rank;
            return *this;
        }
        MatchSet & storeWomanRank(unsigned rank){
            woman = rank;
            return *this;
        }
    private:
        unsigned man, woman;
    };
    std::vector<MatchSet> stableMatch;
};


#endif /* BruteForceSM_hpp */
