#include <iostream>
#include "Lumen.h"

int main()
{
	Lumen::Console console("TESTING");
	console.Info("Hello, world!");
	console.Warn("Here's something you should probably know!");
	console.Error("Uh oh! Something went wrong.");
	console.Crit("OH GOD! ABANDON SHIP!");

	return 0;
}
