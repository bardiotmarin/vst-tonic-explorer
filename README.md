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
- **Custom Rotaries** : Potentiomètres circulaires avec effet de halo lumineux.

## 🚀 Fonctionnalités
- **Analyse MIDI Temps-réel** : Histogramme pondéré des notes jouées pour déduire la tonalité.
- **Camelot Wheel Interactive** : Interface visuelle pour cliquer et moduler vers les tonalités voisines (Dominante, Sous-dominante, Relative).
- **Drone Engine** : Oscillateur simple (Saw/Sine) avec filtrage qui suit la tonique.
- **Chord Assistant** : Suggestions d'accords basés sur la nouvelle tonalité sélectionnée.
- **MIDI Drag & Drop** : Glisse un fichier MIDI directement sur le plugin pour analyse instantanée de la tonique.
- **Track Recognition** : Option pour sélectionner directement une piste MIDI dans le DAW (nécessite l'API host).

## 🛠️ Installation & Build
Ce projet nécessite [JUCE](https://juce.com/).

1. Clonez ce repo.
2. Ouvrez Projucer et créez un nouveau projet "Audio Plug-in".
3. Copiez les fichiers du dossier `Source` de ce repo dans votre projet JUCE.
4. Compilez pour votre OS (VST3 / AU).

## 💡 Idées de Features Futures
- **Arpégiateur Adaptatif** : Génère des motifs rythmiques basés sur la tonalité cible.
- **Mood Selector** : Choisir une "vibe" (Triste, Énergique) qui force le choix sur la roue de Camelot.
- **MIDI Export** : Exporter la progression d'accords générée en fichier MIDI.
- **Animation Temps-réel** : Les poissons lumineux se déplacent en fonction de l'intensité MIDI.
- **Bassline Generator** : Un arpégiateur lent qui joue la fondamentale et la quinte.

---
*Créé pour l'exploration harmonique et la production de musique électronique.*
**Crédits : M4RIN AND Find The Rosee**
