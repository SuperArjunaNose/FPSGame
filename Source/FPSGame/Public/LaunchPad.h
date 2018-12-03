// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPad.generated.h"

class UBoxComponent;
class UParticleSystem;
class UStaticMeshComponent;

UCLASS()
class FPSGAME_API ALaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = LaunchPad)
	UBoxComponent* LaunchBox;

	UPROPERTY(EditInstanceOnly, Category = LaunchPad)
	float launchPitch = 35.0f;

	UPROPERTY(EditInstanceOnly, Category = LaunchPad)
	float launchMagnitude;

	UPROPERTY(EditDefaultsOnly, Category = FX)
	UParticleSystem* launchParticles;

	UPROPERTY(VisibleAnywhere, Category = LaunchPad)
	UStaticMeshComponent* launchCube;

	UPROPERTY(VisibleAnywhere, Category = LaunchPad)
	UStaticMeshComponent* launchPlane;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};