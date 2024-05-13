#include <iostream>
#include "BarConfiguration.hpp"

namespace Boot
{
	bool Init(
		int &r,
		int &g,
		int &b,
		int &h,
		int &sc,
		int &tcr,
		int &tcg,
		int &tcb
	) {
		r = GetConfigColor("Red", 255);
		g = GetConfigColor("Green", 255);
		b = GetConfigColor("Blue", 255);
		h = GetConfigInt("Bar Height", 25);
		sc = GetConfigInt("ShowConsole", 1);
		tcr = GetConfigColor("Text Red", 0);
		tcg = GetConfigColor("Text Green", 0);
		tcb = GetConfigColor("Text Blue", 0);
		WriteConfigColor("Red", r);
		WriteConfigColor("Green", g);
		WriteConfigColor("Blue", b);
		WriteConfigInt("Bar Height", h);
		WriteConfigInt("ShowConsole", sc);
		WriteConfigColor("Text Red", tcr);
		WriteConfigColor("Text Green", tcg);
		WriteConfigColor("Text Blue", tcb);
		return true;
	}

	void Welcome() {
		std::cout << "Config loaded from config.ihw." << std::endl;
		std::cout << "Welcome to IHWBar!" << std::endl << std::endl;
		std::cout << "Keybinds:" << std::endl;
		std::cout << "ESC: Quit" << std::endl;
		std::cout << "F1: Open Config Editor" << std::endl;
		std::cout << "R: Reload bar height" << std::endl;
	}
}
