// Fill out your copyright notice in the Description page of Project Settings.


#include "SpwanLevel.h"
#include "BaseLevel.h"
#include "Engine.h"
#include "Components/BoxComponent.h"

// Sets default values
ASpwanLevel::ASpwanLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpwanLevel::BeginPlay()
{
	Super::BeginPlay();
	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);
	
	
}

// Called every frame
void ASpwanLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpwanLevel::SpawnLevel(bool isFirst)
{
	SpawnLocation = FVector(0.0f, 1000.0f, 0.0f);
	SpawnRotation = FRotator(0, 90, 0);

	if (!isFirst) {
		ABaseLevel* LastLevel = LevelList.Last();
		SpawnLocation = LastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}

	Randomlevel = FMath::RandRange(1, 15);
	ABaseLevel* NewLevel = nullptr;

	if (Randomlevel == 1) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level1, SpawnLocation, SpawnRotation, SpawnInfo);

	}
	else if(Randomlevel == 2) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level2, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if(Randomlevel == 3) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level3, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if(Randomlevel == 4) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level4, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if(Randomlevel == 5) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level5, SpawnLocation, SpawnRotation, SpawnInfo);

	}
	else if (Randomlevel == 6) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level6, SpawnLocation, SpawnRotation, SpawnInfo);

	}
	else if (Randomlevel == 7) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level7, SpawnLocation, SpawnRotation, SpawnInfo);

	}
	else if (Randomlevel == 8) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level8, SpawnLocation, SpawnRotation, SpawnInfo);

	}
	else if (Randomlevel == 9) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level9, SpawnLocation, SpawnRotation, SpawnInfo);

	}
	else if (Randomlevel == 10) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level10, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if (Randomlevel == 11) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level11, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if (Randomlevel == 12) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level12, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if (Randomlevel == 13) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level13, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if (Randomlevel == 14) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level14, SpawnLocation, SpawnRotation, SpawnInfo);

	}else if (Randomlevel == 15) {
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level15, SpawnLocation, SpawnRotation, SpawnInfo);

	}

	if (NewLevel) {
		if (NewLevel->GetTrigger()) {
			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ASpwanLevel::OnOverlapBegin);
		}
	}

	LevelList.Add(NewLevel);
	if (LevelList.Num() > 5)
	{
		LevelList.RemoveAt(0);
	}
}

void ASpwanLevel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	SpawnLevel(false);
}

