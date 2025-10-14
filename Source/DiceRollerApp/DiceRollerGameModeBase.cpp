// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceRollerGameModeBase.h"
#include "GameFramework/GameUserSettings.h"

void ADiceRollerGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings();
		MyGameSettings->SetScreenResolution(FIntPoint(1024, 768));
		MyGameSettings->SetFullscreenMode(EWindowMode::Windowed);
		MyGameSettings->SetVSyncEnabled(true);
		MyGameSettings->ApplySettings(true);
	}

	FActorSpawnParameters SpawnParams;
	APlayerController* PC = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	ADiceRollerHUD* HUD = PC->GetHUD<ADiceRollerHUD>();
	HUD->StartHUD();
}

ADieActor* ADiceRollerGameModeBase::RollD4()
{
	FActorSpawnParameters SpawnParams;
	const float pitch = FMath::FRandRange(-180.f, 180.f);
	const float yaw = FMath::FRandRange(-180.f, 180.f);
	const float roll = FMath::FRandRange(-180.f, 180.f);
	ADieActor* die = GetWorld()->SpawnActor<ADieActor>(D4Class, FVector(500, 0, 50), FRotator(pitch, yaw, roll), SpawnParams);
	die->Throw();
	DiceTray.Add(die);

	return die;
}

ADieActor* ADiceRollerGameModeBase::RollD6()
{
	FActorSpawnParameters SpawnParams;
	const float pitch = FMath::FRandRange(-180.f, 180.f);
	const float yaw = FMath::FRandRange(-180.f, 180.f);
	const float roll = FMath::FRandRange(-180.f, 180.f);
	ADieActor* die = GetWorld()->SpawnActor<ADieActor>(D6Class, FVector(500, 0, 50), FRotator(pitch, yaw, roll), SpawnParams);
	die->Throw();
	DiceTray.Add(die);

	return die;
}

ADieActor* ADiceRollerGameModeBase::RollD8()
{
	FActorSpawnParameters SpawnParams;
	const float pitch = FMath::FRandRange(-180.f, 180.f);
	const float yaw = FMath::FRandRange(-180.f, 180.f);
	const float roll = FMath::FRandRange(-180.f, 180.f);
	ADieActor* die = GetWorld()->SpawnActor<ADieActor>(D8Class, FVector(500, 0, 50), FRotator(pitch, yaw, roll), SpawnParams);
	die->Throw();
	DiceTray.Add(die);

	return die;
}

ADieActor* ADiceRollerGameModeBase::RollD10()
{
	FActorSpawnParameters SpawnParams;
	const float pitch = FMath::FRandRange(-180.f, 180.f);
	const float yaw = FMath::FRandRange(-180.f, 180.f);
	const float roll = FMath::FRandRange(-180.f, 180.f);
	ADieActor* die = GetWorld()->SpawnActor<ADieActor>(D10Class, FVector(500, 0, 50), FRotator(pitch, yaw, roll), SpawnParams);
	die->Throw();
	DiceTray.Add(die);

	return die;
}

ADieActor* ADiceRollerGameModeBase::RollD12()
{
	FActorSpawnParameters SpawnParams;
	const float pitch = FMath::FRandRange(-180.f, 180.f);
	const float yaw = FMath::FRandRange(-180.f, 180.f);
	const float roll = FMath::FRandRange(-180.f, 180.f);
	ADieActor* die = GetWorld()->SpawnActor<ADieActor>(D12Class, FVector(500, 0, 50), FRotator(pitch, yaw, roll), SpawnParams);
	die->Throw();
	DiceTray.Add(die);

	return die;
}

ADieActor* ADiceRollerGameModeBase::RollD20()
{
	FActorSpawnParameters SpawnParams;
	const float pitch = FMath::FRandRange(-180.f, 180.f);
	const float yaw = FMath::FRandRange(-180.f, 180.f);
	const float roll = FMath::FRandRange(-180.f, 180.f);
	ADieActor* die = GetWorld()->SpawnActor<ADieActor>(D20Class, FVector(500, 0, 50), FRotator(pitch, yaw, roll), SpawnParams);
	die->Throw();
	DiceTray.Add(die);

	return die;
}

void ADiceRollerGameModeBase::RerollAll()
{
	for (int i = 0; i < DiceTray.Num(); i++)
	{
		DiceTray[i]->Throw();
	}
}

void ADiceRollerGameModeBase::ClearDiceTray()
{
	while (DiceTray.Num() > 0) 
	{
		ADieActor* die = DiceTray.Pop();
		die->Destroy();
	}
}