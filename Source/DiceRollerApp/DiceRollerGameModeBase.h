// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "DiceRollerHUD.h"
#include "DieActor.h"
#include "DiceRollerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DICEROLLERAPP_API ADiceRollerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<ADieActor*> DiceTray;

protected:
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ADieActor> D4Class;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ADieActor> D6Class;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ADieActor> D8Class;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ADieActor> D10Class;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ADieActor> D12Class;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ADieActor> D20Class;

	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	ADieActor* RollD4();

	UFUNCTION(BlueprintCallable)
	ADieActor* RollD6();

	UFUNCTION(BlueprintCallable)
	ADieActor* RollD8();

	UFUNCTION(BlueprintCallable)
	ADieActor* RollD10();

	UFUNCTION(BlueprintCallable)
	ADieActor* RollD12();

	UFUNCTION(BlueprintCallable)
	ADieActor* RollD20();

	UFUNCTION(BlueprintCallable)
	void ClearDiceTray();

	UFUNCTION(BlueprintCallable)
	void RerollAll();
};
