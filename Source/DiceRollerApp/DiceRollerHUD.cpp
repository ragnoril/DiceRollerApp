// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceRollerHUD.h"


void ADiceRollerHUD::StartHUD()
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	UI = CreateWidget<UUserWidget>(PC, UIClass);

	UI->AddToViewport();
}
