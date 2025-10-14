// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceRollerPawn.h"

// Sets default values
ADiceRollerPawn::ADiceRollerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);


}

// Called when the game starts or when spawned
void ADiceRollerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADiceRollerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADiceRollerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		//EnhancedInputComponent->BindAction(LeftMouseClickAction, ETriggerEvent::Triggered, this, &APlayerPawn::LeftMouseClicked);
	}
	*/
}

