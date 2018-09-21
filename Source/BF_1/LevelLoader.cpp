// Fill out your copyright notice in the Description page of Project Settings.

#include "BF_1.h"
#include "LevelLoader.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

// Sets default values
ALevelLoader::ALevelLoader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CoiComp"));
	CollisionComp->BodyInstance.SetCollisionProfileName("levelloader");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ALevelLoader::OnOverLapB);
	RootComponent = CollisionComp;

	LoaderMesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("LoaderMesh"));
	//LoaderMesh->AttachTo(RootComponent);
	LoaderMesh->SetupAttachment(RootComponent);

	LevelKey = "CurrentLevel";

	//for the life of me i don't know why i have a Black board in this class
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));


	EditorIcon = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"), true);
	static ConstructorHelpers::FObjectFinder<UTexture2D> SpriteTexture(TEXT("Texture2D'/Game/Textures/Loader.Loader'"));
	EditorIcon->Sprite = SpriteTexture.Object;
	EditorIcon->ScreenSize = 0.0015f;
	//EditorIcon->AttachTo(CollisionComp);
	EditorIcon->SetupAttachment(CollisionComp);

	static ConstructorHelpers::FObjectFinder<UTexture2D> PS(TEXT("Texture2D'/Game/Textures/game-loading2.game-loading2'"));
	ReticleDisplayLoading = PS.Object;

	//AddLevelComplete.Empty();
}

// Called when the game starts or when spawned
void ALevelLoader::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALevelLoader::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	BlackboardComp->InitializeBlackboard(*(GlobalVariableAccess->BlackboardAsset));

}

void ALevelLoader::OnOverLapB(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (OtherActor->IsA(APlayerCharacter::StaticClass())) {
			if (LevelName != "None") {
				BlackboardComp->SetValueAsName(LevelKey, LevelName);
				/*APlayerCharacter* temp = Cast<APlayerCharacter>(OtherActor);
				temp->currentLevel = LevelName;*/

				ACharacter* cc = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
				APlayerCharacter* temp = Cast<APlayerCharacter>(cc);
				temp->TemporaryReticle(ReticleDisplayLoading, 2.0f);
				temp->HUDHeight = 564.0f;
				temp->HUDWidth = 564.0f;

				/*if (AddLevelNumOnLoad) {
					FString FileNameA = "level.txt";
					FString SaveTextA;
					FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));


					float adding = FCString::Atof(*SaveTextA);
					adding += 1.0f;
					FString SaveTextB = FString::SanitizeFloat(adding);
					FString FileNameB = "level.txt";
					FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
				}*/


				if (AddLevelComplete.IsEmpty() == false) {
					FString FileNameA = "level.txt";
					FString SaveTextA;
					FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));

					//SaveTextA + AddLevelComplete + ".1.";
					
					//float adding = FCString::Atof(*SaveTextA);
					//adding += 1.0f;
					FString SaveTextB = SaveTextA + AddLevelComplete + "=1 "; //SaveTextA;//"box .1.";//
					FString FileNameB = "level.txt";
					FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));

					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Level Saved");
				}


				UGameplayStatics::OpenLevel(this, LevelName);
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Level Name can't equal None");
			}
		}
	}
}



/*
Ref

crap

//CollisionComp->OnComponentHit.AddDynamic(this, &ALevelLoader::OnHit);

//Material->BlendMode = BLEND_Translucent;
//Material->Opacity.Constant = 0.5f;
//LoaderMesh->SetMaterial(0 ,Material);

//UGameplayStatics::OpenLevel(this, LevelName);
//FName d = "" + NameToLoad->GetName();

//if(GlobalVariableAccess)
//{
//}
//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "tick");

//OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex, bool, bFromSweep, const FHitResult &, SweepResult
/*void ALevelLoader::OnHit(UPrimitiveComponent* HitComp, AActor* Actor, UPrimitiveComponent* Other, FVector Impulse, const FHitResult & Hit)
{

GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "clition");
//UE_LOG(LogTemp, Warning, TEXT("Your message"));
//UGameplayStatics::OpenLevel(this, LevelName);//"levelLoader");
}*

/*if (OtherActor->IsA(Atest3Projectile::StaticClass())) {
health--;
if (health <= 0) {
Destroy();
}
}*



*/