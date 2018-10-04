// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlayerTrigger.generated.h"

UCLASS()
class BF_1_API APlayerTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CallTrigger();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
	class UBoxComponent* CollisionComp;

	UPROPERTY(EditAnywhere, Category = Collision)
	bool PlaySound;

	UPROPERTY(EditAnywhere, Category = Collision)
	bool PlayAnimation;

	UPROPERTY(EditAnywhere, Category = Collision)
	bool PlayParticles;

	UPROPERTY(VisibleAnywhere, Category = Collision)
	bool ToggleBoolForAnimations;

	USoundCue* propellerAudioCue;

	UPROPERTY(EditAnywhere, Category = Audio)
	UAudioComponent* propellerAudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAssess = "true"))
	class UStaticMeshComponent* MeshWithAnimations;
	
};
