/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "BitReducer.h"


//==============================================================================
/**
*/
class LoFiBitCrusherAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    LoFiBitCrusherAudioProcessor();
    ~LoFiBitCrusherAudioProcessor() override;
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif
    
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    
    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const juce::String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    
    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void updateFilter();
    
    juce::AudioProcessorValueTreeState parameters;
    juce::AudioProcessorValueTreeState::ParameterLayout initializeGUI();
    
    float lowPassFilterCutoff = {200000.0f};
    float gain {0.5f};
    int reductionRate = {0};
    double sampleRateStored  = {0.0f};
    int bitReductionAmount = {0};
    int lowPassChooser = {1};
    int lastSampleRate;
    
    
private:
    juce::dsp::ProcessorDuplicator<juce::dsp::FIR::Filter <float>, juce::dsp::FIR::Coefficients <float>> lowPassFilter;

    std::unique_ptr<BitReducer> ptrBit[2];
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoFiBitCrusherAudioProcessor)
};
