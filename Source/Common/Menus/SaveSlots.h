
#ifndef SAVESLOTS_SCREEN_H
#define SAVESLOTS_SCREEN_H

#include "Menu.h"

enum LoadSaveMode//this creates a collection of constants. creating a #define statement of LOAD and SAVE would do the same thing.
{
	LOAD = true,
	SAVE = false
};

class SaveSlots : public Menu
{
public:


	SaveSlots();
	~SaveSlots();

	const char* getName();

	bool getState();
	void setState(bool aLoad);

private:
	void buttonAction(UIButton* button);

	bool m_Load;
};

#endif