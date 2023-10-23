// Work in progress output will be saved in .txt files
#include <iostream>
#include <string>
#include <fstream>

#include "input.h"

const int MAX_SIZE = 100;

int main()
{

  char chooseDay;
  std::string date;
  std::string workoutName;
  std::string exerciseName;
  int sets;
  int reps = 0;
  double weight;
  int choice;

  // int iterations = 0;
  // const int MAX_ITERATIONS = 5;

  std::cout << "Welcome to Personal Workout Tracker" << std::endl;

  while (choice != 0)
  {
    std::cout << "Choose from the following options to continue." << std::endl;
    std::cout << "1. Add a Workout." << std::endl;
    std::cout << "2. Add a Rest Day." << std::endl;
    std::cout << "3. Edit a Workout." << std::endl;
    std::cout << "4. Delete a Workout or Rest Day." << std::endl;
    std::cout << "0. Exit the program." << std::endl;
    std::cout << "Select an option (0-4): ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:
      std::cout << "Adding a Workout ..." << std::endl;
      std::cout << "Enter date (dd/mm/yy): ";
      std::cin >> date;
      inputWorkout(workoutName, exerciseName, sets, reps, weight);
      std::cout << "Workout saved." << std::endl;
      break;

    case 2:
      std::cout << "Adding a Rest day ..." << std::endl;
      std::cout << "Enter date (dd/mm/yy): ";
      std::cin >> date;
      std::cout << "Rest Day saved." << std::endl;
      break;

    case 3:
    std::cout << "Editing a workout ..." << std::endl;
    std::cout << "Enter date of the workout (dd/mm/yy): ";
    std::cin >> date;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Add an exercise." << std::endl;
    std::cout << "2. Edit an exercise." << std::endl;
    std::cout << "3. Delete an exercise." << std::endl;
    std::cout << "0. Return to options." << std::endl;
    //Choice variable
    //inner switch
    //options: add exercise, edit an exercise(sets, reps, weight)


    }

    //   if (choice == 'Y' || choice == 'y')
    //   {

    //     std::cout << "Workout or Rest Day (W/R): ";
    //     std::cin >> chooseDay;
    //     std::cin.ignore();

    //     std::cout << "Enter date (dd/mm/yy): ";
    //     std::cin.ignore();
    //     std::getline(std::cin, date);

    //     if (chooseDay == 'W' || chooseDay == 'w')
    //     {

    //       inputWorkout(workoutName, exerciseName, sets, reps, weight);
    //     }
    //     else if (chooseDay == 'R' || chooseDay == 'r')
    //     {

    //       std::cout << "Rest Day Saved." << std::endl;
    //     }
    //   }
    //   else if (choice == 'N' || choice == 'n')
    //   {
    //     break;
    //   }

    //   iterations++;
    // }
  }
  return 0;
}
