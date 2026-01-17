/*
  ==============================================================================

    GenreData.h
    Created: 17 Jan 2026
    Author:  M4RIN AND Find The Rosee

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>
#include <map>

enum class GenreStyle {
    Techno,
    House,
    AfroHouse,
    MelodicHouse,
    BassHouse
};

struct GenrePreset {
    juce::String name;
    int defaultBPM;
    juce::String scaleType;      // e.g., "Phrygian", "Minor"
    std::vector<int> chordIntervals; // Intervals from root for typical chords
    std::vector<bool> rhythmPattern; // 16 steps (1 bar) of rhythmic gates
    juce::String droneType;      // "Rumble", "Sub", "Reese", "Stab"
};

class GenreManager
{
public:
    GenreManager()
    {
        initTechnoPresets();
        initHousePresets();
        initAfroPresets();
        initMelodicPresets();
        initBassHousePresets();
    }

    const std::vector<GenrePreset>& getPresetsForGenre(GenreStyle style)
    {
        return presets[style];
    }

private:
    std::map<GenreStyle, std::vector<GenrePreset>> presets;

    void initTechnoPresets()
    {
        // BERLIN RUMBLE
        presets[GenreStyle::Techno].push_back({
            "Berlin Warehouse",
            132,
            "Phrygian",
            { 0, 3, 7 }, // Minor Triad
            { 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 }, // Driving Syncopation
            "RumbleReverb" // Heavy filtered reverb kick tail
        });

        // HYPNOTIC DRONE
        presets[GenreStyle::Techno].push_back({
            "Hypnotic Loop",
            128,
            "Minor",
            { 0, 7 }, // Power Chord
            { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, // 1/8th Note Pulse
            "DarkSaw"
        });
    }

    void initHousePresets()
    {
        // CLASSIC HOUSE STABS
        presets[GenreStyle::House].push_back({
            "NY Garage Stabs",
            124,
            "MinorPentatonic",
            { 0, 3, 7, 10 }, // Minor 7th
            { 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 }, // Swing Feel
            "OrganSine"
        });
    }

    void initAfroPresets()
    {
        // AFRO POLYRHYTHM
        presets[GenreStyle::AfroHouse].push_back({
            "Savanna Poly",
            120,
            "Dorian",
            { 0, 3, 7, 9 }, // Minor 6th (Deep feel)
            { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0 }, // 3-3-2 Clave feel
            "SubLog"
        });
    }

    void initMelodicPresets()
    {
        // AFTERLIFE STYLE ARPS
        presets[GenreStyle::MelodicHouse].push_back({
            "Ethereal Arp",
            122,
            "Aeolian",
            { 0, 4, 7, 11 }, // Major 7th (Emotional)
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // Running 1/16ths
            "EvolvingPad"
        });
    }

    void initBassHousePresets()
    {
        // WUB WUB
        presets[GenreStyle::BassHouse].push_back({
            "UK Bass Wobble",
            128,
            "Chromatic",
            { 0, 6, 7 }, // Tritone tension
            { 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0 }, // Aggressive skip
            "FM_Metallic"
        });
    }
};
