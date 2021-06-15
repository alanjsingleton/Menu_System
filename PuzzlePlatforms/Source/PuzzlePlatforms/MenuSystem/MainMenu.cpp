// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableText.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) { return false; }

	if (!ensure(HostButton != nullptr)) { return false; }
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if (!ensure(JoinButton != nullptr)) { return false; }
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if (!ensure(ExitButton != nullptr)) { return false; }
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::ExitGame);

	if (!ensure(CancelJoinMenuButton != nullptr)) { return false; }
	CancelJoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::CancelJoinMenu);

	if (!ensure(JoinGameButton != nullptr)) { return false; }
	JoinGameButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	return true;
}

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) { return; }
	if (!ensure(JoinMenu != nullptr)) { return; }
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::ExitGame()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Exit();
	}
}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) { return; }
	if (!ensure(MainMenu != nullptr)) { return; }
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::CancelJoinMenu()
{
	if (!ensure(IPAddressField != nullptr)) { return; }
	IPAddressField->SetText(FText::GetEmpty());
	OpenMainMenu();
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr)
	{
		if (!ensure(IPAddressField != nullptr)) { return; }
		const FString& Address = IPAddressField->GetText().ToString();
		MenuInterface->Join(Address);
	}
}