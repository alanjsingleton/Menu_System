// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterfacePtr);
	void Setup();
	void Teardown();
	
protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* CancelJoinMenuButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* JoinGameButton;
	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;
	UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;
	UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;
	UPROPERTY(meta = (BindWidget))
		class UEditableText* IPAddressField;

	UFUNCTION()
		void HostServer();
	UFUNCTION()
		void OpenJoinMenu();
	UFUNCTION()
		void OpenMainMenu();
	UFUNCTION()
		void CancelJoinMenu();
	UFUNCTION()
		void JoinServer();

	IMenuInterface* MenuInterface;
};
