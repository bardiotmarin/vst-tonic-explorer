/*
  ==============================================================================

    PluginEditor.cpp
    Created: 17 Jan 2026
    Author:  M4RIN AND Find The Rosee

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VstTonicExplorerAudioProcessorEditor::VstTonicExplorerAudioProcessorEditor (VstTonicExplorerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setLookAndFeel(&deepWaterLook);
    
    // Title Label
    titleLabel.setText("VST TONIC EXPLORER", juce::dontSendNotification);
    titleLabel.setFont(juce::Font(28.0f, juce::Font::bold));
    titleLabel.setColour(juce::Label::textColourId, juce::Colour(0xff00ffff));
    titleLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(titleLabel);
    
    // Credits Label
    creditsLabel.setText("by M4RIN AND Find The Rosee", juce::dontSendNotification);
    creditsLabel.setFont(juce::Font(12.0f, juce::Font::italic));
    creditsLabel.setColour(juce::Label::textColourId, juce::Colour(0xff88ccee).withAlpha(0.7f));
    creditsLabel.setJustificationType(juce::Justification::centredRight);
    addAndMakeVisible(creditsLabel);
    
    // Drop Zone Label
    dropZoneLabel.setText("DROP MIDI HERE \u2b07\ufe0f", juce::dontSendNotification);
    dropZoneLabel.setFont(juce::Font(18.0f, juce::Font::plain));
    dropZoneLabel.setColour(juce::Label::textColourId, juce::Colour(0xff00ffaa).withAlpha(0.5f));
    dropZoneLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(dropZoneLabel);

    setSize (600, 500);
}

VstTonicExplorerAudioProcessorEditor::~VstTonicExplorerAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void VstTonicExplorerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Deep Water Background Gradient
    g.fillAll(juce::Colour(0xff05101a));
    
    juce::ColourGradient gradient(
        juce::Colour(0xff001a33), getWidth() / 2.0f, 0.0f,
        juce::Colour(0xff05101a), getWidth() / 2.0f, (float)getHeight(),
        false);
    g.setGradientFill(gradient);
    g.fillAll();
    
    // Bioluminescent "Fish" Orbs Animation Placeholder
    g.setColour(juce::Colour(0xff00ffff).withAlpha(0.3f));
    
    // Random fish-like glow spots (static for simplicity)
    for (int i = 0; i < 8; ++i)
    {
        float x = 50.0f + i * 70.0f;
        float y = 100.0f + (i % 3) * 100.0f;
        float size = 15.0f + (i % 2) * 10.0f;
        
        // Glowing orb
        juce::ColourGradient orbGlow(
            juce::Colour(0xff00ffff).withAlpha(0.8f), x, y,
            juce::Colour(0xff00ffff).withAlpha(0.0f), x, y - size * 2, true);
        g.setGradientFill(orbGlow);
        g.fillEllipse(x - size / 2, y - size / 2, size, size);
    }
    
    // Decorative Scanlines
    g.setColour(juce::Colour(0xff00ffff).withAlpha(0.05f));
    for (int line = 0; line < getHeight(); line += 4)
    {
        g.drawLine(0.0f, (float)line, (float)getWidth(), (float)line, 1.0f);
    }
}

void VstTonicExplorerAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    
    titleLabel.setBounds(area.removeFromTop(60).reduced(20));
    creditsLabel.setBounds(area.removeFromBottom(30).reduced(20, 5));
    
    // Drop Zone in center
    auto dropArea = area.reduced(80);
    dropZoneLabel.setBounds(dropArea.withSizeKeepingCentre(300, 80));
}

//==============================================================================
// Drag and Drop Implementation
bool VstTonicExplorerAudioProcessorEditor::isInterestedInFileDrag (const juce::StringArray& files)
{
    for (auto& file : files)
    {
        if (file.endsWith(".mid") || file.endsWith(".midi"))
            return true;
    }
    return false;
}

void VstTonicExplorerAudioProcessorEditor::filesDropped (const juce::StringArray& files, int x, int y)
{
    for (auto& file : files)
    {
        if (file.endsWith(".mid") || file.endsWith(".midi"))
        {
            juce::File midiFile(file);
            // TODO: Parse MIDI file and analyze with TonicAnalyzer
            // Send result to processor or update UI
            
            juce::AlertWindow::showMessageBoxAsync(
                juce::AlertWindow::InfoIcon,
                "MIDI Detected",
                "File: " + midiFile.getFileName() + "\n\nTonic analysis will be processed.",
                "OK");
        }
    }
}
