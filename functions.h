#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <fstream>

void greet();

void inputWorkoutfromUser(std::string &workoutName, int &sets);

void writeToStream(std::ofstream &file, const std::string &label, const std::string &value);

void writeToStream(std::ofstream &file, const std::string &label, int value);

void writeToStream(std::ofstream &file, const std::string &label, double value);

int dashboard(int &func_choice);

int editWorkoutChoice(int &choice);

void dateInput(std::string &date_FileName);

void workoutInput(std::ofstream &fout, std::string &workoutName, int &numExercises, std::string &exerciseName, int &sets, int &reps, double &weight);

void restDayNote(std::ofstream &fout, std::string &date_FileName, char &noteChoice);

int editExercise(int &user_choice);

#endif 