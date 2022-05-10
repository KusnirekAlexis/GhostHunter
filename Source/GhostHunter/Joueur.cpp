// Fill out your copyright notice in the Description page of Project Settings.


#include "Joueur.h"
//#include "GameFramework/Controller.h"

// Sets default values
AJoueur::AJoueur()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJoueur::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJoueur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AJoueur::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AJoueur::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AJoueur::MoveRight);

	PlayerInputComponent->BindAxis("LookRight", this, &AJoueur::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AJoueur::LookUp);

}

void AJoueur::MoveForward(float Axis) {
	if ((Controller != nullptr) && (Axis != 0.0f))
	{
		// get forward vector
		const FVector Direction = GetActorForwardVector();
		AddMovementInput(Direction, Axis);
	}
}

void AJoueur::MoveRight(float Axis)
{
	if ((Controller != nullptr) && (Axis != 0.0f))
	{
		// get right vector 
		const FVector Direction = GetActorRightVector();
		// add movement in that direction
		AddMovementInput(Direction, Axis);
	}
}

void AJoueur::LookRight(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * 45.f * GetWorld()->GetDeltaSeconds());
}

void AJoueur::LookUp(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(-Rate * 45.f * GetWorld()->GetDeltaSeconds());
}

