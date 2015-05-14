#ifndef ACTIVITYDYNAMICPROGRAM_H
#define ACTIVITYDYNAMICPROGRAM_H
#include "Activity.h"
#include <vector>
#include <iostream>

namespace md_islam{
	class ActivityDynamicProgram{
	public:
		//Activities are pre-sorted with finishes times first
		ActivityDynamicProgram(Activity  activityArray[], int numberOfActivities){
			this->activityArray_ptr = activityArray;
			this->numberOfActivites = numberOfActivities;

			//Sort start / end times in arrays
			this->startTimes = new float[this->numberOfActivites];
			this->endTimes = new float[this->numberOfActivites];
			for (int i = 0; i < this->numberOfActivites; i++){
				this->startTimes[i] = this->activityArray_ptr[i].getStartTime();
				this->endTimes[i] = this->activityArray_ptr[i].getEndTime();
			}

			//Generate dynamic table
			std::vector<Activity> newRow;
			for (int i = 0; i < this->numberOfActivites; i++){
				newRow.clear();
				generateLeftSideTable(i, newRow);
				newRow.push_back(this->activityArray_ptr[i]);
				generateRightSideTable(i, newRow);
				this->dynamicVectorTable.push_back(newRow);
			}

			//Calculate which row has highest weight:
			float * weightsArray = new float[this->numberOfActivites];
			int weightsArrayCounter = 0;
			float currentWeight;
			for (std::vector<std::vector<Activity>>::iterator it = this->dynamicVectorTable.begin(); it != dynamicVectorTable.end(); it++){
				currentWeight = 0;
				for (std::vector<Activity>::iterator it2 = it->begin(); it2 != it->end(); it2++){
					currentWeight += it2->getWeight();
				}
				weightsArray[weightsArrayCounter] = currentWeight;
				weightsArrayCounter++;
			}
			this->maxWeight = 0;
			for (int i = 0; i <= weightsArrayCounter; i++){
				if (weightsArray[i] > maxWeight){
					this->maxWeight = weightsArray[i];
					this->indexOfMaxWeight = i + 1;
				}
			}

		}
		void generateLeftSideTable(int indexActivity, std::vector<Activity>& newRow){
			float startTimeOfIndex = this->startTimes[indexActivity];

			//search endTimes before startTime of given param
			for (int i = 0; i < this->numberOfActivites; i++){
				if (this->endTimes[i] <= startTimeOfIndex){
					newRow.push_back(this->activityArray_ptr[i]);
					generateLeftSideTable(i, newRow);
					break;
				}
			}
		}
		void generateRightSideTable(int indexActivity, std::vector<Activity>& newRow){
			//search for startTime after endTime of given param
			for (int i = (indexActivity + 1); i < this->numberOfActivites; i++){
				if (this->startTimes[i] >= this->endTimes[indexActivity]){
					newRow.push_back(this->activityArray_ptr[i]);
					generateRightSideTable(i, newRow);
					break;
				}
			}
			
		}
		void print(){
			std::cout << "Max weight is of row: " << indexOfMaxWeight << " with weight: " << maxWeight << std::endl;
			std::cout << "The row has these start times: " << std::endl;
			for (int i = 0; i < this->dynamicVectorTable[this->indexOfMaxWeight].size(); i++)
				std::cout << this->dynamicVectorTable[this->indexOfMaxWeight][i].getStartTime() << ",";
			std::cout << std::endl;
		
			
		}
	private:
		Activity * activityArray_ptr;
		float * startTimes;
		float * endTimes;
		int numberOfActivites;
		int indexOfMaxWeight;
		float maxWeight;
		std::vector<std::vector<Activity>> dynamicVectorTable;
	};
}

#endif