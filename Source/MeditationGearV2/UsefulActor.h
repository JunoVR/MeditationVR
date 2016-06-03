// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UsefulActor.generated.h"

UCLASS(Blueprintable)
class MEDITATIONGEARV2_API AUsefulActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUsefulActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	void DoSomething()
	{
		GLog->Log("UsefulActor does something...");
	}
};
