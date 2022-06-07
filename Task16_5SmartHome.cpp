#include <iostream>
#include<sstream>
using namespace std;
enum switches
{
	MAIN_SWITCH = 1,				//главный выключатель
	SOCKETS=2,						//розетки
	LIGHTS_INSIDE = 4,				//внутренний свет
	LIGHTS_OUTSIDE = 8,				//наружное освещение
	HEATERS = 16,					//обогреватели
	WATER_PIPE_HEATING = 32,		//обогев водопровода
	CONDITIONER = 64				//кондиционер
};
int main()
{
	string text;
	int status = 0;
	int time = 0;
	int day = 0;
	while (!(day==2))
	{
		string timer = to_string(time);
		if (timer.length() == 1)
			timer = "0" + timer;
		cout << "Time " << timer << ":00\n" << " Enter the parameters(outside temperature, house temperature, movement in the garden(on/off), lighting in the house(on/off))" << endl;
		getline(cin, text);
		stringstream parameters(text);
		double temperatureOutside = 0;			// наружная температура
		double temperatureInside = 0;				// температура внутри
		string movement;						// датчик движения
		string lights;							// освещение в доме
		parameters >> temperatureOutside >> temperatureInside >> movement >> lights;
		if (temperatureOutside < 0)
			status |= WATER_PIPE_HEATING;
		if (temperatureOutside > 5)
			status &= ~WATER_PIPE_HEATING;
		if (temperatureInside < 22)
			status |= HEATERS;
		if (temperatureInside > 25)
			status &= ~HEATERS;
		if (temperatureInside < 30)
			status |= CONDITIONER;
		if (temperatureInside > 25)
			status &= ~CONDITIONER;
		if (time > 16 && movement == "on")
			status |= LIGHTS_OUTSIDE;
		if(time < 5)
			status &= ~LIGHTS_OUTSIDE;

		if (status & WATER_PIPE_HEATING)
			cout << " WATER PIPE HEATING ON\n";

		if (time == 23)
		{
			time = -1;
			day++;
		}
		++time;
	}
}
