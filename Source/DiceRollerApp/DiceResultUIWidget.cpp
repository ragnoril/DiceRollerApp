// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceResultUIWidget.h"

void UDiceResultUIWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ValueTextWidget->SetText(FText::FromString(""));
	HideResult();
}

void UDiceResultUIWidget::UpdateResult(FString value)
{
	SetVisibility(ESlateVisibility::Visible);

	FText newText = FText::FromString(value);
	ValueTextWidget->SetText(newText);
}

void UDiceResultUIWidget::HideResult()
{
	SetVisibility(ESlateVisibility::Collapsed);
}
