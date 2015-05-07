#ifndef ACTIVITYDYNAMICPROGRAM_H
#define ACTIVITYDYNAMICPROGRAM_H
#include "Activity.h"

namespace md_islam{
	class ActivityDynamicProgram{
	public:
		ActivityDynamicProgram(int numberOfActivities){
			this->numberOfActivites = numberOfActivites;
			generateTable();
		}
		void generateTable(){

		}
	private:
		int numberOfActivites;
		md_islam::Activity ** dynamicTable_ptr;
	};
}

#endif