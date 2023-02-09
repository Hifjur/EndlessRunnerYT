// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpwanLevel.generated.h"


class ABaseLevel;
UCLASS()
class ENDLESSRUNNERYT_API ASpwanLevel : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpwanLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UFUNCTION()
		void SpawnLevel(bool isFirst);
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherbodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);
protected:
	APawn* Player;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level1;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level2;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level3;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level4;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level5;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level6;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level7;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level8;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level9;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level10;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level11;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level12;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level13;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level14;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Level15;

	TArray<ABaseLevel*> LevelList;

public:
	int Randomlevel;

	FVector SpawnLocation = FVector();
	FRotator SpawnRotation = FRotator();
	FActorSpawnParameters SpawnInfo = FActorSpawnParameters();

};
