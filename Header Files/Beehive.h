#pragma once

#include <string>
#include <chrono>
#include <ctime>
#include <chrono>
#include <thread>  
using namespace std;
class Beehive {

protected:
	Beehive(const int width, const int height, const int breadth, const int volume, const bool produce)
		:Width(width), Height(height), Length(breadth), Volume(volume),Produce(produce) {

	}
	~Beehive() {

	}
	static Beehive* beehive;
public:

    /**
     * Singletons should not be cloneable.
     */
    Beehive(Beehive& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Beehive&) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static Beehive *GetInstance(const int* width, const int* height, const int* breadth, const int* volume,const bool& produce);
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */

    int waitTime(int waitSeconds) const {
       /* int currentValue = **waitSeconds;*/
        while (waitSeconds-- > -1) {
            if (waitSeconds == 0) {
                return waitSeconds;
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        return -1;
    }
    int volume() const {
        return Volume;
    }
    bool produced()const {
        return Produce;
    }
private:
	int Width = 10;
	int Height = 10;
	int Length =10;
	int Volume = 0;
	bool Produce =false;
    string getCurrentDateTime()
    {
        time_t tt;
        struct tm* st;

        time(&tt);
        st = localtime(&tt);
        return asctime(st);
    }
};