# Calendar Management System

### Overview

The Calendar Management System is a console-based application developed in C++ to help users manage and analyze their activities over time. This system supports multiple functionalities, such as listing user activities, checking free time slots, finding the busiest days, and more. 

### Demo
![Demo](https://github.com/abawan7/calendar_management_system/blob/main/Demo.gif)

### Features

- **List All Activities**: View all activities of a specific user within a given time period.
- **Top 5 Important Activities**: Display the top 5 most important activities based on priority.
- **Longest Free Period**: Identify the longest consecutive period where a user has no scheduled activities.
- **Free Time Slots for Users**: Find hourly slots where multiple users are free within a specified time range.
- **Monthly Activity Stats**: Get statistical insights into activities for a particular month, including the busiest day and average activity priority.
- **Yearly Calendar Stats**: Analyze the overall activity trends for the entire year, including the busiest month.
- **Remove a User**: Delete all activities associated with a specific user.
- **Save Calendar**: Persistently save the calendar's data to a file.
- **Print Monthly Calendar**: Visually display the calendar for a given month, showing days with scheduled activities.
- **Clashing Activities**: Identify activities that clash between two users during a specified time period.

### Prerequisites

To compile and run this program, you will need:
- A C++ compiler (e.g., g++, Visual Studio)
- A Windows environment to support the Windows-specific API used in the program.

### How to Run

1. **Clone the Repository:**
   - Download or clone the repository containing the source code files.

2. **Compile the Program:**
   - Use a C++ compiler to compile the source code. For example, if using g++, run the following command in your terminal:
     ```
     g++ -o CalendarSystem calendar.cpp
     ```
     Replace `calendar.cpp` with the name of your source code file.

3. **Run the Program:**
   - After successful compilation, you can run the program by executing the following command:
     ```
     ./CalendarSystem
     ```
     (Replace `CalendarSystem` with the name of your compiled file.)

4. **Interacting with the Calendar:**
   - Upon running the program, you will be presented with a menu of options. Enter the corresponding number to perform the desired action:
     - **1:** List all activities of a given user during a time period.
     - **2:** List the 5 most important activities of a given user during a time period.
     - **3:** Find the longest consecutive number of days where the user has no activities.
     - **4:** List all hourly slots that are free for multiple users in a time period.
     - **5:** Print activity stats for a given month.
     - **6:** Print calendar stats for the whole year.
     - **7:** Remove a user from the calendar.
     - **8:** Save the calendar data to a file.
     - **9:** Print the calendar for a specific month.
     - **10:** Identify clashing activities between two users.

5. **Exit the Program:**
   - To exit the program, choose the option `-1` from the menu.

### Notes

- The calendar is stored in a multi-dimensional array and supports up to 5 activities per hour.
- The program uses a specific format for activity input, which is parsed and stored in the calendar structure.
- The program assumes a Gregorian calendar with typical month lengths, including leap years.

### Credits

- **Abdullah Awan**: mlkabawan336@gmail.com


