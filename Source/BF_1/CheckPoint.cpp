// Fill out your copyright notice in the Description page of Project Settings.

#include "BF_1.h"
#include "CheckPoint.h"


// Sets default values
ACheckPoint::ACheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CoiComp"));
	CollisionComp->BodyInstance.SetCollisionProfileName("checkpoint");
	RootComponent = CollisionComp;
}

// Called when the game starts or when spawned
void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckPoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

