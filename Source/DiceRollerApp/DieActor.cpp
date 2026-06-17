// Fill out your copyright notice in the Description page of Project Settings.


#include "DieActor.h"

// Sets default values
ADieActor::ADieActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DefaultRoot"));
	RootComponent = Mesh;
	Mesh->OnComponentHit.AddDynamic(this, &ADieActor::OnHit);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(Mesh);
	AudioComponent->bAutoActivate = false;

}

// Called when the game starts or when spawned
void ADieActor::BeginPlay()
{
	Super::BeginPlay();

	GetComponents(Faces);

	AudioComponent->SetSound(ImpactSFX);
	
	//UE_LOG(LogTemp, Warning, TEXT("Face Count: %d"), Faces.Num());

}

// Called every frame
void ADieActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SfxBufferTime > 0) SfxBufferTime -= DeltaTime;

	if (!bIsThrown) return;

	if (!bIsStartedRolling && Mesh->GetComponentVelocity().Length() > 0)
	{
		bIsStartedRolling = true;
	}

	if (bIsStartedRolling && Mesh->GetComponentVelocity().Length() == 0)
	{
		bIsThrown = false;
		FindDiceResult();
		//UE_LOG(LogTemp, Warning, TEXT("Dice Result: %d"), Result);
	}
	
}

void ADieActor::FindDiceResult()
{
	double maxVal = -1;
	int upFace = -1;
	for (int i = 0; i < Faces.Num(); i++)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Face id: %d value: %d Z: %f"), i, Faces[i]->Value, Faces[i]->GetComponentLocation().Z);
		if (Faces[i]->GetComponentLocation().Z > maxVal)
		{
			maxVal = Faces[i]->GetComponentLocation().Z;
			upFace = i;
		}
	}

	if (upFace != -1)
	{
		Result = Faces[upFace]->Value;
		FString diceName = UEnum::GetDisplayValueAsText(DiceType).ToString();
		FString str = FString::Printf(TEXT("%s: %d\n"), *diceName, Result);
		OnDieResultChangedDelegate.Broadcast(str);
	}
}

void ADieActor::Throw()
{
	Mesh->AddForce(FVector::ForwardVector * ThrowForwardForce * Mesh->GetMass());
	Mesh->AddForce(FVector::UpVector * ThrowUpForce * Mesh->GetMass());
	Mesh->AddImpulse(Mesh->GetForwardVector() * ThrowImpulseForce * Mesh->GetMass());
	
	bIsThrown = true;
	bIsStartedRolling = false;
}

void ADieActor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (SfxBufferTime > 0) return;
	SfxBufferTime = 1.2;
	AudioComponent->Play();
}
