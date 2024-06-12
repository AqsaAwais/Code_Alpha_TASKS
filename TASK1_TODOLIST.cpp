#include<iostream>
#include<string>
using namespace std;
struct list
{
	string details;
	int task;
	list* next;
	bool complete;
	list() : task(0), next(nullptr), complete(false) {}
};
class to_do_list
{
private:
	list* head;
public:
	to_do_list()
	{
		head = nullptr;
	}
	void add_task(int task, string details)
	{
		list* newlist = new list;
		newlist->task = task;
		newlist->details = details;
		newlist->next = nullptr;
		newlist->complete = false;
		list* curr = head;
		while (curr != nullptr)
		{
			if (curr->task == task)
			{
				cout << "Task " << task << " already exists. Please enter a unique task number." << endl;
				return;
			}
			curr = curr->next;
		}
		{
			
			if (head == nullptr)
			{
				head = newlist;
			
			}

			else
			{
				curr = head;
				while (curr->next != nullptr)
				{
					curr = curr->next;
				}
				curr->next = newlist;
			}
			cout << "Task " << task << ": " << details << " is added" << endl;
		}
	}
	void complete_task(int task)
	{
		list* temp = head;
		int task_done = 1;
		if (head == nullptr)
		{
			cout << "There is no task in to_do_list" << endl;
			return;
		}
		while (temp && task_done < task)
		{
			temp = temp->next;
			task_done++;
		}
		if (temp && task_done == task)
		{
			temp->complete = true;
			cout << "Task " << task << "is completed"<<endl;
		}
		else
		{
			cout << "YOUR INPUT IS NOT VALID!!" << endl;
		}
    }
	void view_curr_tasks()
	{
		list* temp = head;
		int task_num = 1;
		bool curr_tasks = false;
		while (temp != nullptr)
		{
			if (!temp->complete)
			{
				cout << task_num << ": " << temp->details<<endl;
				curr_tasks = true;
			}
			temp = temp->next;
			task_num++;
		}
		if (!curr_tasks)
		{
			cout << "No task in your current list to do" << endl;
		}
	}
	void viewalltask()
	{
		list* temp = head;
		int task_num = 1;
		while (temp != nullptr)
		{
			cout << task_num << ": " << temp->details << endl;
			temp = temp->next;
			task_num++;
		}
	}
	~to_do_list()
	{
		list* temp = head;
		while (temp != nullptr)
		{
			list* newlist = new list;
			delete temp;
			temp = newlist;
		}
	}
};
int main()
{
	to_do_list todo;
	int choice;
	string details;
	int taskno;
	while (true)
	{
		cout << "-----------------------------------------------------------------------------------------------------------"  << endl;
		cout << "|                                          APPLICATION FOR TO_DO_LIST                                      |" << endl;
		cout << "|                                               1.ADD IN LIST                                              |" << endl;
		cout << "|                                           2.MARK TASK AS COMPLETED                                       |" << endl;
		cout << "|                                           3.VIEW YOUR CURRENT TASKS                                      |" << endl;
		cout << "|                                             4.VIEW YOUR ALL TASKS                                        |" << endl;
		cout << "|                                                   5.EXIT                                                 |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------"  << endl;

		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                  Enter your choice                                       |"<<endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			cout << "Enter task no:";
			cin >> taskno;
			cin.ignore();
			cout << "Enter details of respective task:";
			getline(cin, details);
			todo.add_task(taskno, details);
			break;
		case 2:
			cout << "Enter task no:";
			cin >> taskno;
			todo.complete_task(taskno);
			break;
		case 3:
			cout << "Your current tasks are following:" << endl;
			todo.view_curr_tasks();
			break;
		case 4:
			cout << "All of your tasks are following:" << endl;
			todo.viewalltask();
			break;
		case 5:
			cout << "EXITING APPLICATION!!" << endl;
			return 0;
		default:
			cout << "Invalid choice:)" << endl << "TRY AGAIN" << endl;
		}

		
	}
	return 0;
}