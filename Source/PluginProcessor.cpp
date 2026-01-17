/*
  ==============================================================================

    PluginProcessor.cpp
    Created: 17 Jan 2026
    Author:  M4RIN AND Find The Rosee

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VstTonicExplorerAudioProcessor::VstTonicExplorerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

VstTonicExplorerAudioProcessor::~VstTonicExplorerAudioProcessor()
{
}

//==============================================================================
const juce::String VstTonicExplorerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VstTonicExplorerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VstTonicExplorerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool VstTonicExplorerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double VstTonicExplorerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VstTonicExplorerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int VstTonicExplorerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VstTonicExplorerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String VstTonicExplorerAudioProcessor::getProgramName (int index)
{
    return {};
}

void VstTonicExplorerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void VstTonicExplorerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void VstTonicExplorerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VstTonicExplorerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void VstTonicExplorerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // 1. ANALYZE MIDI FOR TONIC
    tonicAnalyzer.processMidi(midiMessages);
    
    // TODO: Use GenreManager and CamelotNavigator to generate audio or MIDI
}

//==============================================================================
bool VstTonicExplorerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* VstTonicExplorerAudioProcessor::createEditor()
{
    return new VstTonicExplorerAudioProcessorEditor (*this);
}

//==============================================================================
void VstTonicExplorerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries
}

void VstTonicExplorerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VstTonicExplorerAudioProcessor();
}
