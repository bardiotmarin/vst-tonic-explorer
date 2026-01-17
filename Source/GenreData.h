/*
  ==============================================================================

    GenreData.h
    Created: 17 Jan 2026
    Author:  M4RIN AND Find The Rosee
    Updated: Expanded Genre Library

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
    juce::String description;    // Added description for tooltip
    int defaultBPM;
    juce::String scaleType;      
    std::vector<int> chordIntervals; 
    std::vector<bool> rhythmPattern; 
    juce::String droneType;      
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
        // 1. BERLIN RUMBLE (Original)
        presets[GenreStyle::Techno].push_back({
            "Berlin Warehouse",
            "Deep reverb kick rumble with dark atmosphere",
            132,
            "Phrygian",
            { 0, 3, 7 }, 
            { 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 }, 
            "RumbleReverb"
        });

        // 2. PEAK TIME DRIVE (Charlotte/Amelie style)
        presets[GenreStyle::Techno].push_back({
            "Peak Time Matrix",
            "Acid 303 lines coupled with aggressive detuned saws",
            138,
            "Minor",
            { 0, 12 }, // Octave jumps
            { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 }, // Rolling 16ths
            "AcidSaw"
        });

        // 3. DUB TECHNO (Basic Channel style)
        presets[GenreStyle::Techno].push_back({
            "Echo Chord Space",
            "Heavily delayed minor chords with noise floor",
            127,
            "Minor 9th",
            { 0, 3, 7, 10, 14 }, // Minor 9th
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, // Sparse stabs
            "FilteredNoise"
        });
    }

    void initHousePresets()
    {
        // 1. NY GARAGE (Original)
        presets[GenreStyle::House].push_back({
            "NY Garage Stabs",
            "Classic M1 Organ swing",
            124,
            "MinorPentatonic",
            { 0, 3, 7, 10 }, 
            { 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 }, 
            "OrganSine"
        });

        // 2. FRENCH TOUCH (Daft/Stardust style)
        presets[GenreStyle::House].push_back({
            "Filter Disco Loop",
            "Phaser-heavy disco samples with compression pump",
            128,
            "Mixolydian",
            { 0, 4, 7, 10 }, // Dominant 7th
            { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, // Straight disco
            "FilteredDisco"
        });

        // 3. PIANO ANTHEM
        presets[GenreStyle::House].push_back({
            "Ibiza 90s Piano",
            "Bright Korg M1 Piano chords",
            126,
            "Major",
            { 0, 4, 7, 12 }, // Major Triad + Octave
            { 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }, // Syncopated
            "BrightPiano"
        });
    }

    void initAfroPresets()
    {
        // 1. SAVANNA POLY (Original)
        presets[GenreStyle::AfroHouse].push_back({
            "Savanna Poly",
            "Log drums with shaker layers",
            120,
            "Dorian",
            { 0, 3, 7, 9 }, 
            { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0 }, 
            "SubLog"
        });

        // 2. KEINE-VIBE (Keinemusik style)
        presets[GenreStyle::AfroHouse].push_back({
            "Kloudy Sunset",
            "Soft drifting pads with intricate percussion",
            118,
            "Aeolian",
            { 0, 3, 7, 15 }, // Spread voicing
            { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }, // Sparse, airy
            "AiryPad"
        });
        
        // 3. TRIBAL SOUL
        presets[GenreStyle::AfroHouse].push_back({
            "Ancestral Drum",
            "Heavy triplets and vocal chops",
            122,
            "Minor Pentatonic",
            { 0, 5, 7 }, // Fourth and Fifth emphasis
            { 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1 }, // Triplets feel
            "WoodPerc"
        });
    }

    void initMelodicPresets()
    {
        // 1. ETHEREAL ARP (Original)
        presets[GenreStyle::MelodicHouse].push_back({
            "Ethereal Arp",
            "Tale Of Us style arpeggiator",
            122,
            "Aeolian",
            { 0, 4, 7, 11 }, 
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
            "EvolvingPad"
        });

        // 2. BODZIN BASS
        presets[GenreStyle::MelodicHouse].push_back({
            "Moogish Glide",
            "Monophonic bass with heavy pitch glide automation",
            124,
            "Harmonic Minor",
            { 0, 7, 8 }, // Semitone tension (V-VI)
            { 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0 }, // Driving
            "SawGlide"
        });
        
        // 3. PROGRESSIVE PLUCK
        presets[GenreStyle::MelodicHouse].push_back({
            "Deadmau5 Chord",
            "Short percussive chords opening up on cutoff",
            128,
            "Major",
            { 0, 4, 7, 14 }, // Spread Major 9
            { 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 }, // Offbeat focus
            "PluckSynth"
        });
    }

    void initBassHousePresets()
    {
        // 1. UK BASS WOBBLE (Original)
        presets[GenreStyle::BassHouse].push_back({
            "UK Bass Wobble",
            "Filthy LFO bass",
            128,
            "Chromatic",
            { 0, 6, 7 }, 
            { 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0 }, 
            "FM_Metallic"
        });

        // 2. G-HOUSE LOW
        presets[GenreStyle::BassHouse].push_back({
            "Gangsta Low",
            "Deep sine compression with rap vocal chops",
            124,
            "Phrygian Dominant",
            { 0, 1, 4, 5 }, // Exotic tension
            { 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }, // Bouncy
            "PureSub"
        });
        
        // 3. SPEED GARAGE WARP
        presets[GenreStyle::BassHouse].push_back({
            "Speed Warper",
            "Time-stretched bass sample vibe",
            132,
            "Minor",
            { 0, 3, 5, 7 }, 
            { 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 }, // 2-step shuffle
            "ReeseBass"
        });
    }
};
