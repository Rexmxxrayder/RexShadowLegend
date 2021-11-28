// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/EngineTypes.h"
#include "WallPainting.h"
#include "Math/Vector.h"

// Sets default values
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	Mesh->SetStaticMesh(MeshRef.Object);
	SetActorScale3D(FVector(0.1f, 0.1f, 0.1f));
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	Projectile->InitialSpeed = 3000.f;
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/ThirdPersonCPP/MaterialS/d.d'"));
	Material = MaterialAsset.Object;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	FHitResult HitResult;
	Super::Tick(DeltaTime);
	if (HitResult.GetActor())
	{
		FRotator rotate;
		ADecalActor* Decal = GetWorld()->SpawnActor<AWallPainting>(HitResult.ImpactPoint, rotate);
		Decal->SetDecalMaterial(Material);
		Destroy();
	}
}

