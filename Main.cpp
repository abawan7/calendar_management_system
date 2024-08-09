#include <iostream>
#include<stdio.h>
#include <windows.h>
#include <cwchar>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Activity
{
	string title;
	string user_Id;
	string activity_Id;
	float priority;
	int duration;
};

void setCursorPointer(int x = 0, int y = 0)
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}

void split(string& act, Activity***** Calender)
{
	int Day, Months;
	int Start_time, End_time, Position;

	float Priority;

	string User_Id;
	string Activity_Id;
	string Title;
	string EmptyTitle = " ";

	Position = act.find('/');
	Day = atoi((act.substr(0, Position)).c_str());
	Day--;
	act.erase(0, Position + 1);

	Position = act.find(',');
	Months = atoi((act.substr(0, Position)).c_str());
	Months--;
	act.erase(0, Position + 1);

	Position = act.find(',');
	Start_time = atoi((act.substr(0, Position)).c_str());
	act.erase(0, Position + 1);

	Position = act.find(',');
	End_time = atoi((act.substr(0, Position)).c_str());
	act.erase(0, Position + 5);

	Position = act.find(',');
	User_Id = act.substr(0, Position);
	act.erase(0, Position + 1);

	Position = act.find(',');
	Activity_Id = act.substr(0, Position);
	act.erase(0, Position + 1);

	Position = act.find(',');
	Title = act.substr(0, Position);
	act.erase(0, Position + 1);

	Position = act.find(',');
	Priority = atof((act.substr(0)).c_str());

	int Duration = End_time - Start_time;

	int n = 0;
	Activity* activity = new Activity();
	if (Calender[Months][Day][Start_time][n] != NULL) {
		n = 1;
		activity->activity_Id = Activity_Id;
		activity->user_Id = User_Id;
		activity->duration = Duration;
		activity->title = Title;
		activity->priority = Priority;
		Calender[Months][Day][Start_time][n] = activity;
	}
	if (Calender[Months][Day][Start_time][n] == NULL)
	{
		activity->activity_Id = Activity_Id;
		activity->user_Id = User_Id;
		activity->duration = Duration;
		activity->title = Title;
		activity->priority = Priority;

		Calender[Months][Day][Start_time][n] = activity;
	}

	cout << "Stored In Calender" << endl;

	cout << "Activity: " << Calender[Months][Day][Start_time][n]->activity_Id << "  User Id: " << Calender[Months][Day][Start_time][n]->user_Id << "  Priority: " << Calender[Months][Day][Start_time][n]->priority;
	cout << "  Title: " << Calender[Months][Day][Start_time][n]->title << "  Duration: " << Calender[Months][Day][Start_time][n]->duration << endl;
}

void list_all_activity(Activity***** Calender) {
	string User_Id;
	int count = 0, Days = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;

	cout << "Enter the ID of the User whose Activities are to be Displayed" << endl;
	cin >> User_Id;
	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());

	cout << endl << "The List of the User Activities is" << endl;
	int j = 0;
	for (int i = start_month; i < end_month; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (j = start_date; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						for (int z = 0; Calender[i][j][k][l][z].title != ""; z++)
						{
							if (User_Id == (Calender[i][j][k][l][z].user_Id))
							{
								cout << Calender[i][j][k][l][z].title << endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	if (count == 0)
	{
		cout << "The User Has No Activity In this Time Span" << endl;
	}
}

void Print_activity_stats(Activity***** Calender) {
	int count = 0;
	float total;
	float avg = 0;
	int Days = 0;
	int acts = 0;
	int month;
	cout << "Enter Month Number: " << endl;
	cin >> month;
	month -= 1;

	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
	}
	else if (month == 1)
	{
		Days = 28;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
	}
	for (int j = 0; j < Days; j++)
	{
		for (int k = 0; k < 24; k++)
		{
			for (int l = 0; l < 1; l++) {
				if (Calender[month][j][k][l] != NULL)
				{
					count++;
				}
			}
		}
	}
	total = count;
	int i = 0;
	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
		avg = total / Days;
	}
	else if (month == 1)
	{
		Days = 28;
		avg = total / Days;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
		avg = total / Days;
	}
	cout << "The Total Number of Activities in the Month are : " << total << endl;
	cout << "The Average Number of Activities Per Month are : " << avg << endl;

	int day_act = 0;
	int curr_day = 0;
	int buzy_day = 0;
	int high_day = 0;
	int yex = 0;

	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
	}
	else if (month == 1)
	{
		Days = 28;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
	}
	for (int j = 0; j < Days; j++)
	{
		for (int k = 0; k < 24; k++)
		{
			for (int l = 0; l < 1; l++) {
				if (Calender[month][j][k][l] != NULL)
				{
					curr_day++;
					yex++;
				}
			}
		}
		if (high_day < curr_day) {
			high_day = curr_day;
			buzy_day = j;
			day_act = yex;
		}
	}


	if (yex > 0)
	{
		buzy_day++;
		cout << "The Buziest Day of the Month is                              : Day " << buzy_day << endl;
		cout << "The No. Activities on the Buziest Day of the Month are       : " << day_act << endl;
	}

	float priority = 0;
	float count1 = 0;
	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
	}
	else if (month == 1)
	{
		Days = 28;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
	}
	for (int j = 0; j < Days; j++)
	{
		for (int k = 0; k < 24; k++)
		{
			for (int l = 0; l < 1; l++) {
				if (Calender[month][j][k][l] != NULL)
				{
					for (int z = 0; Calender[month][j][k][l][z].title != ""; z++)
					{
						priority += Calender[month][j][k][l][z].priority;
						count1++;
					}
				}
			}
		}
	}
	priority = priority / count1;
	cout << "The Average Number of Activities Priority In the Month are : " << priority << endl;

}

