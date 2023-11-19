# Console Based Workout Tracker

**Work in Progress**

Welcome to the Console Based Workout Tracker! This simple C++ program allows you to track your workouts and rest days using a console-based interface. You can input workout details and save them to text files for future reference.

## Features

- Add and save workout details.
- Add rest days.
- Edit existing workouts.
- Delete workouts or rest days.
- User-friendly console interface.

## Usage

1. **Adding a Workout**: Choose option 1 and provide the date (in the format dd/mm/yy) for your workout. Then, enter workout details, including the workout name, exercise name, number of sets, number of reps, and weight in kilograms. The workout data will be saved to a text file.

2. **Adding a Rest Day**: Choose option 2 and enter the date for your rest day. This will be saved as a rest day in the program.

3. **Editing a Workout**: Choose option 3 and provide the date of the workout you want to edit. You can then choose to add an exercise or return to dashboard.

4. **Deleting a Workout or Rest Day**: Choose option 4 and enter the date of the workout or rest day you want to delete. Confirm your choice, and the data will be deleted.

5. **Exiting the Program**: Choose option 0 to exit the program.

## How to Run

1. Compile the program using a C++ compiler.

   ```bash
   g++ main.cpp functions.cpp -o workout_tracker
   ./workout_tracker