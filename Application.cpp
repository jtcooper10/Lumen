#include <iostream>
#include "Lumen.h"

using namespace Lumen;

int main()
{
	Application window(720, 480, "Lumen Engine");
	window.console.Info("Starting draw loop");
	while (window.Draw());
	window.console.Info("Draw loop terminated");

	return 0;
}
