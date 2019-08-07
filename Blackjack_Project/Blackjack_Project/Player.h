#pragma once

#include<vector>

using namespace std;

class Player 
{
private:
	bool busted;

public:
	Player()
	{
		busted = false;
	}

	bool getBusted()
	{
		return busted;
	}

	void bustPlayer()
	{
		busted = true;
	}


};