void list_of_users(Activity***** Calender) {
	int count = 0, Days = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;
	int U = 0;;

	cout << "Enter Users: " << endl;
	cin >> U;

	string* arr = new string[U];
	for (int i = 0; i < U; i++) {
		cout << "Enter User " << i << " : ";
		cin >> arr[i];
	}

	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());

	cout << endl << "The List of the User Free In Time Slot Is: " << endl;
	int j = 0;
	for (int i = start_month; i < end_month; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (j = start_date; j < end_date; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {

					if (Calender[i][j][k][l] == NULL)
					{
						cout << "Users Are Free In " << j + 1 << "/" << i + 1 << " " << k + 1 << endl;
					}
				}
			}
		}
	}
}

void longest_free_period(Activity***** Calender) {
	string User_Id;
	int count = 0, Days = 0, act = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;
	bool flag = false;

	cout << "Enter the ID of the User" << endl;
	cin >> User_Id;
	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());
	int j = 0;
	for (int i = start_month; i < end_month; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (j = start_date; j < Days; j++)
		{
			flag = false;
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						for (int z = 0; Calender[i][j][k][l][z].title != ""; z++)
						{
							if (User_Id == (Calender[i][j][k][l][z].user_Id))
							{
								act++;
								flag = true;
							}
						}
					}
				}
			}
			if (flag == true) {
				count--;
				if (act == 2) {
					break;
				}

			}
			else {
				count++;
			}
			if (act == 2) {
				break;
			}
		}
		if (act == 2) {
			break;
		}
	}
	cout << "The long time period in which the user is free is: " << count << endl;
}

