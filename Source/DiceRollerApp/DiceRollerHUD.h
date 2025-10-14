// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "DiceRollerHUD.generated.h"

/**
 * 
 */
UCLASS()
class DICEROLLERAPP_API ADiceRollerHUD : public AHUD
{
	GENERATED_BODY()

public:
	void StartHUD();

protected:
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> UIClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> UI;
	
};
