// Fill out your copyright notice in the Description page of Project Settings.


#include "JumPad.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"

// Sets default values
AJumPad::AJumPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Mesh->SetNotifyRigidBodyCollision(true);

	Mesh->OnComponentHit.AddDynamic(this, &AJumPad::OnHit);
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AJumPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJumPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJumPad::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	ACharacter* character = Cast<ACharacter>(OtherActor);
	if (!character) { return; }

	character->LaunchCharacter(FVector(0.f, 0.f, 1.f) * Force, false, true);
}