void Important_activities(Activity***** Calender) {
	string User_Id;
	int count = 0, Days = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;

	cout << "Enter the ID of the User whose Top 5 Activities are to be Displayed" << endl;
	cin >> User_Id;
	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());

	cout << endl << "The Top 5 Activities of the User are" << endl;
	int j = 0;
	for (int i = start_month; i < end_month; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (j = start_date; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						for (int z = 0; Calender[i][j][k][l][z].title != ""; z++)
						{
							if (User_Id == (Calender[i][j][k][l][z].user_Id))
							{
								count++;
							}
						}

					}
				}
			}
		}
	}
	if (count > 0)
	{
		Activity* arr = new Activity[count];
		int counter = 0;
		float prt[5000] = { 0 };
		for (int i = start_month; i < end_month; i++)
		{
			if (start_month == end_month - 1)
			{
				if (i == start_month)
				{
					if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
					{
						Days = 31;
					}
					else if (i == 1)
					{
						Days = 28;
					}
					else if (i == 3 || i == 5 || i == 8 || i == 10)
					{
						Days = 30;
					}
					for (j = start_date; j < Days; j++)
					{
						for (int k = 0; k < 24; k++)
						{
							for (int z = 0; z < 1; z++) {
								if (Calender[i][j][k] != NULL)
								{
									for (int l = 0; Calender[i][j][k][l][z].title != ""; l++)
									{
										if (User_Id == (Calender[i][j][k][l][z].user_Id))
										{
											arr[counter].title.assign((Calender[i][j][k][l][z].title));
											prt[counter] = Calender[i][j][k][l][z].priority;
											counter++;
										}
									}
								}
							}
						}
					}
				}
			}
			else
			{
				if (i == start_month)
				{
					if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
					{
						Days = 31;
					}
					else if (i == 1)
					{
						Days = 28;
					}
					else if (i == 3 || i == 5 || i == 8 || i == 10)
					{
						Days = 30;
					}
					for (j = start_date; j < Days; j++)
					{
						for (int k = 0; k < 24; k++)
						{
							for (int z = 0; z < 1; z++) {
								if (Calender[i][j][k][z] != NULL)
								{
									for (int l = 0; Calender[i][j][k][z][l].title != ""; l++)
									{
										if (User_Id == (Calender[i][j][k][z][l].user_Id))
										{
											arr[counter].title.assign((Calender[i][j][k][z][l].title));
											prt[counter] = Calender[i][j][k][z][l].priority;
											counter++;
										}
									}
								}
							}
						}
					}
				}
				if (i != start_month && i != (end_month - 1))
				{
					if (i == 2 || i == 4 || i == 6 || i == 7 || i == 9)
					{
						Days = 31;
					}
					else if (i == 1)
					{
						Days = 28;
					}
					else if (i == 3 || i == 5 || i == 8 || i == 10)
					{
						Days = 30;
					}
					for (j = 0; j < Days; j++)
					{
						for (int k = 0; k < 24; k++)
						{
							for (int z = 0; z < 1; z++) {
								if (Calender[i][j][k][z] != NULL)
								{
									for (int l = 0; Calender[i][j][k][z][l].title != ""; l++)
									{
										if (User_Id == (Calender[i][j][k][z][l].user_Id))
										{
											arr[counter].title.assign((Calender[i][j][k][z][l].title));
											prt[counter] = Calender[i][j][k][z][l].priority;
											counter++;
										}
									}
								}
							}
						}
					}
				}
				if (i == (end_month - 1))
				{
					for (j = 0; j < end_date; j++)
					{
						for (int k = 0; k < 24; k++)
						{
							for (int z = 0; z < 1; z++) {
								if (Calender[i][j][k][z] != NULL)
								{
									for (int l = 0; Calender[i][j][k][z][l].title != ""; l++)
									{
										if (User_Id == (Calender[i][j][k][z][l].user_Id))
										{
											arr[counter].title.assign((Calender[i][j][k][z][l].title));
											prt[counter] = Calender[i][j][k][z][l].priority;
											counter++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < counter; i++)
		{
			j = i + 1;
			while (j < counter)
			{
				if (prt[i] < prt[i + j])
				{
					swap(prt[i], prt[i + j]);
					swap(arr[i].title, arr[i + j].title);
				}
				j++;
			}
		}
		for (int i = 0; i < counter && i < 5; i++)
		{
			cout << arr[i].title << " (" << prt[i] << ")" << endl;
		}
	}
	else
	{
		cout << "There is no Activity of the user During this Time Period." << endl;
	}
}

void Remove_user(Activity***** Calender)
{
	int count = 0;
	int Days = 0;
	bool flag = true;
	string User_id;
	cout << "Enter the ID of the User to be Removed" << endl;
	cin >> User_id;
	for (int i = 0; i < 12; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						if (User_id == Calender[i][j][k][l][0].user_Id) {
							Calender[i][j][k][l] = NULL;
						}
					}

				}
			}
		}
	}
	cout << endl << "All the Data of User " << User_id << " has been removed" << endl;
}

void Calendar_Stats(Activity***** Calender) {
	int count = 0;
	float total;
	float avg = 0;
	int g = 0;
	int Days = 0;
	int acts = 0;
	for (int i = 0; i < 12; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						count++;
					}
				}
			}
		}
	}
	total = count;
	avg = total / 12;
	int i = 0;
	cout << "The Total Number of Activities in the Year are : " << total << endl;
	cout << "The Average Number of Activities Per Month are : " << avg << endl;
	int month_act = 0;
	int curr_month = 0;
	int buzy_month = 0;
	int high_month = 0;
	int yex = 0;
	for (int i = 0; i < 12; i++)
	{
		curr_month = 0;
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						curr_month++;
						yex++;

					}
				}
			}
		}
		if (high_month < curr_month)
		{
			high_month = curr_month;
			month_act = curr_month;
			buzy_month = i;
		}
	}
	if (yex > 0)
	{
		buzy_month++;
		cout << "The Buziest Month of the Year is                              : Month " << buzy_month << endl;
		cout << "The No. Activities on the Buziest Month of the Year are       : " << month_act << endl;
	}
}

