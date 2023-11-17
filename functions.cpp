#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"

void greet()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "+ Welcome to Personal Workout Tracker +" << std::endl;
    std::cout << "****************************************" << std::endl;
}

void inputWorkoutfromUser(std::string &workoutName, int &sets)
{
    std::cout << "Enter Workout Name: ";
    std::cin.ignore();
    std::getline(std::cin, workoutName);

    std::cout << "Input Number of Sets: ";
    std::cin >> sets;
}

void writeToStream(std::ofstream &file, const std::string &label, const std::string &value)
{
    file << label << " " << value << std::endl;
}

void writeToStream(std::ofstream &file, const std::string &label, int value)
{
    file << label << " " << value << std::endl;
}

int dashboard(int &func_choice)
{
    std::cout << "Choose from the following options to continue." << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|\t1. Add a Workout.\t\t   |" << std::endl;
    std::cout << "|\t2. Add a Rest Day.\t\t   |" << std::endl;
    std::cout << "|\t3. Edit a Workout.\t\t   |" << std::endl;
    std::cout << "|\t4. Delete a Workout or Rest Day.   |" << std::endl;
    std::cout << "|\t0. Exit the program.\t\t   |" << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "Select an option (0-4): ";
    std::cin >> func_choice;
    std::cin.ignore();
    return func_choice;
}

int editWorkoutChoice(int &choice)
{
    std::cout << "Choose from the following options to continue." << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|\t1. Add exercise(s).\t\t  |" << std::endl;
    std::cout << "|\t2. Edit exercise(s).\t\t  |" << std::endl;
    std::cout << "|\t3. Delete exercise(s).\t\t  |" << std::endl;
    std::cout << "|\t0. Return to dashboard.\t\t  |" << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "Select an option (0-3): ";
    std::cin >> choice;
    return choice;
}

void dateInput(std::string &date_FileName)
{
    std::cout << "Enter date (dd-mm-yy): ";
    std::getline(std::cin, date_FileName);
}

void workoutInput(std::ofstream &fout, std::string &workoutName, int &numExercises, std::string &exerciseName, int &sets, int &reps, double &weight)
{
    writeToStream(fout, "Workout Name:", workoutName);
    std::cout << "How many exercises would you like to save: ";
    std::cin >> numExercises;
    for (int i = 1; i <= numExercises; i++)
    {
        std::cout << "Enter name of exercise no. " << i << ": ";
        std::cin.ignore();
        std::getline(std::cin, exerciseName);

        std::cout << "Enter no. of sets: ";
        std::cin >> sets;

        writeToStream(fout, "Exercise Name:", exerciseName);
        writeToStream(fout, "Sets:", sets);
        for (int j = 1; j <= sets; j++)
        {
            std::cout << "Set no. " << j << " reps: ";
            std::cin >> reps;
            fout << "Set no. " << j << " reps: " << std::endl;
            std::cout << "Weight on set no. " << j << ": ";
            std::cin >> weight;
            fout << "Weight on set no. " << j << ": " << weight << std::endl;
        }
    }
}

void restDayNote(std::ofstream &fout, std::string &date_FileName, char &noteChoice)
{
    if (noteChoice == 'y' || noteChoice == 'Y')
    {
        std::cout << "Adding a note ..." << std::endl;
        std::string restDayNote;
        std::cout << "Note: ";
        std::cin.ignore();
        std::getline(std::cin, restDayNote);
        fout << restDayNote;
        std::cout << "Note added to rest day " << date_FileName << " ." << std::endl;
    }

    else if (noteChoice == 'n' || noteChoice == 'N')
    {
        std::cout << "Did not added a note and the rest day is saved." << std::endl;
    }
}

int editExercise(int &user_choice)
{
    std::cout << "Choose from the following" << std::endl;
    std::cout << "1. Change the name of the exercise." << std::endl;
    std::cout << "2. Edit sets." << std::endl;
    std::cout << "3. Edit reps." << std::endl;
    std::cout << "4. Edit weight." << std::endl;
    std::cout << "0. Return to dashboard." << std::endl;
    std::cin >> user_choice;
    return user_choice;
}