#include "BitReducer.h"

BitReducer::BitReducer()
{
    
}
BitReducer::~BitReducer()
{
}


void BitReducer::bitReducerProcess (float* audioIn, float* audioOut, int bitReductionIn, int numSamplesIn)
{
    if(bitReductionIn > 1)
    {
        for (int i = 0; i < numSamplesIn; i++)
        {
            if( i % bitReductionIn != 0)
            {
                audioOut[i] = (audioIn[i - i % bitReductionIn]) * 2;
            }
        }
    }
}

