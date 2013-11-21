//
//  LevelEditor.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-25.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LevelEditor.h"
#include "../Constants/Constants.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"
#include "../Menus/SaveSlots.h"


LevelEditor::LevelEditor() :
m_TilesMenu(NULL),
	m_TilesMenuLeft(NULL),
	m_Level(NULL),
	m_IsMouseDown(false),
	m_SelectedTileIndex(-1),
	m_SelectedButtonIndex(-1)
{
	//Create the Tiles menu items
	m_TilesMenu = new UISideMenu(this, SideMenuRight);
	m_TilesMenu->addButton(new UIToggle("MenuTileGround"));
	m_TilesMenu->addButton(new UIToggle("MenuTileBrickhoff"));
	m_TilesMenu->addButton(new UIToggle("MenuTileGrasshoff"));
	m_TilesMenu->addButton(new UIToggle("MenuTileWaterhoff"));
	m_TilesMenu->addButton(new UIToggle("MenuTileFirehoff"));
	m_TilesMenu->addButton(new UIToggle("MenuTileHardwoodhoff"));

	///buttons for TileMenuLeft
	m_TilesMenuLeft = new UISideMenu(this, SideMenuLeft);
	m_TilesMenuLeft->addButton(new UIButton("ClearButton"));
	m_TilesMenuLeft->addButton(new UIButton("SaveButton"));
	m_TilesMenuLeft->addButton(new UIButton("LoadButton"));
	m_TilesMenuLeft->addButton(new UIButton("ExitButton"));

	//Create the level object
	m_Level = new Level(true);

	//Reset everything
	reset();
}

LevelEditor::~LevelEditor()
{
	if(m_Level != NULL)
	{
		delete m_Level;
		m_Level = NULL;
	}

	if(m_TilesMenu != NULL)
	{
		delete m_TilesMenu;
		m_TilesMenu = NULL;
	}

	if(m_TilesMenuLeft != NULL)
	{
		delete m_TilesMenuLeft;
		m_TilesMenuLeft = NULL;
	}

}

const char* LevelEditor::getName()
{
	return LEVEL_EDITOR_SCREEN_NAME;
}

void LevelEditor::update(double delta)
{
	if(m_Level != NULL)
	{
		m_Level->update(delta);
	}

	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->update(delta);
	}

	if(m_TilesMenuLeft != NULL)
	{
		m_TilesMenuLeft->update(delta);
	}

}

void LevelEditor::paint()
{
	if(m_Level != NULL)
	{
		m_Level->paint();
	}

	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->paint();
	}

	if(m_TilesMenuLeft != NULL)
	{
		m_TilesMenuLeft->paint();
	}
}

void LevelEditor::reset()
{
	if(m_Level != NULL)
	{
		m_Level->reset();
	}
}

void LevelEditor::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{    
	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}

	if(m_TilesMenuLeft != NULL)
	{
		m_TilesMenuLeft->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}

	if(m_Level != NULL)
	{        
		if(m_SelectedTileIndex != -1 && m_IsMouseDown == true)
		{
			m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
		}
	}
}

void LevelEditor::mouseLeftClickDownEvent(float positionX, float positionY)
{
	//Set the mouse down flag
	m_IsMouseDown = true;
}

void LevelEditor::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Set the mouse up flag
	m_IsMouseDown = false;

	//Safety check the level pointer, then set the new tile type in the index
	if(m_Level != NULL)
	{
		if(m_SelectedTileIndex != -1 && m_TilesMenu->isShowing() == false)
		{
			m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
		}

		if(m_SelectedButtonIndex != -1 && m_TilesMenu->isShowing() == false)
		{
			m_Level->setTileTypeAtPosition((TileType)m_SelectedButtonIndex, positionX, positionY);
		}
	}

	//Notify the tiles menu of the mouse event
	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_TilesMenuLeft != NULL)
	{
		m_TilesMenuLeft->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void LevelEditor::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_TAB)
	{
		if(m_TilesMenu != NULL)
		{
			m_TilesMenu->isShowing() == true ? m_TilesMenu->hide() : m_TilesMenu->show();
		}

		if(m_TilesMenuLeft != NULL)
		{
			m_TilesMenuLeft->isShowing() == true ? m_TilesMenuLeft->hide() : m_TilesMenuLeft->show();
		}
	}

	if(keyCode == KEYCODE_L)//load game
	{
		ScreenManager::getInstance()->switchScreen(SAVESLOTS_SCREEN_NAME);
	}
	if(keyCode == KEYCODE_A)//save game
	{
		ScreenManager::getInstance()->switchScreen(SAVESLOTS_SCREEN_NAME);
	}

	if(keyCode == KEYCODE_E)//exit to menu
	{
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}

	if(keyCode == KEYCODE_C)//clear all tiles to default tile
	{
		m_Level = new Level(true);
	}

	else
	{
		if(m_Level != NULL)
		{
			m_Level->keyUpEvent(keyCode);
		}
	}
}

void LevelEditor::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{
	m_TilesMenuLeft->getIndexForButton(button);

	if(m_TilesMenuLeft->getIndexForButton(button) == 0)
	{
		m_Level->load(NULL);//resets the level
	}

	else if(m_TilesMenuLeft->getIndexForButton(button) == 1)
	{

		ScreenManager::getInstance()->switchScreen(SAVESLOTS_SCREEN_NAME);
		Screen* ScreenPtr = ScreenManager::getInstance()->getScreenForName(SAVESLOTS_SCREEN_NAME);
		SaveSlots* childPtr = dynamic_cast<SaveSlots*>(ScreenPtr);//creates a pointer to SaveSlots screen to save
		childPtr->setState(SAVE);
	}

	else if (m_TilesMenuLeft->getIndexForButton(button) == 2)
	{
		ScreenManager::getInstance()->switchScreen(SAVESLOTS_SCREEN_NAME);
		Screen* ScreenPtr = ScreenManager::getInstance()->getScreenForName(SAVESLOTS_SCREEN_NAME);
		SaveSlots* childPtr = dynamic_cast<SaveSlots*>(ScreenPtr);
		childPtr->setState(LOAD);
		
	}

	else if (m_TilesMenuLeft->getIndexForButton(button) == 3)
	{
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}

void LevelEditor::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
	if(sideMenu == m_TilesMenu)
	{
		//Un-toggled the previously selected toggle
		UIToggle* previousToggle = (UIToggle*)m_TilesMenu->getButtonForIndex(m_SelectedTileIndex);
		if(previousToggle != NULL)
		{
			previousToggle->setIsToggled(false);
		}

		//Set the selected tile index
		m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
		m_SelectedButtonIndex = toggle->isToggled() == true ? toggleIndex : -1;

		//Hide the options and tiles menus
		m_TilesMenu->hide();
		m_TilesMenuLeft->hide();
	}
}

Level* LevelEditor::getLevel()
{
	return m_Level;
}

void LevelEditor::setLevel(Level* aLevel)
{
	m_Level = aLevel;
}