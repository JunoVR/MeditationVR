// Fill out your copyrights notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UsefulActor.h"
#include "ActorSpawner.generated.h"


UCLASS(Blueprintable)
class MEDITATIONGEARV2_API AActorSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category = "ActorSpawning")
		TSubclassOf<AUsefulActor> UsefulActorBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorSpawning")
		TArray <TSubclassOf<AUsefulActor>> UsefulActorsArray;

	/*Delay after the Blueprint of the UsefulActor will get spawned*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorSpawning")
		float TimeToSpawn = 2.f;


private:
	UInputComponent* InputComponent = nullptr;
	
	int currentEmitterIndex = 0;

	// Setup (assumed) attached input component
	void SetupInputComponent();

	void ToggleEmitter();

	AUsefulActor* CurrentActor;


};