void Save_calendar(Activity***** Calender)
{
	int Days = 0;
	bool flag = true;
	int count = 0;
	ofstream Write("Data");
	for (int i = 0; i < 12; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						Write << j + 1 << "/" << i + 1 << "," << k
							<< "," << k + Calender[i][j][k][l][0].duration << "," << "user" << Calender[i][j][k][l][0].user_Id
							<< "," << Calender[i][j][k][l][0].activity_Id << "," << Calender[i][j][k][l][0].title
							<< "," << Calender[i][j][k][l][0].priority << endl;

					}
				}
			}
		}
	}
	cout << "Calender Saved /_" << endl;
}

void Print_Calender_Month(Activity***** Calender)
{
	int i;
	cout << "Enter Month: " << endl;
	cin >> i;
	i -= 1;
	system("cls");

	int x = 0;
	int y = 0;
	int Days = 0;



	int cx = 0, px = 0, py = 0, count = 0;
	bool flag = false;

	if (i == 1)
	{
		setCursorPointer(2, 0);
		cout << "---January---" << endl;
		Days = 31;
	}
	else if (i == 2)
	{
		setCursorPointer(2, 0);
		cout << "---Febraury---" << endl;
		Days = 28;
	}
	else if (i == 3)
	{
		setCursorPointer(2, 0);
		cout << "---March---" << endl;
		Days = 31;
	}
	else if (i == 4)
	{
		setCursorPointer(2, 0);
		cout << "---April---" << endl;
		Days = 30;
	}
	else if (i == 5)
	{
		setCursorPointer(2, 0);
		cout << "---May---" << endl;
		Days = 31;
	}
	else if (i == 6)
	{
		setCursorPointer(2, 0);
		cout << "---June---" << endl;
		Days = 30;
	}
	else if (i == 7)
	{
		setCursorPointer(2, 0);
		cout << "---July---" << endl;
		Days = 31;
	}
	else if (i == 8)
	{
		setCursorPointer(2, 0);
		cout << "---August---" << endl;
		Days = 31;
	}
	else if (i == 9)
	{
		setCursorPointer(2, 0);
		cout << "---September---" << endl;
		Days = 30;
	}
	else if (i == 10)
	{
		setCursorPointer(2, 0);
		cout << "---October---" << endl;
		Days = 31;
	}
	else if (i == 11)
	{
		setCursorPointer(2, 0);
		cout << "---November---" << endl;
		Days = 30;
	}
	else if (i == 12)
	{
		setCursorPointer(2, 0);
		cout << "---December---" << endl;
		Days = 31;
	}
	x = 9;
	y = 2;
	cx = 0;

	if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
	{
		Days = 31;
	}
	else if (i == 1)
	{
		Days = 28;
	}
	else if (i == 3 || i == 5 || i == 8 || i == 10)
	{
		Days = 30;
	}
	for (int j = 0; j < Days; j++)
	{
		flag = false;
		for (int k = 0; k < 24; k++)
		{
			for (int l = 0; l < 1; l++) {
				if (Calender[i][j][k][l] != NULL)
				{

					setCursorPointer(x, y);
					cout << "'" << j + 1;
					x = x + 3;
					if (x == 21)
					{
						x = cx;
						y++;
					}
					flag = true;
				}
			}
			if (flag == true) {
				break;
			}
		}
		if (flag == false) {
			setCursorPointer(x, y);
			cout << j + 1;
			x = x + 3;
			if (x == 21)
			{
				x = cx;
				y++;
			}
		}
	}

	setCursorPointer(px, 1);
	cout << "M";
	px += 3;
	setCursorPointer(px, 1);
	cout << "T";
	px += 3;
	setCursorPointer(px, 1);
	cout << "W";
	px += 3;
	setCursorPointer(px, 1);
	cout << "T";
	px += 3;
	setCursorPointer(px, 1);
	cout << "F";
	px += 3;
	setCursorPointer(px, 1);
	cout << "S";
	px += 3;
	setCursorPointer(px, 1);
	cout << "S";
	cout << endl << endl << endl << endl << endl << endl;
}

