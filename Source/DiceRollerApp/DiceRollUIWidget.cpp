// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceRollUIWidget.h"
#include "DiceRollerGameModeBase.h"
#include "DieActor.h"

void UDiceRollUIWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_D4->OnClicked.AddDynamic(this, &UDiceRollUIWidget::ThrowD4);
	Button_D6->OnClicked.AddDynamic(this, &UDiceRollUIWidget::ThrowD6);
	Button_D8->OnClicked.AddDynamic(this, &UDiceRollUIWidget::ThrowD8);
	Button_D10->OnClicked.AddDynamic(this, &UDiceRollUIWidget::ThrowD10);
	Button_D12->OnClicked.AddDynamic(this, &UDiceRollUIWidget::ThrowD12);
	Button_D20->OnClicked.AddDynamic(this, &UDiceRollUIWidget::ThrowD20);

	Button_Reroll->OnClicked.AddDynamic(this, &UDiceRollUIWidget::Reroll);
	Button_Clear->OnClicked.AddDynamic(this, &UDiceRollUIWidget::ClearDices);
}

void UDiceRollUIWidget::ThrowD4()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	ADieActor* die = GameMode->RollD4();
	die->OnDieResultChangedDelegate.AddUniqueDynamic(this, &UDiceRollUIWidget::UpdateResults);
}

void UDiceRollUIWidget::ThrowD6()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	ADieActor* die = GameMode->RollD6();
	die->OnDieResultChangedDelegate.AddUniqueDynamic(this, &UDiceRollUIWidget::UpdateResults);
}

void UDiceRollUIWidget::ThrowD8()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	ADieActor* die = GameMode->RollD8();
	die->OnDieResultChangedDelegate.AddUniqueDynamic(this, &UDiceRollUIWidget::UpdateResults);
}

void UDiceRollUIWidget::ThrowD10()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	ADieActor* die = GameMode->RollD10();
	die->OnDieResultChangedDelegate.AddUniqueDynamic(this, &UDiceRollUIWidget::UpdateResults);
}

void UDiceRollUIWidget::ThrowD12()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	ADieActor* die = GameMode->RollD12();
	die->OnDieResultChangedDelegate.AddUniqueDynamic(this, &UDiceRollUIWidget::UpdateResults);
}

void UDiceRollUIWidget::ThrowD20()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	ADieActor* die = GameMode->RollD20();
	die->OnDieResultChangedDelegate.AddUniqueDynamic(this, &UDiceRollUIWidget::UpdateResults);
}

void UDiceRollUIWidget::Reroll()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	GameMode->RerollAll();
	ResultText->SetText(FText::FromString(""));
}

void UDiceRollUIWidget::ClearDices()
{
	ADiceRollerGameModeBase* GameMode = (ADiceRollerGameModeBase*)GetWorld()->GetAuthGameMode();
	GameMode->ClearDiceTray();
	ResultText->SetText(FText::FromString(""));
}

void UDiceRollUIWidget::UpdateResults(FString value)
{
	FString text = ResultText->GetText().ToString();
	text += value;
	FText newText = FText::FromString(text);
	ResultText->SetText(newText);
	ScrollBoxResult->ScrollToEnd();
}

