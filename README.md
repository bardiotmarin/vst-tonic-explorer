# 🎹 VST Tonic Explorer & Drone Generator

**By M4RIN AND Find The Rosee**

Ce projet est un prototype de plugin VST (basé sur le framework JUCE) conçu pour aider les producteurs sur Ableton (et autres DAW) à :
1. **Identifier la Tonique** : Analyse en temps réel du MIDI entrant pour déterminer la note fondamentale.
2. **Générer des Drones** : Crée un tapis sonore (drone) accordé sur la tonique détectée pour "ancrer" le morceau.
3. **Suggérer des Évolutions** : Utilise la **Roue de Camelot** (Circle of Fifths) pour proposer des changements de tonalité harmonieux.

## 🌊✨ Interface Futuriste : Deep Water & Neon Glow
L'interface graphique (UI) plonge l'utilisateur dans un environnement sous-marin bioluminescent :
- **Couleurs** : Dégradé bleu profond (Deep Water) avec des néons cyan/turquoise.
- **Effets visuels** : Particules lumineuses simulant des poissons des abysses (Neon Glow Fish).
- **Scanlines** : Lignes horizontales subtiles pour un rendu cyberpunk/synthwave.

## 🔥 NOUVEAU : Massive Genre Engine
Le plugin intègre maintenant une bibliothèque de presets spécialisés pour les producteurs de musique électronique moderne :

### 🏭 Techno (Berlin Rumble)
- **Presets** : "Berlin Warehouse", "Hypnotic Loop"
- **Tech** : Générateur de Sub-Rumble avec Reverb filtrée
- **Scale** : Phrygian mode par défaut pour cette touche sombre

### 🏠 House / Classic
- **Presets** : "NY Garage Stabs"
- **Tech** : Accords Mineur 7th et 9th automatiques
- **Rhythm** : Swing classique 1/16th

### 🌴 Afro House
- **Presets** : "Savanna Poly"
- **Tech** : Polyrythmies 3-3-2 et basses "Log Drum"
- **Scale** : Dorian / Minor 6th pour la profondeur

### 🌌 Melodic House (Afterlife Style)
- **Presets** : "Ethereal Arp"
- **Tech** : Arpégiateurs fluides et nappes (Pads) évolutives
- **Vibe** : Émotionnel et planant

### 🔊 Bass House
- **Presets** : "UK Bass Wobble"
- **Tech** : FM Metallic Basses et modulation agressive
- **Intervals** : Tritone tension (Diabolus in musica)

## 🚀 Formats Supportés
Grâce au framework JUCE, ce code peut être exporté dans les formats suivants (selon votre configuration) :
- **VST3** (Standard actuel)
- **Audio Unit (AU)** (Pour Logic Pro / Mac)
- **Standalone** (Application autonome)
- *VST2 (Legacy) : Possible si vous possédez l'ancien SDK Steinberg.*

## 🛠️ Installation & Build
Ce projet nécessite [JUCE](https://juce.com/).

1. Clonez ce repo.
2. Ouvrez Projucer et créez un nouveau projet "Audio Plug-in".
3. Copiez les fichiers du dossier `Source` de ce repo dans votre projet JUCE.
4. Compilez pour votre OS.

---
*Créé pour l'exploration harmonique et la production de musique électronique.*
**Crédits : M4RIN AND Find The Rosee**
