// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractAble.h"
#include "InteractCube.generated.h"

/**
 * 
 */
UCLASS()
class BF_1_API AInteractCube : public AInteractAble
{
	GENERATED_BODY()
	
public:
	AInteractCube();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


	//called when the player looks at this actor, makes glowing outline (spell silawet)
	virtual void Focused() override;

	//called when the player stops looking at this actor, turns off glowing
	virtual void Unfocused() override;


	virtual void AttachToHand(USceneComponent* Hand) override;

	virtual void DetachFromHand() override; //AInteractAble* MakeHandNull

	virtual void Throw(FVector Direction) override;

	virtual void ZeroVelocity() override;

	virtual void DampenVelocity(float DampenBy) override;

	void PhysicsOn();//remove

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision)
	class UBoxComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAssess = "true"))
	class UStaticMeshComponent* InteractAbleMesh;

	FVector StartLocation;

	float ZLevelRespone;
	
};
