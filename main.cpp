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

  std::string file_Content;

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
        printContentsOfFile(fin, date_FileName, file_Content);
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
      dateInput(date_FileName);

      editWorkoutChoice(editChoice);

      switch (editChoice)
      {
      case 1:
        // append exercise to file
        std::cout << "Updating " << date_FileName << " ..." << std::endl;
        fout.open(date_FileName + ".txt", std::ios::app);
        printContentsOfFile(fin, date_FileName, file_Content);

        if (fout.is_open())
        {
          workoutInput(fout, workoutName, numExercises, exerciseName, sets, reps, weight);
          std::cout << date_FileName << " successfully updated." << std::endl;
          printContentsOfFile(fin, date_FileName, file_Content);
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

      case 0:
        std::cout << "+-----------------------+" << std::endl;
        std::cout << "| Returning to dashboard. |" << std::endl;
        std::cout << "+-----------------------+" << std::endl;
        break;
      default:
        std::cerr << "Invalid choice." << std::endl;
        break;
      }

    case 4:
      dateInput(date_FileName);
      std::cout << "+-----------------------+" << std::endl;
      std::cout << "Deleting the file ..." << std::endl;
      std::cout << "+-----------------------+" << std::endl;
      date_FileName += ".txt";
      if (std::remove(date_FileName.c_str()) == 0)
      {
        std::cout << "File successfully deleted.\n";
      }
      else
      {
        std::cerr << "Error deleting the file.\n";
      }

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
  fin.close();
  fout.close();
  return 0;
}
