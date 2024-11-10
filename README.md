### Train Scheduling Simulation: Platform Usage Analysis

This C++ program simulates a train station's scheduling system to calculate the number of platforms needed to accommodate all trains throughout the day. It works by generating random arrival times and durations for each train and then calculating the maximum number of platforms in use at any given time.

#### Key Features:
- **Randomized Train Data**: The program generates random arrival times and durations for 170 trains within a 24-hour period (from 00:00 to 23:59).
- **Platform Calculation**: It calculates the maximum number of active platforms required at any given time by tracking train arrivals and departures.
- **Time-Specific Query**: Users can input a specific time to check how many platforms will be in use at that exact moment.
- **Execution Time**: The program measures and reports the total runtime of the simulation.

#### How It Works:
1. **Random Data Generation**: 
   - The program randomly generates 170 arrival times (between 00:00 and 23:59) and random durations for each train's stay at the station.
2. **Train Scheduling**:
   - Each train has an arrival time and a corresponding departure time calculated by adding the duration to the arrival time.
3. **Platform Analysis**:
   - The program iterates over every minute of the day, updating the number of active platforms (based on train arrivals and departures).
   - The maximum number of platforms needed at any point in time is calculated and displayed.
4. **User Query**:
   - The user can input a specific time to find out how many platforms will be active at that time.
5. **Performance**:
   - The program calculates and prints the time it takes to execute the simulation.

#### Example Output:
```
Trains
Train 1
Arrival: 320
Time of Departure: 325 minutes

Train 2
Arrival: 1325
Time of Departure: 1330 minutes
...
Today there will be 10 active platforms.

Insert time to see how many platforms will be active:
Time: 1200
3 out of 10 platforms will be active at 12:00 PM.

Program took: 0 seconds.
```

#### Dependencies:
- C++ Standard Library

#### How to Run:
1. Clone the repository to your local machine.
2. Compile the code using any C++ compiler (e.g., `g++` or Visual Studio).
3. Run the executable to simulate the scheduling and platform usage.
