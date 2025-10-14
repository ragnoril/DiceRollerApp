// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "Components/MultiLineEditableTextBox.h"
#include "DiceRollUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class DICEROLLERAPP_API UDiceRollUIWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void ThrowD4();

	UFUNCTION()
	void ThrowD6();

	UFUNCTION()
	void ThrowD8();

	UFUNCTION()
	void ThrowD10();

	UFUNCTION()
	void ThrowD12();

	UFUNCTION()
	void ThrowD20();

	UFUNCTION()
	void Reroll();

	UFUNCTION()
	void ClearDices();

	UFUNCTION()
	void UpdateResults(FString value);


protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_D4;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_D6;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_D8;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_D10;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_D12;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_D20;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_Reroll;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> Button_Clear;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UMultiLineEditableTextBox> ResultText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UScrollBox> ScrollBoxResult;

};
