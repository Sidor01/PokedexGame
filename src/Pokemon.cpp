#include "Pokemon.h"

Pokemon::Pokemon() {
    name = "";
    attack = 0;
    speed = 0;
    health = 0;
    type = "";
    secondType = "";
    description = "";
}
Pokemon::Pokemon(string inputName, int inputAttack, int inputSpeed, int inputHealth,
                 QString inputType, QString inputDescription) {
    name = inputName;
    attack = inputAttack;
    speed = inputSpeed;
    health = inputHealth;
    type = inputType;
    secondType = "";
    description = inputDescription;
}

Pokemon::Pokemon(string inputName, int inputAttack, int inputSpeed, int inputHealth,
                 QString inputType, QString inputSecondType, QString inputDescription) {
    name = inputName;
    attack = inputAttack;
    speed = inputSpeed;
    health = inputHealth;
    type = inputType;
    secondType = inputSecondType;
    description = inputDescription;
}

Pokemon::Pokemon(const Pokemon &otherPokemon) {
    name = otherPokemon.name;
    attack = otherPokemon.attack;
    speed = otherPokemon.speed;
    health = otherPokemon.health;
    type = otherPokemon.type;
    secondType = otherPokemon.secondType;
    description = otherPokemon.description;
}

void Pokemon::setName(string value)
{
    name = value;
}

void Pokemon::setAttack(int value)
{
    attack = value;
}

void Pokemon::setSpeed(int value)
{
    speed = value;
}

void Pokemon::setHealth(int value)
{
    health = value;
}

void Pokemon::setType(QString firstInputType)
{
    type = firstInputType;
}

void Pokemon::setType(QString firstInputType, QString secondInputType) {
    type = firstInputType;
    secondType = secondInputType;
}

void Pokemon::setDescription(QString inputDescription)
{
    description = inputDescription;
}

string Pokemon::getName()
{
    return name;
}

int Pokemon::getAttack()
{
    return attack;
}

int Pokemon::getSpeed()
{
    return speed;
}

int Pokemon::getHealth()
{
    return health;
}

QString Pokemon::getFirstType()
{
    return type;
}

QString Pokemon::getSecondType()
{
    return secondType;
}

QString Pokemon::getDescription()
{
    return description;
}

bool Pokemon::operator==(string temp)
{
    return this->name == temp;

}
