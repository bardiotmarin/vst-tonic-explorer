/*
  ==============================================================================

    PluginProcessor.h
    Created: 17 Jan 2026
    Author:  M4RIN AND Find The Rosee

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "TonicAnalyzer.h"
#include "CamelotWheel.h"
#include "GenreData.h"

//==============================================================================
class VstTonicExplorerAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    VstTonicExplorerAudioProcessor();
    ~VstTonicExplorerAudioProcessor() override;

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

    // Public accessors for the editor to visualize data
    int getCurrentTonic() const { return tonicAnalyzer.getEstimatedTonic(); }
    juce::String getCurrentGenreName() const { return currentGenreName; }

private:
    //==============================================================================
    TonicAnalyzer tonicAnalyzer;
    CamelotNavigator camelotNavigator;
    GenreManager genreManager;
    
    juce::String currentGenreName = "Init";

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstTonicExplorerAudioProcessor)
};
