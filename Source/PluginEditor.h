/*
  ==============================================================================

    PluginEditor.h
    Created: 17 Jan 2026
    Author:  M4RIN AND Find The Rosee

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
class NeonDeepWaterLookAndFeel : public juce::LookAndFeel_V4
{
public:
    NeonDeepWaterLookAndFeel()
    {
        setColour(juce::ResizableWindow::backgroundColourId, juce::Colour(0xff05101a)); // Deep dark blue
        setColour(juce::Slider::thumbColourId, juce::Colour(0xff00ffff)); // Cyan Neon
        setColour(juce::Slider::trackColourId, juce::Colour(0xff0a2a40)); 
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(0xff00e5ff)); 
        setColour(juce::Label::textColourId, juce::Colour(0xffcceeff));
    }

    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
        const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider) override
    {
        // Custom Bioluminescent Rotary
        auto radius = (float)juce::jmin(width / 2, height / 2) - 4.0f;
        auto centreX = (float)x + (float)width * 0.5f;
        auto centreY = (float)y + (float)height * 0.5f;
        auto rx = centreX - radius;
        auto ry = centreY - radius;
        auto rw = radius * 2.0f;
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

        // Glow effect
        g.setGradientFill(juce::ColourGradient(juce::Colour(0xff00ffff).withAlpha(0.6f), centreX, centreY,
                                               juce::Colour(0xff00ffff).withAlpha(0.0f), centreX, centreY - radius * 1.5f, true));
        g.fillEllipse(rx, ry, rw, rw);

        // Arc
        juce::Path p;
        p.addArc(rx, ry, rw, rw, rotaryStartAngle, angle, true);
        g.setColour(juce::Colour(0xff00ffff));
        g.strokePath(p, juce::PathStrokeType(2.5f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    }
};

class VstTonicExplorerAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::FileDragAndDropTarget
{
public:
    VstTonicExplorerAudioProcessorEditor (VstTonicExplorerAudioProcessor&);
    ~VstTonicExplorerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    // FileDragAndDropTarget methods
    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped (const juce::StringArray& files, int x, int y) override;

private:
    NeonDeepWaterLookAndFeel deepWaterLook;
    VstTonicExplorerAudioProcessor& audioProcessor;
    
    juce::Label titleLabel;
    juce::Label creditsLabel;
    juce::Label dropZoneLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstTonicExplorerAudioProcessorEditor)
};
