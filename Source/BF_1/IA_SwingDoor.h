// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractCube.h"
#include "IA_SwingDoor.generated.h"

/**
 * 
 */
UCLASS()
class BF_1_API AIA_SwingDoor : public AInteractCube
{
	GENERATED_BODY()

	class UTimelineComponent* RotateTimeline;

public:
	AIA_SwingDoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InteractWithPlayer() override;

	virtual void InteractWithItem(AInteractAble* Item) override;

	void StopParticle();
	
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timeline)
	class UCurveVector* VCurve;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timeline)
	class UCurveFloat* FCurve;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision)
	class USceneComponent* DoorPivot;

	UPROPERTY()	
	FRotator StartRotation;

	UPROPERTY()
	FRotator EndRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timeline)
	float ZOffSet;

	UPROPERTY(EditAnywhere, Category = ID)
	UTexture2D* ReticleDisplayLocked;

	UPROPERTY(EditAnywhere, Category = ID)
	bool Locked;

	UPROPERTY(EditAnywhere, Category = ID)
	bool DeleteUnlockItem;

	/*UPROPERTY(EditAnywhere, Category = Collision)
	UTexture2D* SpriteTexture;*/

	/*UPROPERTY()
	class UParticleSystemComponent* DeleteItemParticle;*/

	/*temporary holds Particle System so it can be set MovingToLocationMaker in BeginPlay*/
	UParticleSystem* TempPS;

	//FOnTimelineVector InterpFunction{};

	FOnTimelineFloat InterpFunction{};

	FOnTimelineEvent TimelineFinished{};

	UFUNCTION()
	void TimelineVectorReturn(float value);

	UFUNCTION()
	void OnTimelineFinished();/**/
	

};
