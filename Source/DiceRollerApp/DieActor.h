// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DieFaceComponent.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "DieActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieResultChangedSignature, FString, DieResult);


UENUM(BlueprintType)
enum class EDiceType: uint8 
{
	D4 = 0 UMETA(DisplayName = "d4"),
	D6 = 1 UMETA(DisplayName = "d6"),
	D8 = 2 UMETA(DisplayName = "d8"),
	D10 = 3 UMETA(DisplayName = "d10"),
	D12 = 4 UMETA(DisplayName = "d12"),
	D20 = 5 UMETA(DisplayName = "d20") 
};

UCLASS()
class DICEROLLERAPP_API ADieActor : public AActor
{
	GENERATED_BODY()

	bool bIsThrown = false;
	bool bIsStartedRolling = false;
	float SfxBufferTime;

	void FindDiceResult();

protected:
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TArray<UDieFaceComponent*> Faces;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintAssignable)
	FOnDieResultChangedSignature OnDieResultChangedDelegate;

	UPROPERTY(Category = Gameplay, EditAnywhere)
	EDiceType DiceType;

	UPROPERTY(EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> ImpactSFX;

	UPROPERTY(EditAnywhere, Category = "Audio")
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
	int Result = -1;

	UPROPERTY(Category = Gameplay, EditAnywhere)
	int ThrowForwardForce = 100000;

	UPROPERTY(Category = Gameplay, EditAnywhere)
	int ThrowUpForce = 100000;

	UPROPERTY(Category = Gameplay, EditAnywhere)
	int ThrowImpulseForce = 100;

	// Sets default values for this actor's properties
	ADieActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Throw();

	UFUNCTION(BlueprintCallable)
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
