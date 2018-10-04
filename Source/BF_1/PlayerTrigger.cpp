// Fill out your copyright notice in the Description page of Project Settings.

#include "BF_1.h"
#include "PlayerTrigger.h"


// Sets default values
APlayerTrigger::APlayerTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CoiComp"));
	CollisionComp->BodyInstance.SetCollisionProfileName("PlayerTrigger");
	RootComponent = CollisionComp;

	static ConstructorHelpers::FObjectFinder<USoundCue> propellerCue(TEXT("'/Game/Sounds/Button_Click_Cue.Button_Click_Cue'"));
	propellerAudioCue = propellerCue.Object;
	propellerAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PropellerAudioComp"));
	propellerAudioComponent->bAutoActivate = false;
	propellerAudioComponent->SetupAttachment(RootComponent);

	MeshWithAnimations = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshWithAnimations"));
	MeshWithAnimations->SetupAttachment(CollisionComp);
}

// Called when the game starts or when spawned
void APlayerTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	if (propellerAudioCue->IsValidLowLevelFast()) {
		propellerAudioComponent->SetSound(propellerAudioCue);
	}
}

// Called every frame
void APlayerTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerTrigger::CallTrigger()
{
	if (PlaySound) {
		propellerAudioComponent->Play();
	}
}