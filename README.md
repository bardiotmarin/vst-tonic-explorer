# 🎹 VST Tonic Explorer & Drone Generator

Ce projet est un prototype de plugin VST (basé sur le framework JUCE) conçu pour aider les producteurs sur Ableton (et autres DAW) à :
1. **Identifier la Tonique** : Analyse en temps réel du MIDI entrant pour déterminer la note fondamentale.
2. **Générer des Drones** : Crée un tapis sonore (drone) accordé sur la tonique détectée pour "ancrer" le morceau.
3. **Suggérer des Évolutions** : Utilise la **Roue de Camelot** (Circle of Fifths) pour proposer des changements de tonalité harmonieux.

## 🚀 Fonctionnalités
- **Analyse MIDI Temps-réel** : Histogramme pondéré des notes jouées pour déduire la tonalité.
- **Camelot Wheel Interactive** : Interface visuelle pour cliquer et moduler vers les tonalités voisines (Dominante, Sous-dominante, Relative).
- **Drone Engine** : Oscillateur simple (Saw/Sine) avec filtrage qui suit la tonique.
- **Chord Assistant** : Suggestions d'accords basés sur la nouvelle tonalité sélectionnée.

## 🛠️ Installation & Build
Ce projet nécessite [JUCE](https://juce.com/).

1. Clonez ce repo.
2. Ouvrez Projucer et créez un nouveau projet "Audio Plug-in".
3. Copiez les fichiers du dossier `Source` de ce repo dans votre projet JUCE.
4. Compilez pour votre OS (VST3 / AU).

## 💡 Idées de Features Futures
- **Arpégiateur Adaptatif** : Génère des motifs rythmiques basés sur la tonalité cible.
- **Mood Selector** : Choisir une "vibe" (Triste, Énergique) qui force le choix sur la roue de Camelot.
- **MIDI Drag & Drop** : Glisser la progression d'accords générée directement dans le piano roll.

---
*Créé pour l'exploration harmonique et la production de musique électronique.*
