
#include "SaveSlots.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../Level Editor/LevelEditor.h"
#include <iostream>
#include <fstream>

SaveSlots::SaveSlots() : Menu(NULL, NULL)
{
	addButton(new UIButton("SaveSlot1Button"));
	addButton(new UIButton("SaveSlot2Button"));
	addButton(new UIButton("SaveSlot3Button"));
	addButton(new UIButton("SaveSlot4Button"));
	addButton(new UIButton("SaveSlot5Button"));
	addButton(new UIButton("SaveSlot6Button"));

	m_Load = LOAD; //creates a default state
}

SaveSlots::~SaveSlots()
{

}

const char* SaveSlots::getName()
{
	return SAVESLOTS_SCREEN_NAME;
}



void SaveSlots::buttonAction(UIButton* button)
{
	int index = getIndexForButton(button);

	switch(index)
	{
	case 0:
		{
			if(m_Load == LOAD)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);//creates a pointer to the LevelEditor
				LevelEditorPtr->getLevel()->load("Level1.json");//Either it loads a map...
			}

			else if(m_Load == SAVE)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->save("Level1.json");///or it saves a map.
			}
			ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
		}
		break;

	case 1:
		{
			if(m_Load == LOAD)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->load("Level2.json");
			}

			else if(m_Load == SAVE)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->save("Level2.json");
			}
			ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
		}
		break;

	case 2:
		{
			if(m_Load == LOAD)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->load("Level3.json");
			}

			else if(m_Load == SAVE)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->save("Level3.json");
			}
			ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
		}
		break;

	case 3:
		{
			if(m_Load == LOAD)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->load("Level4.json");
			}

			else if(m_Load == SAVE)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->save("Level4.json");
			}

			ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
		}
		break;

	case 4:
		{
			if(m_Load == LOAD)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->load("Level5.json");
			}

			else if(m_Load == SAVE)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->save("Level5.json");
			}

			ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
		}
		break;

	case 5:
		{
			if(m_Load == LOAD)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->load("Level6.json");
			}

			else if(m_Load == SAVE)
			{
				LevelEditor* LevelEditorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
				LevelEditorPtr->getLevel()->save("Level6.json");
			}
			ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
		}
		break;
	}


}

bool SaveSlots::getState()
{
	return m_Load;
}

void SaveSlots::setState(bool aLoad)
{
	m_Load = aLoad;
}