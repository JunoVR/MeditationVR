// Fill out your copyright notice in the Description page of Project Settings.

#include "MeditationGearV2.h"
#include "ActorSpawner.h"



// Sets default values
AActorSpawner::AActorSpawner()
{


}

void AActorSpawner::BeginPlay()
{	
	UE_LOG(LogTemp, Warning, TEXT("BEGIN PLAY"))
	Super::BeginPlay();
	SetupInputComponent();
	FTimerHandle OutHandle;

	// Will call SpawnUserfulActor after the specified time
	ToggleEmitter();
}

void AActorSpawner::SetupInputComponent()
{
	InputComponent = FindComponentByClass<UInputComponent>();

		if (InputComponent)
		{
			InputComponent->BindAction("ToggleEmitter", IE_Pressed, this, &AActorSpawner::ToggleEmitter);
	    }
	
}



void AActorSpawner::ToggleEmitter()
{	
	if (CurrentActor) {
		GetWorld()->DestroyActor(CurrentActor);
	}
	UE_LOG(LogTemp, Warning, TEXT("TOGGLE EMITTER"))
	TSubclassOf<AUsefulActor> UsefulActorBP = UsefulActorsArray[currentEmitterIndex];
	if (!UsefulActorBP) {
		UE_LOG(LogTemp, Warning, TEXT("NO BP FOUND! RETURNING"));
		return;
	}
	FActorSpawnParameters SpawnParams;
	CurrentActor= GetWorld()->SpawnActor<AUsefulActor>(UsefulActorBP, GetTransform(), SpawnParams);

	currentEmitterIndex++;
	if (currentEmitterIndex == UsefulActorsArray.Num())
	{
		currentEmitterIndex = 0;
	}
	
}
