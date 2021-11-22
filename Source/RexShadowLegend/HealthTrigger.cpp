// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthTrigger.h"

// Sets default values
AHealthTrigger::AHealthTrigger() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	RootComponent = Collider;
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AHealthTrigger::OnBeginOverlap);
	Collider->OnComponentEndOverlap.AddDynamic(this, &AHealthTrigger::OnEndOverlap);
}

// Called when the game starts or when spawned
void AHealthTrigger::BeginPlay() {
	Super::BeginPlay();
	if (Amount > 0.f) {
		Light->SetLightColor(FLinearColor(0.f, 1.f, 0.f, 1.f));
	}
	else if (Amount == 0.f) {
		Light->SetLightColor(FLinearColor(1.f, 1.f, 1.f, 1.f));
	}
	else {
		Light->SetLightColor(FLinearColor(1.f, 0.f, 0.f, 1.f));
	}
}

// Called every frame
void AHealthTrigger::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	TimerUpdate(DeltaTime);

}

void AHealthTrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	ACharacterController* character = Cast<ACharacterController>(OtherActor);
	if (character) {
		GLog->Log(TEXT("TALUT"));
		CharacterInside = character;
	}
}

void AHealthTrigger::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	GLog->Log(TEXT("GET OUT"));
	CharacterInside = nullptr;
	CurrentTimer = 0.f;
}

void AHealthTrigger::TimerUpdate(float DeltaTime) {
	if (CharacterInside == nullptr) {
		return;
	}
	if (CurrentTimer >= Timer) {
		CharacterInside->Health += Amount;
		CurrentTimer = 0.f;
	}
	else {
		CurrentTimer += DeltaTime;
	}
}