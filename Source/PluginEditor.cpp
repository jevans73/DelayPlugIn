/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayPluginAudioProcessorEditor::DelayPluginAudioProcessorEditor (DelayPluginAudioProcessor& p, AudioProcessorValueTreeState& vts)
: AudioProcessorEditor (&p), valueTreeState(vts), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    
    // set background image
    //Background1 = ImageCache::getFromMemory(BinaryData::Background1, BinaryData::Background1Size);
    Background2 = ImageCache::getFromMemory(BinaryData::Background2, BinaryData::Background2Size);
    
    setSize (400, 300); // set the size of the plugin window
    //setResizable (true, true); // makes the window resizable
    //setResizeLimits (400, 300, 450, 350); // sets the limits of resize
    
//==============================================================================
    
    // gain slider and attachment
    gainSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // set the style of slider
    gainSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::crimson); // set the colour of the slider
    gainSlider.setColour(Slider::ColourIds::thumbColourId, Colours::white); // set the colour of the slider thumb
    
    gainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 12); // creates textbox below the slider
    gainSlider.setNumDecimalPlacesToDisplay(2);
    gainSlider.setTextValueSuffix("%"); // shows value as a percentage
    gainSlider.setColour(Slider::ColourIds::textBoxBackgroundColourId, Colours::transparentBlack); // set the colour of the textbox background
    gainSlider.setColour(Slider::ColourIds::textBoxOutlineColourId, Colours::transparentBlack); // makes textbox outline transparent
    gainSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::crimson);
    
    addAndMakeVisible(gainSlider); // makes slider visible
   
    // creates label and centres to top
    gainLabel.setText ("Gain", dontSendNotification);
    gainLabel.setColour(Label::ColourIds::textColourId, Colours::white);
    gainLabel.setJustificationType(Justification::centredTop);
    
    addAndMakeVisible (gainLabel); // makes label visible
    
     gainAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "gainparam", gainSlider)); // attaches slider to plugin processor

//==============================================================================
    
    // time slider and attachment
    timeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // set the style of the slider
    timeSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::crimson); // set the colour of the slider
    timeSlider.setColour(Slider::ColourIds::thumbColourId, Colours::white); // set the colour of the slider thumb
    
    timeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 12); // creates textbox below the slider
    timeSlider.setNumDecimalPlacesToDisplay(2);
    timeSlider.setTextValueSuffix("ms"); // shows value as a measurement of time (milliseconds)
    timeSlider.setColour(Slider::ColourIds::textBoxBackgroundColourId, Colours::transparentBlack); // set the colour of the textbox background
    timeSlider.setColour(Slider::ColourIds::textBoxOutlineColourId, Colours::transparentBlack); // makes textbox outline transparent
    timeSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::crimson);
    
    addAndMakeVisible(timeSlider); // makes slider visible
    
    // creates label and centres to top
    timeLabel.setText ("Time", dontSendNotification);
    timeLabel.setColour(Label::ColourIds::textColourId, Colours::white);
    timeLabel.setJustificationType(Justification::centredTop);
    
    addAndMakeVisible (timeLabel); // makes label visible
    
    timeAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "timeparam", timeSlider)); // attaches slider to plugin processor
    
//==============================================================================
    
    // feedback slider and attachment
    feedbackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // set the style of the slider
    feedbackSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::crimson); // set the colour of the slider
    feedbackSlider.setColour(Slider::ColourIds::thumbColourId, Colours::white); // set the colour of the slider thumb
    
    feedbackSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 12); // creates textbox below the slider
    feedbackSlider.setNumDecimalPlacesToDisplay(2);
    feedbackSlider.setTextValueSuffix("%"); // shows value as a percentage
    feedbackSlider.setColour(Slider::ColourIds::textBoxBackgroundColourId, Colours::transparentBlack); // set the colour of the textbox background
    feedbackSlider.setColour(Slider::ColourIds::textBoxOutlineColourId, Colours::transparentBlack); // makes textbox outline transparent
    feedbackSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::crimson);
    
    addAndMakeVisible(feedbackSlider); // makes slider visible
    
    // creates label and centres to top
    feedbackLabel.setText ("Feedback", dontSendNotification);
    feedbackLabel.setColour(Label::ColourIds::textColourId, Colours::white);
    feedbackLabel.setJustificationType(Justification::centredTop);
    
    addAndMakeVisible (feedbackLabel); // makes label visible
    
    feedbackAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "feedbackparam", feedbackSlider)); // attaches slider to the plugin processor
}

DelayPluginAudioProcessorEditor::~DelayPluginAudioProcessorEditor()
{
}

//==============================================================================
void DelayPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    g.drawImageWithin(Background2, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination); // fills background with chosen image
    
    g.setColour (Colours::white);
    g.setFont (Font ("Menlo", 17.5f, Font::bold)); // sets font and size
    g.drawFittedText ("D  E  L  A  Y  P L U G I N", getLocalBounds(), Justification::centredTop, 1);

    //g.setColour (Colours::white);
    //g.setFont (Font ("Menlo", 7.5f, Font::plain));
    //g.drawFittedText ("", getLocalBounds(), Justification::centredBottom, 1);
}

void DelayPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    auto r = getLocalBounds();
    
    auto leftSection = r.removeFromLeft(getWidth()/3);
    auto rightSection = r.removeFromRight(getWidth()/3);
    
    //====================================================================================
    gainSlider.setBounds(leftSection.removeFromTop(getHeight()*0.8f).reduced(15.0f));
    gainLabel.setBounds(leftSection);
    gainLabel.setFont(Font("Menlo", 15.0f, Font::plain)); // sets font and size
    //====================================================================================
    timeSlider.setBounds(r.removeFromTop(getHeight()*0.6f).reduced(15.0f));
    timeLabel.setBounds(r);
    timeLabel.setFont(Font("Menlo", 15.0f, Font::plain)); // sets font and size
    //====================================================================================
    feedbackSlider.setBounds(rightSection.removeFromTop(getHeight()*0.8f).reduced(15.0f));
    feedbackLabel.setBounds(rightSection);
    feedbackLabel.setFont(Font("Menlo", 15.0f, Font::plain)); // sets font and size
    //====================================================================================

}
