// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) { return false; }

	if (!ensure(InGameCancelButton != nullptr)) { return false; }
	InGameCancelButton->OnClicked.AddDynamic(this, &UInGameMenu::CancelInGameMenu);

	if (!ensure(InGameQuitButton != nullptr)) { return false; }
	InGameQuitButton->OnClicked.AddDynamic(this, &UInGameMenu::QuitInGameMenu);

	return true;
}

void UInGameMenu::CancelInGameMenu()
{
	Teardown();
}

void UInGameMenu::QuitInGameMenu()
{
	if (MenuInterface != nullptr)
	{
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}