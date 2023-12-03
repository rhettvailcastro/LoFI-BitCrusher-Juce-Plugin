/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LoFiBitCrusherAudioProcessorEditor::LoFiBitCrusherAudioProcessorEditor (LoFiBitCrusherAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 20);
    gainSlider.setRange (-60.0f, 20.0f, 0.01f);
    gainSlider.setValue (0.0f);
    gainSlider.addListener (this);
    addAndMakeVisible (gainSlider);
    
    addAndMakeVisible (gainLabel);
    gainLabel.setText ("Gain", juce::dontSendNotification);

    
    sampleRateReducerSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    sampleRateReducerSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    sampleRateReducerSlider.setRange (-500, 0, 5);
    sampleRateReducerSlider.setValue (0);
    sampleRateReducerSlider.addListener (this);
    addAndMakeVisible (sampleRateReducerSlider);
    
    addAndMakeVisible (sampleRateReducerLabel);
    sampleRateReducerLabel.setText ("Sample Rate ", juce::dontSendNotification);
    addAndMakeVisible (sampleRateReducerLabel2);
    sampleRateReducerLabel2.setText ("Reduction", juce::dontSendNotification);
    addAndMakeVisible (sampleRateReducerLabel3);
    sampleRateReducerLabel3.setText ("Amount", juce::dontSendNotification);
    
    bitReducerSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    getLookAndFeel().setColour(juce::Slider::LinearVertical, juce::Colours::purple);
    bitReducerSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 20);
    bitReducerSlider.setRange (0, 16, 1);
    bitReducerSlider.setValue (0);
    bitReducerSlider.addListener (this);
    addAndMakeVisible (bitReducerSlider);
    
    filterChooserSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterChooserSlider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    filterChooserSlider.setRange (0, 1, 1);
    filterChooserSlider.setValue (0);
    filterChooserSlider.addListener (this);
    addAndMakeVisible (filterChooserSlider);
    
    addAndMakeVisible (bitReducerLabel);
    bitReducerLabel.setText ("Bits", juce::dontSendNotification);
    addAndMakeVisible (bitReducerLabel2);
    bitReducerLabel2.setText ("Reduced", juce::dontSendNotification);
    
    filterCutoffSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterCutoffSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 20);
    filterCutoffSlider.setRange (0, 20000, 1);
    filterCutoffSlider.setValue (20000);
    filterCutoffSlider.addListener (this);
    addAndMakeVisible (filterCutoffSlider);
    
    addAndMakeVisible (filterCutoffLabel);
    filterCutoffLabel.setText ("Low Pass", juce::dontSendNotification);
    addAndMakeVisible (filterCutoffLabel2);
    filterCutoffLabel2.setText ("Filter", juce::dontSendNotification);
    addAndMakeVisible (filterCutoffLabel3);
    filterCutoffLabel3.setText ("Cutoff", juce::dontSendNotification);
    
    addAndMakeVisible (filterChooserLabel);
    filterChooserLabel.setText ("Pre", juce::dontSendNotification);
    addAndMakeVisible (filterChooserLabel2);
    filterChooserLabel2.setText ("Post", juce::dontSendNotification);
    
    
    setSize (600, 300);
}

LoFiBitCrusherAudioProcessorEditor::~LoFiBitCrusherAudioProcessorEditor()
{
}

//==============================================================================
void LoFiBitCrusherAudioProcessorEditor::paint (juce::Graphics& g)
{
    auto myImage = juce::ImageCache::getFromMemory (BinaryData::back_png, BinaryData::back_pngSize);
    g.drawImage (myImage, getLocalBounds().toFloat());
    
   // g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    
}

void LoFiBitCrusherAudioProcessorEditor::resized()
{
    gainSlider.setBounds (20, getHeight()/2 - 80, 100, 200);
    sampleRateReducerSlider.setBounds (150, getHeight() / 2 - 80, 100, 200);
    bitReducerSlider.setBounds (280, getHeight() / 2 - 80, 100, 200);
    filterCutoffSlider.setBounds (410, getHeight() / 2 - 80, 100, 200);
    filterChooserSlider.setBounds (485, getHeight() / 2 - 35, 100, 70);
    
    gainLabel.setBounds (50, 15, 50, 50);
    sampleRateReducerLabel.setBounds (159, 0, 100, 50);
    sampleRateReducerLabel2.setBounds (165, 15, 100, 50);
    sampleRateReducerLabel3.setBounds (169, 30, 100, 50);
    bitReducerLabel.setBounds (315, 10, 50, 50);
    bitReducerLabel2.setBounds (300, 25, 100, 50);
    filterCutoffLabel.setBounds (427, 2, 100, 50);
    filterCutoffLabel2.setBounds (438, 17, 100, 50);
    filterCutoffLabel3.setBounds (434, 32, 100, 50);
    filterChooserLabel.setBounds (520, 85, 100, 50);
    filterChooserLabel2.setBounds (515, 162, 100, 50);
}

void LoFiBitCrusherAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.gain = gainSlider.getValue();
    }
    if (slider == &sampleRateReducerSlider)
    {
        audioProcessor.reductionRate = sampleRateReducerSlider.getValue();
    }
    if (slider == &bitReducerSlider)
    {
        audioProcessor.bitReductionAmount = bitReducerSlider.getValue();
    }
    if (slider == &filterCutoffSlider)
    {
        audioProcessor.lowPassFilterCutoff = filterCutoffSlider.getValue();
    }
    if (slider == &filterChooserSlider)
    {
        audioProcessor.lowPassChooser = filterChooserSlider.getValue();
    }
}
