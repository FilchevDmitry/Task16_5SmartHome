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
	double temperatureOutside = 0;			// наружная температура
	double temperatureInside = 0;				// температура внутри
	string movement;						// датчик движения
	string lights;							// освещение в доме
	while (!(day==2))
	{
		string timer = to_string(time);
		if (timer.length() == 1)
			timer = "0" + timer;
		cout << "Time " << timer << ":00\n" << " Enter the parameters(outside temperature, house temperature, movement in the garden(on/off), lighting in the house(on/off))" << endl;
		getline(cin, text);
		stringstream parameters(text);
		parameters >> temperatureOutside >> temperatureInside >> movement >> lights;
		if (temperatureOutside < 0)
		{
			status |= WATER_PIPE_HEATING;
			cout << " WATER PIPE HEATING ON\n";
		}
		if (temperatureOutside > 5)
		{
			status &= ~WATER_PIPE_HEATING;
			cout << " WATER PIPE HEATING OFF\n";
		}
		if (temperatureInside < 22)
		{
			status |= HEATERS;
			cout<< " HEATERS ON\n";
		}
		if (temperatureInside > 25)
		{
			status &= ~HEATERS;
			cout << " HEATERS OFF\n";
		}
		if (temperatureInside < 30)
		{
			status |= CONDITIONER;
			cout << " CONDITIONER ON\n";
		}
		if (temperatureInside > 25)
		{
			status &= ~CONDITIONER;
			cout << " CONDITIONER OFF\n";
		}
		if (time > 16 && movement == "on")
		{
			status |= LIGHTS_OUTSIDE;
			cout << " LIGHTS OUTSIDE ON\n";
		}
		if (time < 5)
		{
			status &= ~LIGHTS_OUTSIDE;
			cout << " LIGHTS OUTSIDE OFF\n";
		}


		if (time == 23)
		{
			time = -1;
			day++;
		}
		++time;
		
	}
}
