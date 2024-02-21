# PokedexGame
This project is a simple auto battler game made in QT using C++.
## Table of contents
* [Introduction](#introduction)
* [Functionalities](#functionalities)
## Introduction
This project was a homework for my Object-Oriented C++ Programming course on the college. We had to make a simple game using C++ and Qt, in which we had to implement a few features of Object-Oriented Programming. I always loved Pokemon series, so I have chosen to make game based on it. Core of the game are Pokemons, each of which has separate statistics. It has a simple gameplay, where you pick your Pokemons that will be part of your team and then you pick your enemy. Every opponent has different Pokemons with different statistics. Then you move on to the fight screen itself. You can't control your allies. Pokemons fight on their own and you can only watch the process. There is also Pokedex, where you can check your favorite Pokemon's statistics, types and a short description.
## Functionalities

### 1.Pokedex
 - Pokemons data are loaded from binary file and afterwards loaded into labels in interface
 - User can check statistics, types and description of every single Pokemon in PokedexGame
### 2.Choosing your team
- There are two modes available at the moment, three or six team slots variants
- They are accessible by changing command line argument to 3 or 6
- User can choose up to 3/6 (depending on chosen mode) Pokemons that will be part of your team during battle
- User's team is saved in binary file, so the program remembers user choices and will load them when you start the program again
### 3.Chosing enemy
- User can choose one of three available opponents, each of them has a different team
- If user does not select any opponent, there is a special "basic" opponent that will be chosen
### 4.Comparing statistics
- User can compare one of three statistics of two Pokemons chosen by the user
### 5.Quick check of Pokemon's statistics
- User can quickly check statistics of chosen Pokemon without the need of going to Pokedex.
### 6.Battle
- User does not have control over the course of the battle
- Which team goes first is determined by the speed stat of the first Pokemon
- Battle lasts until one of the players has no Pokemons left
- Pokemons attack alternately
- Damage formula is made on template which helps in quick changes in code, e.g. if user wants statistics with decimal points
- User can watch the course of the battle by updated HP bars and text log, where every single action is recorded