void Clashing_Activity(Activity***** Calender) {
	int count = 0, Days = 0;
	int position;
	string start, end;
	int D = 0;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;

	string user_id1, user_id2;
	cout << "Enter User 1: ";
	cin >> user_id1;
	cout << "Enter User 2: ";
	cin >> user_id2;

	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());
	bool flag = false;
	for (int i = start_month; i < end_month; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			D = 31;
		}
		else if (i == 1)
		{
			D = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			D = 30;
		}
		for (int j = start_date; j < D; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				for (int l = 0; l < 1; l++) {
					if (Calender[i][j][k][l] != NULL)
					{
						for (int z = 0; Calender[i][j][k][l][z].title != ""; z++)
						{
							if (user_id1 == (Calender[i][j][k][l][0].user_Id) && user_id2 == (Calender[i][j][k][l + 1][z].user_Id))
							{
								cout << "The User Having a Clash In These " << endl;
								cout << Calender[i][j][k][l][z].title << endl;
								cout << Calender[i][j][k][l + 1][z].title << endl;
								flag = true;
								count++;
							}
						}
					}
					if (flag == true) {
						break;
					}
				}
				if (flag == true) {
					break;
				}
			}
			if (flag == true) {
				break;
			}
		}
		if (flag == true) {
			break;
		}
	}
	if (count == 0)
	{
		cout << "The User Has No Clash In this Time Span" << endl;
	}

}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	int Days = 0;
	int Monthss = 12;
	int hours = 24;
	int act = 5;
	Activity***** Calender;
	Calender = new Activity * ***[Monthss];
	for (int i = 0; i < Monthss; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		Calender[i] = new Activity * **[Days];
		for (int j = 0; j < Days; j++)
		{
			Calender[i][j] = new Activity * *[hours];
			for (int k = 0; k < hours; k++)
			{
				Calender[i][j][k] = new Activity * [act];
				for (int l = 0; l < 5; l++) {
					Calender[i][j][k][l] = NULL;
				}
			}
		}
	}
	string line;

	ifstream Fetch("Activity");
	if (Fetch.is_open())
	{
		while (getline(Fetch, line))
		{
			split(line, Calender);
		}
		Fetch.close();
	}

	while (1)
	{
		int choice;
		cout << "\n\nWelcome to the Calendar.." << endl << endl;
		cout << "1) List all activities of a given user during a time period." << endl;
		cout << "2) List the 5 most important activities of a given user during a time period." << endl;
		cout << "3) longest consecutive number of days in which the user has no activity. " << endl;
		cout << "4) list all hourly slots that are free for all these user in this time period." << endl;
		cout << "5) Print activity stats for a given month" << endl;
		cout << "6) Print Calendar Stats (for the whole year)" << endl;
		cout << "7) Remove a user from the calendar" << endl;
		cout << "8) Save the calendar" << endl;
		cout << "9) Print the calendar month." << endl;
		cout << "10) Clashing Activities." << endl;
		cout << "Enter -1 To Exit" << endl << endl;
		cout << "Please Choice (1 - 9): ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			list_all_activity(Calender);
		}
		else if (choice == 2)
		{
			Important_activities(Calender);
		}
		else if (choice == 3)
		{
			longest_free_period(Calender);
		}
		else if (choice == 4)
		{
			list_of_users(Calender);
		}
		else if (choice == 5)
		{
			Print_activity_stats(Calender);
		}
		else if (choice == 6)
		{
			Calendar_Stats(Calender);
		}
		else if (choice == 7)
		{
			Remove_user(Calender);
		}
		else if (choice == 8)
		{
			Save_calendar(Calender);
		}
		else if (choice == 9) {
			Print_Calender_Month(Calender);
		}
		else if (choice == 10) {
			Clashing_Activity(Calender);
		}
		else if (choice == -1) {
			break;
		}
		else
		{
			cout << "Invalid Value.. Try Again" << endl;
		}
	}
	for (int i = 0; i < Monthss; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			Calender[i][j] = new Activity * *[hours];
			for (int k = 0; k < hours; k++)
			{
				Calender[i][j][k] = new Activity * [act];
				for (int l = 0; l < 5; l++) {
					delete[]Calender[i][j][k][l];
				}
				delete[]Calender[i][j][k];
			}
			delete[]Calender[i][j];
		}
		delete[]Calender[i];
	}
	delete[]Calender;
	return 0;
}