/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
 */
class DelayPluginAudioProcessorEditor  : public AudioProcessorEditor //Slider::Listener
{
public:
    DelayPluginAudioProcessorEditor (DelayPluginAudioProcessor&, AudioProcessorValueTreeState&);
    ~DelayPluginAudioProcessorEditor();
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
private:
    
    // create the APVTS
    AudioProcessorValueTreeState& valueTreeState;
    
    // creating sliders and their respective labels
    Slider gainSlider;
    Label gainLabel;
    //======================
    Slider timeSlider;
    Label timeLabel;
    //======================
    Slider feedbackSlider;
    Label feedbackLabel;
    //======================
    
    // creating attachments for the APVTS
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> timeAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;
    
    // GUI background
    
    Image Background1;
    Image Background2;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DelayPluginAudioProcessor& processor;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayPluginAudioProcessorEditor)
};
