/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class LoFiBitCrusherAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                            public juce::Slider::Listener

{
public:
    LoFiBitCrusherAudioProcessorEditor (LoFiBitCrusherAudioProcessor&);
    ~LoFiBitCrusherAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override;

private:
    juce::Slider gainSlider,
                 bitReducerSlider,
                 filterCutoffSlider,
                 filterChooserSlider,
                 sampleRateReducerSlider;
    
    juce::Label gainLabel,
                filterCutoffLabel,
                filterCutoffLabel2,
                filterCutoffLabel3,
                filterChooserLabel,
                filterChooserLabel2,
                bitReducerLabel,
                bitReducerLabel2,
                sampleRateReducerLabel,
                sampleRateReducerLabel2,
                sampleRateReducerLabel3;


    

    
    LoFiBitCrusherAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoFiBitCrusherAudioProcessorEditor)
};
