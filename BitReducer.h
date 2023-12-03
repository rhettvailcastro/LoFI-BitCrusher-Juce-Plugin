
#pragma once


class BitReducer
{
public:
    BitReducer();
    ~BitReducer();
    

    void bitReducerProcess(float* audioIn, float* audio, int bitReductionIn, int numSamplesIn);
    
};
