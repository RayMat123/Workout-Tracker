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

  int iterations = 0;
  const int MAX_ITERATIONS = 5;

  while (iterations < MAX_ITERATIONS)
  {

    std::cout << "Would you like to add a workout or rest day (Y/N)? ";
    char choice;
    std::cin >> choice;
    std::cin.ignore(); 

    if (choice == 'Y' || choice == 'y')
    {

      std::cout << "Workout or Rest Day (W/R): ";
      std::cin >> chooseDay;
      std::cin.ignore(); 

      std::cout << "Enter date (dd/mm/yy): ";
      std::cin.ignore(); 
      std::getline(std::cin, date);

      if (chooseDay == 'W' || chooseDay == 'w')
      {

        inputWorkout(workoutName, exerciseName, sets, reps, weight);
      }
      else if (chooseDay == 'R' || chooseDay == 'r')
      {

        std::cout << "Rest Day Saved." << std::endl;
      }
    }
    else if (choice == 'N' || choice == 'n')
    {
      break;
    }

    iterations++;
  }

  return 0;
}

