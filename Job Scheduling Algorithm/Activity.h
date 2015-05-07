#ifndef ACTIVITY_H
#define ACTIVITY_H

namespace md_islam{
	class Activity{
	public:
		Activity(float startTime = -1, float endTime = -1, float weight = -1){
			this->startTime = startTime;
			this->endTime = endTime;
			this->weight = weight;
		}
		float getStartTime(){
			return this->startTime;
		}
		float getEndTime(){
			return this->endTime;
		}
		float getWeight(){
			return this->weight;
		}
	private:
		float startTime;
		float endTime;
		float weight;
	};
}

#endif ACTIVITY_H
