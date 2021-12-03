// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h" 
#include "Projectile.h"


void ACharacterController::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACharacterController::Launch);
}

void ACharacterController::ChangeHealth(float amount, bool setTo) {
	if (setTo) {
		CurrentHealth = amount;
	}
	else
	{
		CurrentHealth += amount;
	}
	if (CurrentHealth <= 0) {
		Die();
	}
}

void ACharacterController::Die() {
	//DisableInput(GetWorld()->GetFirstPlayerController());
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FTimerHandle Timer = FTimerHandle();
	SetActorHiddenInGame(true);
	GetWorldTimerManager().SetTimer(Timer, this, &ACharacterController::Respawn, ReviveTime, false);

}

void ACharacterController::Respawn() {
	CurrentHealth = Health;
	SetActorLocation(SpawnPoint->GetActorLocation());
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
	SetActorHiddenInGame(false);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void ACharacterController::Launch() {
	UClass* Projectile = AProjectile::StaticClass();
	AActor* ProjectileLaunched = GetWorld()->SpawnActor<AProjectile>(GetActorLocation() + GetActorForwardVector() * DistProjectile, GetActorRotation());

}

void ACharacterController::SaveGame(FString name) {
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance->PlayerPosition = this->GetActorLocation();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My Location is: %s"), *SaveGameInstance->PlayerPosition.ToString()));
	SaveGameInstance->PlayerHealth = this->CurrentHealth;

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, name, 0);
}

void ACharacterController::LoadGame(FString name) {
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(name, 0));
	if (SaveGameInstance) {
		SetActorLocation(SaveGameInstance->PlayerPosition);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My Location is: %s"), *SaveGameInstance->PlayerPosition.ToString()));
		ChangeHealth(SaveGameInstance->PlayerHealth, true);
	}
}