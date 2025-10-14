// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DieActor.h"
#include "DiceRollerPawn.generated.h"

UCLASS()
class DICEROLLERAPP_API ADiceRollerPawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot = nullptr;

public:
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<class ADieActor>> DiceList;
	/*
	UPROPERTY(EditAnywhere, Category = "InputPawn")
	TObjectPtr<UInputMappingContext> InputMappingPawn;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> ThrowDiceAction;
	*/
	// Sets default values for this pawn's properties
	ADiceRollerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
