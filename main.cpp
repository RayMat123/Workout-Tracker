// Work in progress output will be saved in .txt files
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "functions.h"

int main()
{

  std::string chooseDay;
  std::string date_FileName;
  std::string workoutName;
  std::string exerciseName;
  int sets = 0;
  int reps = 0;
  double weight = 0.0;
  int choice = -1;
  int numExercises = 0;

  std::string tempPrint;

  std::ofstream fout;
  std::ifstream fin;

  greet();

  while (choice != 0)
  {

    dashboard(choice);

    switch (choice)
    {
    case 1:
      std::cout << "Adding a Workout ..." << std::endl;
      dateInput(date_FileName);

      std::cout << "Enter workout name: ";

      std::getline(std::cin, workoutName);

      // Saving workout to file
      fout.open(date_FileName + ".txt");
      if (fout.is_open())
      {

        workoutInput(fout, workoutName, numExercises, exerciseName, sets, reps, weight);

        std::cout << "Workout saved." << std::endl;
      }
      else
      {
        std::cerr << "Error creating file." << std::endl;
      }

      fout.close();

      break;

    case 2:
      std::cout << "Adding a Rest day ..." << std::endl;
      dateInput(date_FileName);

      fout.open(date_FileName + ".txt");
      if (fout.is_open())
      {
        fout << "**Rest Day**" << std::endl;
        std::cout << "Rest Day saved." << std::endl;
        std::cout << "Would you like to add a note? (y/n): ";
        char noteChoice;
        std::cin >> noteChoice;

        restDayNote(fout, date_FileName, noteChoice);
      }
      else
      {
        std::cerr << "Error opening file." << std::endl;
      }

      fout.close();

      break;
    case 3:
      int editChoice;
      std::cout << "Editing a workout ..." << std::endl;

      editWorkoutChoice(editChoice);

      switch (editChoice)
      {
      case 1:
        // append exercise to file
        std::cout << "Updating " << date_FileName << " ..." << std::endl;
        fout.open(date_FileName + ".txt", std::ios::app);

        if (fout.is_open())
        {
          workoutInput(fout, workoutName, numExercises, exerciseName, sets, reps, weight);
          std::cout << date_FileName << " successfully updated." << std::endl;
        }
        else if (!fout.is_open())
        {
          std::cout << "File not found." << std::endl;
        }
        else
        {
          std::cout << "Invalid choice." << std::endl;
        }
        fout.close();
        break;

      case 2:
        // ask if the user wants to:
        //   1. change exercise name
        //   2. edit no. of sets or reps
        //  3. edit weight
        //  4. go back to dashboard
        int user_choice;

        editExercise(user_choice);

        switch (user_choice)
        {
        case 1:
          dateInput(date_FileName);
          fin.open(date_FileName + ".txt");
          if (fin.is_open(), std::ios::in)
          {
            std::cout << "Following is the data stored in this file." << std::endl;
            std::cout << "+-------------+" << std::endl;
            while (std::getline(fin, tempPrint))
            {
              std::cout << tempPrint << "\n";
            }
            std::cout << "+-------------+" << std::endl;
          }
          else if(!fin.is_open())
          {
            std::cerr << "Error. File not found." << std::endl;
          }

          else{
            std::cerr << "Invalid choice." << std::endl;
          }
          fin.close();

          break;

        default:
          std::cout << "Invalid choice. "
                    << "\n";
          break;
        }
        break;
      }
      break;

    case 0:
      std::cout << "+-----------------------+" << std::endl;
      std::cout << "| Exiting the program. |" << std::endl;
      std::cout << "+-----------------------+" << std::endl;
      break;

    default:
      std::cerr << "Invalid choice." << std::endl;
      break;
    }
  }

  return 0;
}
