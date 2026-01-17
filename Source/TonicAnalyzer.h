/*
  ==============================================================================

    TonicAnalyzer.h
    Created: 17 Jan 2026
    Author:  VstTonicExplorer AI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <array>
#include <vector>

class TonicAnalyzer
{
public:
    TonicAnalyzer()
    {
        noteHistogram.fill(0.0f);
    }

    void processMidi(const juce::MidiBuffer& buffer)
    {
        for (const auto metadata : buffer)
        {
            auto msg = metadata.getMessage();
            if (msg.isNoteOn())
            {
                int note = msg.getNoteNumber() % 12;
                noteHistogram[note] += 1.0f; // Add weight
            }
        }
        
        // Simple decay to adapt to key changes over time
        for (auto& weight : noteHistogram)
        {
            weight *= 0.999f; 
        }
    }

    int getEstimatedTonic() const
    {
        int bestNote = -1;
        float maxWeight = -1.0f;

        for (int i = 0; i < 12; ++i)
        {
            if (noteHistogram[i] > maxWeight)
            {
                maxWeight = noteHistogram[i];
                bestNote = i;
            }
        }
        return bestNote;
    }

    juce::String getNoteName(int noteIndex) const
    {
        const std::vector<juce::String> names = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
        if (noteIndex >= 0 && noteIndex < 12)
            return names[noteIndex];
        return "Unknown";
    }

private:
    std::array<float, 12> noteHistogram;
};
