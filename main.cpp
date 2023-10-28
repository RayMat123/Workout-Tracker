// Work in progress output will be saved in .txt files
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

void inputWorkout(std::string &workoutName, std::string &exerciseName, int &sets, int &reps, double &weight);

int main()
{

  std::string chooseDay;
  std::string date_FileName;
  std::string workoutName;
  std::string exerciseName;
  int sets;
  int reps = 0;
  double weight;
  int choice = -1;

  std::ofstream fout;
  std::ifstream fin;

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
      std::cout << "Enter date (dd/mm/yy) with .txt extenxion: ";
      std::cin >> date_FileName;
      inputWorkout(workoutName, exerciseName, sets, reps, weight);
      // Saving workout to file
      fout.open(date_FileName);
      if (fout.is_open())
      {
        fout << "Workout Name: ";
        fout << workoutName << std::endl;
        fout << "Exercise Name: ";
        fout << exerciseName << std::endl;
        fout << "Sets: ";
        fout << sets << std::endl;
        fout << "Reps: ";
        fout << reps << std::endl;
        fout << "Weight: ";
        fout << weight << std::endl;
        std::cout << "Workout saved." << std::endl;
        fout.close();
      }
      else
      {
        std::cout << "Error creating file." << std::endl;
      }

      break;

    case 2:
      std::cout << "Adding a Rest day ..." << std::endl;
      std::cout << "Enter date (dd/mm/yy): ";
      std::cin >> date_FileName;
      std::cout << "Rest Day saved." << std::endl;
      break;

    case 3:
      std::cout << "Editing a workout ..." << std::endl;
      std::cout << "Enter date of the workout (dd/mm/yy): ";
      std::cin >> date_FileName;
      std::cout << "What would you like to do?" << std::endl;
      std::cout << "1. Add an exercise." << std::endl;
      std::cout << "2. Edit an exercise." << std::endl;
      std::cout << "3. Delete an exercise." << std::endl;
      std::cout << "0. Return to dashboard." << std::endl;

      int editChoice;
      /*switch (editChoice)
      {
      case 1:
        // append exercise to file
      case 2:
        // ask if the user wants to:
        //   1. change exercise name
        //   2. edit no. of sets or reps
        //  3. edit weight
        //  4. go back to menu
      case 3:
        // Ask exercise name
        // Confirm if the user wants to delete the exercise
        // Delete exercise and show the workout in console and save in file
      }*/
      break;
    case 4:
      std::cout << "Enter date: ";
      std::cin >> date_FileName;
      std::cout << "Are you sure you want to delete the contents of " << date_FileName << "(y/n): ";
      char confirmChar;
      std::cin >> confirmChar;
      date_FileName += ".txt";
      if (confirmChar == 'y' || confirmChar == 'Y')
      {
        // delete file
        if (std::remove(date_FileName.c_str()) == 0)
        {
          std::cout << date_FileName << " has been succesfully deleted." << std::endl;
        }
        else
        {
          std::cout << "Error deleting file.";
        }
      }
      break;
    case 0:
      std::cout << "Exiting the program.";
      break;
    default:
      std::cout << "Invalid choice." << std::endl;
    }
  }

  return 0;
}

void inputWorkout(std::string &workoutName, std::string &exerciseName, int &sets, int &reps, double &weight)
{
  std::cin.ignore();
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