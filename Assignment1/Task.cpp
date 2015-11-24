#include<iostream>
#include<string>
#include <iomanip>
#include "Task.h"
#include "Utilities.h"

size_t Task::field_width = 0;
char Task::delimiter = 0;

Task::Task(const std::string& record) { 
	slots = "1";
	pNextTask[0] = nullptr;
	pNextTask[1] = nullptr;
	size_t n_pos = 0;
	bool more = true;
	Utilities util(getFieldWidth());

	if (!record.empty()){
		name = util.nextToken(record,n_pos, more);

		if (more){ 
			slots = util.nextToken(record,n_pos, more);
			if (more) {
				nextTask[0] = util.nextToken(record,n_pos, more);
				if (more) 
					nextTask[1] = util.nextToken(record,n_pos, more);
			}
	 	}
	 }

	field_width =  util.getFieldWidth(); 

}

const std::string& Task::getName() const { return name; }
const unsigned int Task::getSlots() const { 
	unsigned int slot = std::stoi(slots);

	return  slot;
}

bool Task::validate(const Task& task) {
	bool valid = false;

	//std::cout << "current name: " << name << " other name: " << task.getName() << std::endl;
	if (*this == task){
		pNextTask[0] = &task;
		valid = true;
	}

	if (*this == task){
		pNextTask[1] = &task;
		valid = true;
	}

	return valid;
}

const Task* Task::getNextTask(Quality quality) const {
	std::string msg = "";
	switch(quality)
	{
		case passed :
			if(pNextTask[0] == nullptr)
				throw ("*** Validate  [" + nextTask[0] + "] @ ");
			else
				return pNextTask[0];
		case redirect :
			if(pNextTask[1] == nullptr)
				throw ("*** Validate  [" + nextTask[1] + "] @ ");
			else
				return pNextTask[1];
		default :
			throw ("Quality Error"); 
	}

}

void Task::display(std::ostream& os) const
{
	os << "Task Name    : [";
	os << std::setw(field_width) << std::left << name + "]" << "\t[";
	os << std::setw(field_width) << std::left << slots+ "]" << std::endl;
	if (!nextTask[0].empty()) {
		if (pNextTask[0] == nullptr)
			os << " Continue to : [" << std::setw(field_width) << std::left << nextTask[0]+"]"
			<< "\t*** to be validated ***" << std::endl;
		else
			os << " Continue to : [" << std::setw(field_width) << std::left << nextTask[0]+"]"
			<< std::endl;

		if (!nextTask[1].empty()) {
			if (pNextTask[1] == nullptr)
				os << " Redirect to : [" << std::setw(field_width) << std::left << nextTask[1] + "]"
				<< "\t*** to be validated ***" << std::endl;
			else
				os << " Redirect to : [" << std::setw(field_width) << std::left << nextTask[1] + "]"
				<< std::endl;
		}
	}
}
void Task::setDelimiter(const char c) { delimiter = c; }

size_t Task::getFieldWidth() { return field_width; }

bool operator==(const Task& task1, const Task& task2) {
	if (task1.getName() == task2.getName() )
		return true;
	else 
		return false;
}