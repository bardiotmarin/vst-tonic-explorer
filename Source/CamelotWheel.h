/*
  ==============================================================================

    CamelotWheel.h
    Created: 17 Jan 2026
    Author:  VstTonicExplorer AI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <map>
#include <vector>

struct CamelotKey {
    juce::String code; // e.g., "8B"
    juce::String name; // e.g., "C Major"
    int rootNote;      // 0=C, 1=C#, etc.
    bool isMajor;
};

class CamelotNavigator
{
public:
    CamelotNavigator()
    {
        // Initialize the wheel (Simplified subset for example)
        // 8B = C Major
        keys["8B"] = { "8B", "C Major", 0, true };
        keys["8A"] = { "8A", "A Minor", 9, false }; // Relative Minor
        keys["9B"] = { "9B", "G Major", 7, true };  // Dominant (Clockwise)
        keys["7B"] = { "7B", "F Major", 5, true };  // Subdominant (Counter-Clockwise)
        // ... (Full map would go here)
    }

    std::vector<juce::String> getEvolutionOptions(juce::String currentCode)
    {
        // Logic to return neighbors: +/- 1 hour, and relative minor/major
        // Parsing the number and letter from code...
        // This is a placeholder for the full circular logic.
        return { "9B", "7B", "8A" }; 
    }

private:
    std::map<juce::String, CamelotKey> keys;
};
