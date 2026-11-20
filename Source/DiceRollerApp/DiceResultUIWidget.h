// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "DiceResultUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class DICEROLLERAPP_API UDiceResultUIWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void UpdateResult(FString value);

	UFUNCTION()
	void HideResult();

protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> ValueTextWidget;
};
