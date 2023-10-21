// Input Function
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

void inputWorkout(std::string &workoutName, std::string &exerciseName, int &sets, int &reps, double &weight)
{

    std::cout << "Enter Workout Name: ";
    std::cin.ignore();
    std::getline(std::cin, workoutName);

    std::cout << "Input Exercise name: ";
    std::getline(std::cin, exerciseName);

    std::cout << "Input Number of Sets: ";
    std::cin >> sets;

    std::cout << "Input Number of Reps: ";
    std::cin >> reps;

    std::cout << "Input weight in kg: ";
    std::cin >> weight;
}

#endif
