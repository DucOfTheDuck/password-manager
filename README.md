# Password Manager

Bienvenue dans le projet **Password Manager** ! Ce projet est un gestionnaire de mots de passe simple en C qui permet de générer, enregistrer et récupérer des mots de passe de manière (plus ou moins) sécurisée.

C'est mon premier vrai projet en C. J'estime qu'environ 15% du code a été réalisé à l'aide d'une IA (Mistral). Je commence en C, donc je fais sûrement des erreurs, mais merci de ne pas trash bêtement. Ce n'est pas un outil que je recommande fortement pour sa sécurité, mais c'est surtout sympa pour moi d'afficher ce que je code !

## Table des matières

- [Introduction](#introduction)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)

## Introduction

Le **Password Manager** est un outil en ligne de commande qui permet de générer des mots de passe aléatoires, de les enregistrer de manière sécurisée (chiffrés) et de les récupérer lorsque nécessaire. Il utilise le chiffrement AES pour sécuriser les mots de passe et le codage en base64 pour le stockage.

## Fonctionnalités

- Génération de mots de passe aléatoires.
- Enregistrement des mots de passe de manière sécurisée.
- Récupération des mots de passe enregistrés.
- Affichage de la liste des noms des mots de passe enregistrés.

## Installation

Pour compiler et exécuter le projet, suivez ces étapes :

1. **Installer les dépendances** :
   - Assurez-vous que les bibliothèques OpenSSL sont installées sur votre système.
     - **Ubuntu/Debian** :
       ```sh
       sudo apt-get install libssl-dev
       ```
     - **Fedora** :
       ```sh
       sudo dnf install openssl-devel
       ```
     - **Arch Linux** :
       ```sh
       sudo pacman -S openssl
       ```
     - **CentOS/RHEL** :
       ```sh
       sudo yum install openssl-devel
       ```
     - **macOS** :
       ```sh
       brew install openssl
       ```

2. **Cloner le dépôt** :
   ```sh
   git clone https://github.com/DucOfTheDuck/password-manager.git
   cd password-manager
   ```

3. **Générer le fichier `key.txt`** :
   - Le fichier `key.txt` contient la clé de chiffrement utilisée pour chiffrer et déchiffrer les mots de passe.
   - Vous pouvez générer une clé aléatoire en utilisant `openssl` :
     ```sh
     openssl rand -base64 16 > data/key.txt
     ```

4. **Compiler le projet** :
   ```sh
   gcc -o password_manager src/main.c src/encryption.c src/password_generator.c src/password_manager.c -Iinclude -lssl -lcrypto
   ```

5. **Exécuter le projet** :
   ```sh
   ./password_manager
   ```

## Utilisation

1. **Générer un mot de passe** :
   - Sélectionnez l'option `1` pour générer un mot de passe.
   - Entrez un nom pour le mot de passe.

2. **Récupérer un mot de passe** :
   - Sélectionnez l'option `2` pour récupérer un mot de passe.
   - La liste des noms des mots de passe enregistrés sera affichée.
   - Entrez le nom du mot de passe que vous souhaitez récupérer.





(Ce message est inclus dans les 15% de Mistral.)