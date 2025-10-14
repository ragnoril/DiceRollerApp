// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DieFaceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DICEROLLERAPP_API UDieFaceComponent : public USceneComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(Category = Gameplay, EditAnywhere)
	int Value;

	// Sets default values for this component's properties
	UDieFaceComponent();



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
